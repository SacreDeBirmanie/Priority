
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QFileSystemModel>
#include <QDateTime>
#include <QDesktopServices>
#include <QUrl>
#include <QPushButton>
#include <GestionnaireDesTags.hpp>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QFileSystemModel *fsm = new QFileSystemModel(&engine);
    fsm->setRootPath(QDir::homePath());
    fsm->setResolveSymlinks(true);
    engine.rootContext()->setContextProperty("fileSystemModel", fsm);
    engine.rootContext()->setContextProperty("rootPathIndex", fsm->index(fsm->rootPath()));
    engine.load(QUrl(QStringLiteral("qrc:///essaiApp.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QPushButton* button = new QPushButton("essai");
    GestionnaireDesTags tagger;
    QObject::connect(button, SIGNAL(triggered()), &tagger, SLOT(creerUnNouveauTag()));

    //QObject::connect(button1, SIGNAL(clicked()), &tagger, SLOT(creerUnNouveauTag(QString)));
    tagger->recupererLesTags();
    tagger->creerUnNouveauTag("Serie");
    tagger->tagger("Serie", "haha");
    tagger->tagger("Serie", "haha");
    tagger->tagger("Serie", "lulu");
    tagger->detagger("Serie", "lulu");

    tagger->creerUnNouveauTag("lol");
    tagger->tagger("lol", "test");
    tagger->supprimerTag("lol");
    return app.exec();
}
