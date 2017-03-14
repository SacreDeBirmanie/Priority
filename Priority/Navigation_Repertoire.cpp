#include "Navigation_Repertoire.hpp"

#include <QDir>
#include <QFile>
#include <QTextStream>

Navigation_Repertoire::Navigation_Repertoire(){
    ;
}

bool Navigation_Repertoire::existe_dossier(QString chemin){
    QDir repertoire = QDir(chemin);
    return repertoire.exists();
}

bool Navigation_Repertoire::existe_fichier(QString chemin){
    return QFile::exists(chemin);
}

QStringList Navigation_Repertoire::listeDesFichiers(QString chemin, QStringList filtre_extension){
    QStringList liste;
    QDir repertoire(chemin);

    repertoire.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    repertoire.setSorting(QDir::Size | QDir::Reversed);
    repertoire.setNameFilters(filtre_extension);

    QFileInfoList listefichiers = repertoire.entryInfoList();
    for (int i = 0; i < listefichiers.size(); ++i) {
       QFileInfo fichInfo = listefichiers.at(i);
       liste.append(fichInfo.fileName());
    }
    return liste;

}

bool Navigation_Repertoire::creerDossier(QString chemin, QString nom){
    QDir repertoire = QDir(chemin);
    return repertoire.mkdir(nom);


}

void Navigation_Repertoire::creerFichier(QString chemin, QString nom){
    QFile fichier(chemin+nom);
    fichier.open(QIODevice::ReadWrite);
    fichier.close();
}

void Navigation_Repertoire::supprimerFichier(QString chemin, QString nom){
    QDir repertoire = QDir(chemin);
    repertoire.remove(nom);
}

void Navigation_Repertoire::ecrire(QString chemin, QString nom, QString contenu){
    QFile fichier(chemin + nom);
    if(!fichier.open(QIODevice::WriteOnly))
    {
        fichier.close();
        return;
    }

    QTextStream flux(&fichier);
    flux << contenu;

    fichier.close();
}

