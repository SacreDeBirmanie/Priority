#ifndef GESTIONNAIREDESTAGS
#define GESTIONNAIREDESTAGS
#include <QList>
#include "Tag.hpp"

class gestionnaireDesTags{
    private :
        QList<Tag*> lestags;
        void ecrireDansLeFichier();
        void ajouterTagByString(QString nom);
        void supprimerTag(Tag* tag);
    public :
        gestionnaireDesTags();
        void récupérerLesTags();
        void créerUnNouveauTag(QString nom);
        void supprimerUnTag(Tag* tag);


};



#endif // GESTIONNAIREDESTAGS


