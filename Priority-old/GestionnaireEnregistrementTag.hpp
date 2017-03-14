#ifndef GESTIONNAIRE_ENREGISTREMENT_TAG

#define GESTIONNAIRE_ENREGISTREMENT_TAG


#include <QtGui>

#include <QString>
#include <QtXml>



class GestionnaireEnregistrementTag

{
    private:
        QDomDocument *dom;
    public:
        static const QString CHEMIN_DOSSIER_TAGS;
        static const QString EXTENSION;

        GestionnaireEnregistrementTag(QString nom_fichier_tag);
        QStringList recupererFichiers();
        void tagger(QString nom_fich);
        ~GestionnaireEnregistrementTag();

        static QStringList listeDesTags();
        static bool existe(QString nom);
        static void creerTag(QString nom);
        static void supprimerTag(QString nom);
};


#endif // GESTIONNAIRE_ENREGISTREMENT_TAG

