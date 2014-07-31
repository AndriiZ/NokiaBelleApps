#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeContext>
#include "qmlapplicationviewer.h"
#include "src/ProviderModel.h"
#include "src/qgoogleauth.h"

#if defined(Q_OS_SYMBIAN) || defined(Q_WS_SIMULATOR)
#include <QtGui/QSplashScreen>
#include <QtGui/QPixmap>
#endif

#include "src/networkmonitor.h"
#include "src/qmlutils.h"

#ifdef Q_OS_SYMBIAN
#include <QSymbianEvent>
#include <w32std.h>
#include <avkon.hrh>

class SymbianApplication : public QApplication
{
public:
    SymbianApplication(int &argc, char** argv) : QApplication(argc, argv){}

protected:
    bool symbianEventFilter(const QSymbianEvent *event)
    {
        if (event->type() == QSymbianEvent::WindowServerEvent
                && event->windowServerEvent()->Type() == KAknUidValueEndKeyCloseEvent){
            return true;
        }
        return QApplication::symbianEventFilter(event);
    }
};

#endif // Q_OS_SYMBIAN


Q_DECL_EXPORT int main(int argc, char *argv[])
{
#ifdef Q_OS_SYMBIAN
    QScopedPointer<QApplication> app(new SymbianApplication(argc, argv));
#else
    QScopedPointer<QApplication> app(createApplication(argc, argv));
#endif

#if defined(Q_OS_SYMBIAN) || defined(Q_WS_SIMULATOR)
    QSplashScreen *splash = new QSplashScreen(QPixmap(":/splash/gauth-splash-symbian.jpg"), Qt::WindowStaysOnTopHint);
    splash->show();
    splash->showMessage(QSplashScreen::tr("Loading..."), Qt::AlignHCenter | Qt::AlignBottom, Qt::white);
#endif

    QmlApplicationViewer viewer;

    QMLUtils qmlUtils(&viewer);
    viewer.rootContext()->setContextProperty("QMLUtils", &qmlUtils);
    //NetworkMonitor networkMonitor;
    //viewer.rootContext()->setContextProperty("networkMonitor", &networkMonitor);
    //view.rootContext()->setContextProperty("APP_VERSION", APP_VERSION);

    qmlRegisterType<ProviderSqlQueryModel>("ProviderModel", 1,0, "ProviderModel");
    qmlRegisterType<QGoogleAuth>("QGoogleAuth", 1,0, "QGoogleAuth");

    viewer.setMainQmlFile(QLatin1String("qml/GAuth/main.qml"));
    viewer.showExpanded();

#if defined(Q_OS_SYMBIAN) || defined(Q_WS_SIMULATOR)
    splash->finish(&viewer);
    splash->deleteLater();
#endif

    return app->exec();
}
