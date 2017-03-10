#include "GestionnaireDesTags.hpp"

//private
void GestionnaireDesTags::ecrireDansLeFichier(){
    ;
}

void GestionnaireDesTags::ajouterTagByString(QString nom){
    Tag* tmp_tag = new Tag(nom);
    this->lestags.append(tmp_tag);
}

void GestionnaireDesTags::supprimerTag(Tag* tag){
    int resultat = this->lestags.indexOf(tag);
   if(resultat >= 0)
       this->lestags.removeAt(resultat);
   else
       ;

}

//public
GestionnaireDesTags::gestionnaireDesTags(){
    ;
}

void GestionnaireDesTags::récupérerLesTags(){
    ;
}

void GestionnaireDesTags::créerUnNouveauTag(QString nom){



    //mise a jour de la liste
    ajouterTagByString(nom);

}

void GestionnaireDesTags::supprimerUnTag(Tag *tag){


    //mise a jour de la liste
    supprimerTag(tag);
}
