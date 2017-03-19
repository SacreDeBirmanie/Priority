#ifndef GESTIONNAIRE_DES_TAGS
#define GESTIONNAIRE_DES_TAGS
#include <QHash>
#include <QObject>
#include <QStringList>

#include "Tag.hpp"

class GestionnaireDesTags{
    private :
        QHash<QString, Tag*> lestags;


        void ajouterTagByString(QString nom_tag);
        void supprimerTagListe(QString nom_tag);


    public :
        GestionnaireDesTags();
        void recupererLesTags();
        void creerUnNouveauTag(QString nom);
        void supprimerTag(QString nom_tag);
        void tagger(QString nom_tag, QString nom_fichier);
        void detagger(QString nom_tag, QString nom_fichier);
        QStringList listeDesNomTags();
        int compterFichiers(QString nom_tag);
        Tag* getTag(QString nom);
        QStringList recupererLesFichiers(Tag* tag);

};



#endif // GESTIONNAIRE_DES_TAGS


