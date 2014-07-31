#ifndef QGOOGLEAUTH_H
#define QGOOGLEAUTH_H

#include <QtCore/QObject>
#include <QtDeclarative/QDeclarativeListProperty>
#include <QString>


class QGoogleAuth : public QObject {
    Q_OBJECT

public:
    explicit QGoogleAuth(QObject *parent = 0);
    ~QGoogleAuth();
    Q_INVOKABLE QString generatePin(const QByteArray key);
private:

signals:

public slots:
};

#endif // QGOOGLEAUTH_H
