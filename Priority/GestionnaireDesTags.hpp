#ifndef GESTIONNAIRE_DES_TAGS
#define GESTIONNAIRE_DES_TAGS
#include <QList>
#include "Tag.hpp"

class GestionnaireDesTags{
    private :
        QList<Tag*> lestags;
        void tagerUnFichier(QString fich);
        void ajouterTagByString(QString nom);
        void supprimerTag(Tag* tag);

    public :
        GestionnaireDesTags();
        void recupererLesFichiers(Tag* tag);
        void recupererLesTags();
        void creerUnNouveauTag(QString nom);
        void supprimerUnTag(Tag *tag);
};



#endif // GESTIONNAIRE_DES_TAGS


