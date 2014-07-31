#ifndef PROVIDERMODEL_H
#define PROVIDERMODEL_H

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

class ProviderSqlQueryModel : public QSqlQueryModel
{
  Q_OBJECT

  QHash<int, QByteArray> roles;
  void generateRoleNames();
  QString CreateDbFolder();
public:
  explicit ProviderSqlQueryModel(QObject *parent = 0);

  Q_INVOKABLE void setQuery(const QString &query, const QSqlDatabase &db = QSqlDatabase());
  Q_INVOKABLE void setQuery(const QSqlQuery &query);
  Q_INVOKABLE QVariant data(const QModelIndex &index, int role) const;
  Q_INVOKABLE void refresh();
  Q_INVOKABLE QVariant datasingle(const QString &role) const;

  Q_INVOKABLE bool openDB();
  Q_INVOKABLE void initDB();
  Q_INVOKABLE void closeDB();
  Q_INVOKABLE bool insertProvider(const QString &title, const QString &secret);
  Q_INVOKABLE bool updateProvider(const QString &title, const QString &secret, const int &providerid);
  Q_INVOKABLE bool deleteProvider(const int &providerid);


  QSqlDatabase mydb;

private:

signals:

public slots:

};


#endif // PROVIDERMODEL_H
