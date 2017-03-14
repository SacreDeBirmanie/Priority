#ifndef GESTIONNAIRE_DES_TAGS
#define GESTIONNAIRE_DES_TAGS
#include <QList>
#include "Tag.hpp"

class GestionnaireDesTags{
    private :
        QList<Tag*> lestags;
        void ajouterTagByString(QString nom);
        void supprimerTagListe(Tag* tag);

    public :
        GestionnaireDesTags();
        void recupererLesFichiers(Tag* tag);
        void recupererLesTags();
        void creerUnNouveauTag(QString nom);
        void supprimerTag(Tag *tag);
        void tagger(Tag* tag, QString nom_fichier);
};



#endif // GESTIONNAIRE_DES_TAGS


