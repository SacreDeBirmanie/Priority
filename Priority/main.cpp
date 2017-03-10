#include "qtquick1applicationviewer.h"
#include <QApplication>
#include <QtXml/>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QtQuick1ApplicationViewer viewer;
    viewer.addImportPath(QLatin1String("modules"));
    viewer.setOrientation(QtQuick1ApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/Priority/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
