
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QFileSystemModel>
#include <QDateTime>
#include <QDesktopServices>
#include <QUrl>
#include <QPushButton>
#include <QWidget>
#include <QMainWindow>
#include <iostream>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include "headers/FenetrePrincipale.hpp"




int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);

    QTranslator translator;

    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));

    app.installTranslator(&translator);

    FenetrePrincipale fenetre;

    return app.exec();
}
