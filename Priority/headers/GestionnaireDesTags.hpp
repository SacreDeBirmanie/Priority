#ifndef GESTIONNAIRE_DES_TAGS
#define GESTIONNAIRE_DES_TAGS
#include <QHash>
#include <QObject>
#include <QStringList>

#include "headers/Tag.hpp"

/**
 * @brief The GestionnaireDesTags Gestionnaire des tags
 */
class GestionnaireDesTags{
    private :
        QHash<QString, Tag*> lestags;


        void ajouterTagByString(QString nom_tag);
        void supprimerTagListe(QString nom_tag);


    public :
        GestionnaireDesTags();
        void recupererLesTags();
        bool creerUnNouveauTag(QString nom);
        void supprimerTag(QString nom_tag);
        void tagger(QString nom_tag, QString nom_fichier);
        void tagger(QString nom_tag, QStringList noms_fichiers);
        void detagger(QString nom_tag, QString nom_fichier);
        void detagger(QString nom_tag, QStringList fichiers);
        QStringList listeDesNomTags();
        QStringList listeDesNomTags(QString nom_fichier);
        int compterFichiers(QString nom_tag);
        Tag* getTag(QString nom);
        QStringList recupererLesFichiers(Tag* tag);

};



#endif // GESTIONNAIRE_DES_TAGS


