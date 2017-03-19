
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
#include "FenetreRechercheAffichageTag.hpp"





int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget vueApp;
    GestionnaireDesTags *tagger = new GestionnaireDesTags();

    QHBoxLayout *mainLayout = new QHBoxLayout();
    tagger->recupererLesTags();
    //Use to debug
    //tagger->tagger("bob","Documents/URI.java");
    vueApp.setLayout(mainLayout);
    FenetreRechercheAffichageTag *vueRecherche = new FenetreRechercheAffichageTag(tagger,&vueApp, mainLayout);
    FenetreManagerDeTag* fenetreTag = new FenetreManagerDeTag(tagger,&vueApp,mainLayout);

    vueApp.showMaximized();
    return app.exec();
}
