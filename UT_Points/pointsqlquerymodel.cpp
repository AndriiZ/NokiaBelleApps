#include "pointsqlquerymodel.h"
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/QDeclarativeComponent>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlDriver>
#include <QModelIndex>
#include <QVariant>
#include <QObject>
#include <QString>
#include <QDir>
#include <QDebug>
#include "src/sqlite3.h"
#include <math.h>

//--------------------------------
// SQL QUERY MODEL
//--------------------------------

PointSqlQueryModel::PointSqlQueryModel(QObject *parent) :
  QSqlQueryModel(parent)
{

}

QString PointSqlQueryModel::CreateDbFolder()
{
    QDir dir;
    QString newPath = "E:";
    newPath += QDir::separator();
    newPath += "Databases";
    newPath = (QDir::toNativeSeparators(newPath));

    if(!dir.exists(newPath)) {
        dir.mkpath(newPath);
    }
    return newPath;
}

// Open DB before doing anything, set the path to custom path E:\Databases\providers.sqlite
bool PointSqlQueryModel::openDB()
{
  mydb = QSqlDatabase::addDatabase("QSQLITE");
  // Adjust for Windows, OSX or Symbian deploy
  mydb.setDatabaseName(CreateDbFolder() + "\\ut_wifi.sl3");
  bool open = mydb.open();
  #if defined(Q_OS_SYMBIAN)
    sqlite3_config( SQLITE_CONFIG_SINGLETHREAD );
    installCustomFunctions();
  #endif
  return open;
}

// Init DB, create missing tables if necessary
void PointSqlQueryModel::initDB()
{
  if (mydb.isOpen()) {
    QSqlQuery query1;

  }
}


// Close DB to end app
void PointSqlQueryModel::closeDB()
{
  mydb.close();
}

// Set query and run
void PointSqlQueryModel::setQuery(const QString &query, const QSqlDatabase &db)
{
  QSqlQueryModel::setQuery(query,db);
  generateRoleNames();
}

// Set query and run
void PointSqlQueryModel::setQuery(const QSqlQuery &query)
{
  QSqlQueryModel::setQuery(query);
  generateRoleNames();
}

// Assign role names to model's rolenames hash so it can be accessed by fields instead of numbers
void PointSqlQueryModel::generateRoleNames()
{
  roles.clear();
  int nbCols = this->columnCount();
  for (int i = 0; i < nbCols; i++) {
      roles[Qt::UserRole + i + 1] = QVariant(this->headerData(i, Qt::Horizontal).toString()).toByteArray();
  }
  setRoleNames(roles);
}

// Retrieve multi-row data from model
QVariant PointSqlQueryModel::data(const QModelIndex &index, int role) const
{
  QVariant value = QSqlQueryModel::data(index, role);
  if(role < Qt::UserRole)
  {
    value = QSqlQueryModel::data(index, role);
  }
  else
  {
    int columnIdx = role - Qt::UserRole - 1;
    QModelIndex modelIndex = this->index(index.row(), columnIdx);
    value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
  }
  return value;
}

// Retrieve data for single row only
// Nasty hack, assumes only one row returned by query!
QVariant PointSqlQueryModel::datasingle(const QString &fieldName) const
{
  return QSqlQueryModel::record(0).value(fieldName);
}


void PointSqlQueryModel::refresh(double lat, double lng, double maxDistance)
{
    QSqlQuery query(mydb);
    if (maxDistance <= 0)
        maxDistance = 6371.0;
    #if defined(Q_OS_SYMBIAN)
    query.prepare("SELECT p.CityId, c.CityName, p.PointId, p.latitude, p.longtitude, p.address, p.name, p.type, p.sellplaceworktime, distance(p.latitude, p.longtitude, :lat, :lng) AS distance from Point p inner join city c on p.cityId = c.CityId where distance < :dsc order by distance");
    query.bindValue(":lat", lat);
    query.bindValue(":lng", lng);
    query.bindValue(":dsc",  maxDistance);
    #else
    query.prepare("SELECT c.CityName, p.*, 0 as distance from Point p inner join city c on p.cityId = c.CityId where latitude between :lat1 and :lat2 and longtitude between :lng1 and :lng2");
    query.bindValue(":lat1", lat - 0.25);
    query.bindValue(":lat2", lat + 0.25);
    query.bindValue(":lng1", lng - 0.25);
    query.bindValue(":lng2", lng + 0.25);
    #endif
    query.exec();
    this->setQuery(query);
    //delete query;
}

void PointSqlQueryModel::refreshSearch(const QString &city)
{
    QSqlQuery query(mydb);
    query.prepare("SELECT p.CityId, c.CityName, p.PointId, p.latitude, p.longtitude, p.address, p.name, p.type, p.sellplaceworktime, 0 AS distance from Point p inner join city c on p.cityId = c.CityId where c.CityName Like :city");
    query.bindValue(":city", city + "%");
    query.exec();
    this->setQuery(query);
}

double radians(double degrees)
{
    return degrees * M_PI / 180.0;
}

double _distance(double lat, double lng, double lat2, double lng2)
{
    double _lat  = radians(lat);
    double _lng  = radians(lng);
    double _lat2 = radians(lat2);
    double _lng2 = radians(lng2);
    return 6371.0 * acos(cos(_lat2) * cos(_lat) * cos(_lng - _lng2) + sin(_lat2) * sin(_lat));
}

double PointSqlQueryModel::distance(double lat, double lng, double lat2, double lng2)
{
    qDebug()<<lat<<" "<<lng<<" "<<lat2<<" "<<lng2<<" dst "<<_distance(lat, lng, lat2, lng2);
    return _distance(lat, lng, lat2, lng2);
}


void sqlite_distance(sqlite3_context *context, int argc, sqlite3_value **argv)
{
    double values[4];

    // get the double values for the four arguments

    for (int i = 0; i < 4; i++) {
        int dataType = sqlite3_value_numeric_type(argv[i]);

        if (dataType == SQLITE_INTEGER || dataType == SQLITE_FLOAT) {
            values[i] = sqlite3_value_double(argv[i]);
        } else {
            sqlite3_result_null(context);
            return;
        }
    }

    // calculate the distance

    double result = _distance(values[0], values[1], values[2], values[3]);

    sqlite3_result_double(context, result);
}

bool PointSqlQueryModel::installCustomFunctions()
{
    // Get handle to the driver and check it is both valid and refers to SQLite3.
    QVariant v = mydb.driver()->handle();
    if (!v.isValid() || qstrcmp(v.typeName(), "sqlite3*") != 0) {
        return false;
    }

    // Create a handler and attach functions.
    sqlite3* handler = *static_cast<sqlite3**>(v.data());
    if (!handler) {
        return false;
    }

    // Check validity of the state.
    if (!mydb.isValid()) {
        return false;
    }

    if (!mydb.isOpen()) {
        return false;
    }

    if (sqlite3_create_function(handler, "distance", 4, SQLITE_ANY, 0, &sqlite_distance, 0, 0))
        return true;
}

