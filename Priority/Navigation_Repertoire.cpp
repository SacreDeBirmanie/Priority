#include "Navigation_Repertoire.hpp"

#include <QDir>
#include <QFile>

Navigation_Repertoire::Navigation_Repertoire(){
    ;
}

static bool Navigation_Repertoire::exist_dossier(QString chemin){
    return QDir::exists(chemin);
}

static bool Navigation_Repertoire::exist_fichier(QString chemin){
    return QFile::exists(chemin);
}

static QStringList Navigation_Repertoire::listeDesFichiers(QString chemin){
    QStringList liste = new QStringList();
    QDir repertoire(chemin);

    repertoire.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    repertoire.setSorting(QDir::Size | QDir::Reversed);

    QFileInfoList listefichiers = repertoire.entryInfoList();
    for (int i = 0; i < listefichiers.size(); ++i) {
       QFileInfo fichInfo = listefichiers.at(i);
       liste.append(fichInfo.fileName());
    }
    return liste;

}

static bool Navigation_Repertoire::creerDossier(QString chemin, QString nom){
    QDir repertoire = QDir(chemin);

    repertoire.mkdir(nom);


}

static bool Navigation_Repertoire::creerFichier(QString chemin, QString nom){
    QFile fichier(chemin+nom);

