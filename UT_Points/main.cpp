#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "PointSqlQueryModel.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    qmlRegisterType<PointSqlQueryModel>("PointSqlQueryModel", 1,0, "PointSqlQueryModel");

    QmlApplicationViewer viewer;
    viewer.setMainQmlFile(QLatin1String("qml/UT_Points/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
