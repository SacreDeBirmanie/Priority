#ifndef NAVIGATION_REPERTOIRE
#define NAVIGATION_REPERTOIRE
#include <QDir>

class Navigation_Repertoire{
    public:
    Navigation_Repertoire();
    static bool exist_dossier(QString chemin);
    static bool exist_fichier(QString chemin);
    static QStringList listeDesFichiers(QString chemin);
    static bool creerDossier(QString chemin, QString nom);
    static bool creerFichier(QString chemin, QString nom);

};


#endif // NAVIGATION_REPERTOIRE

