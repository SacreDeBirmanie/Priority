#ifndef GESTIONNAIRE_DES_TAGS
#define GESTIONNAIRE_DES_TAGS
#include <QHash>
#include "Tag.hpp"

class GestionnaireDesTags{
    private :
        QHash<QString, Tag*> lestags;

        void recupererLesFichiers(Tag* tag);
        void ajouterTagByString(QString nom_tag);
        void supprimerTagListe(QString nom_tag);
        Tag* getTag(QString nom);

    public slots:
        GestionnaireDesTags();
        void recupererLesTags();
        void creerUnNouveauTag(QString nom);
        void supprimerTag(QString nom_tag);
        void tagger(QString nom_tag, QString nom_fichier);
        void detagger(QString nom_tag, QString nom_fichier);
};



#endif // GESTIONNAIRE_DES_TAGS


