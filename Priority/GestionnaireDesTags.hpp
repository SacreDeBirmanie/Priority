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

    public :
        GestionnaireDesTags();
        void recupererLesTags();
        void creerUnNouveauTag(QString nom);
        void supprimerTag(QString nom_tag);
        void tagger(QString nom_tag, QString nom_fichier);
        Tag* getTag(QString nom);
};



#endif // GESTIONNAIRE_DES_TAGS


