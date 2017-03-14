#ifndef NAVIGATION_REPERTOIRE
#define NAVIGATION_REPERTOIRE
#include <QDir>

class Navigation_Repertoire{
    public:
    Navigation_Repertoire();
    static bool existe_dossier(QString chemin);
    static bool existe_fichier(QString chemin);
    static QStringList listeDesFichiers(QString chemin, QStringList filtre_extension, bool extension);
    static bool creerDossier(QString chemin, QString nom);
    static void creerFichier(QString chemin, QString nom);
    static void supprimerFichier(QString chemin, QString nom);
    static void ecrire(QString chemin, QString contenu);

};


#endif // NAVIGATION_REPERTOIRE

