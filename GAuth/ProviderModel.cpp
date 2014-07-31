
#include "src/ProviderModel.h"
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/QDeclarativeComponent>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QModelIndex>
#include <QVariant>
#include <QObject>
#include <QString>
#include <QDir>
#include <QDebug>

//--------------------------------
// SQL QUERY MODEL
//--------------------------------

ProviderSqlQueryModel::ProviderSqlQueryModel(QObject *parent) :
  QSqlQueryModel(parent)
{

}

QString ProviderSqlQueryModel::CreateDbFolder()
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
bool ProviderSqlQueryModel::openDB()
{
  mydb = QSqlDatabase::addDatabase("QSQLITE");
  // Adjust for Windows, OSX or Symbian deploy
  mydb.setDatabaseName(CreateDbFolder() + "\\providers.sqlite");
  return mydb.open();
}

// Init DB, create missing tables if necessary
void ProviderSqlQueryModel::initDB()
{
  if (mydb.isOpen()) {
    QSqlQuery query1;
    query1.exec("CREATE TABLE IF NOT EXISTS providers "
             "(id INTEGER PRIMARY KEY AUTOINCREMENT, "
             "provider TEXT NOT NULL, "
             "secret TEXT NOT NULL)");

    query1.exec("CREATE TABLE IF NOT EXISTS Settings(setting TEXT UNIQUE, value TEXT)");
  }
}


// Close DB to end app
void ProviderSqlQueryModel::closeDB()
{
  mydb.close();
}

// Set query and run
void ProviderSqlQueryModel::setQuery(const QString &query, const QSqlDatabase &db)
{
  QSqlQueryModel::setQuery(query,db);
  generateRoleNames();
}

// Set query and run
void ProviderSqlQueryModel::setQuery(const QSqlQuery &query)
{
  QSqlQueryModel::setQuery(query);
  generateRoleNames();
}

// Assign role names to model's rolenames hash so it can be accessed by fields instead of numbers
void ProviderSqlQueryModel::generateRoleNames()
{
  roles.clear();
  int nbCols = this->columnCount();
  for (int i = 0; i < nbCols; i++) {
      roles[Qt::UserRole + i + 1] = QVariant(this->headerData(i, Qt::Horizontal).toString()).toByteArray();
  }
  setRoleNames(roles);
}

// Retrieve multi-row data from model
QVariant ProviderSqlQueryModel::data(const QModelIndex &index, int role) const
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
QVariant ProviderSqlQueryModel::datasingle(const QString &fieldName) const
{
  return QSqlQueryModel::record(0).value(fieldName);
}

bool ProviderSqlQueryModel::insertProvider(const QString &title, const QString &secret)
{
  bool ret = false;
  QSqlQuery query;
  ret = query.prepare("INSERT INTO providers (provider, secret)"
            "VALUES(?,?)");
  if (ret) {
    query.addBindValue(title);
    query.addBindValue(secret);
    ret = query.exec();
  }
  return ret;
}

bool ProviderSqlQueryModel::updateProvider(const QString &title, const QString &secret, const int &providerid)
{
  bool ret = false;
  QSqlQuery query;
  ret = query.prepare("UPDATE providers SET provider = ?, secret = ? WHERE id = ?");
  if (ret) {
    query.addBindValue(title);
    query.addBindValue(secret);
    query.addBindValue(providerid);
    ret = query.exec();
  }
  return ret;
}

bool ProviderSqlQueryModel::deleteProvider(const int &providerid)
{
  bool ret = false;
  QSqlQuery query;
  ret = query.prepare("DELETE FROM providers WHERE id = ?");
  if (ret) {
    query.addBindValue(providerid);
    ret = query.exec();
  }
  return ret;
}

void ProviderSqlQueryModel::refresh()
{
   this->setQuery("SELECT id, provider, secret FROM providers");
}

