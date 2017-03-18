
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QFileSystemModel>
#include <QDateTime>
#include <QDesktopServices>
#include <QUrl>
#include <QPushButton>
#include <QWidget>
#include <iostream>

#include "GestionnaireDesTags.hpp"
#include "FenetreManagerDeTag.hpp"





int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QSplitter vueApp;
    GestionnaireDesTags *tagger = new GestionnaireDesTags();
    tagger->recupererLesTags();

    FenetreManagerDeTag* fenetreTag = new FenetreManagerDeTag(tagger,&vueApp);
    vueApp.showMaximized();
    return app.exec();
}
