#ifndef POINTSQLQUERYMODEL_H
#define POINTSQLQUERYMODEL_H

#include <QObject>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/QDeclarativeComponent>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlRecord>
#include <QVariant>
#include <QModelIndex>

class PointSqlQueryModel : public QSqlQueryModel
{
  Q_OBJECT

  QHash<int, QByteArray> roles;
  void generateRoleNames();
  QString CreateDbFolder();
  bool installCustomFunctions();
public:
  explicit PointSqlQueryModel(QObject *parent = 0);

  Q_INVOKABLE void setQuery(const QString &query, const QSqlDatabase &db = QSqlDatabase());
  Q_INVOKABLE void setQuery(const QSqlQuery &query);
  Q_INVOKABLE QVariant data(const QModelIndex &index, int role) const;
  Q_INVOKABLE void refresh(double lat, double lng, double maxDistance);
  Q_INVOKABLE void refreshSearch(const QString &city);
  Q_INVOKABLE QVariant datasingle(const QString &role) const;

  Q_INVOKABLE bool openDB();
  Q_INVOKABLE void initDB();
  Q_INVOKABLE void closeDB();

  Q_INVOKABLE double distance(double lat, double lng, double lat2, double lng2);

  QSqlDatabase mydb;

private:

signals:

public slots:

};

#endif // POINTSQLQUERYMODEL_H
