#include "GestionnaireDesTags.hpp"

#include "GestionnaireEnregistrementTag.hpp"

//public
GestionnaireDesTags::GestionnaireDesTags(){
    ;
}

void GestionnaireDesTags::recupererLesFichiers(Tag* tag){
    GestionnaireEnregistrementTag *document = new GestionnaireEnregistrementTag(tag->getNom());

    QStringList liste = document->recupererFichiers();

    QStringListIterator iterator(liste);
    while (iterator.hasNext()){
        tag->ajouterFichier(iterator.next().toLocal8Bit().constData());
    }

}

void GestionnaireDesTags::recupererLesTags(){
    QStringList tags = GestionnaireEnregistrementTag::listeDesTags();

    QStringListIterator iterator(tags);
    while (iterator.hasNext()){
        Tag* tmp = new Tag(iterator.next().toLocal8Bit().constData());
        this->lestags.append(tmp);
        recupererLesFichiers(tmp);

    }
}

void GestionnaireDesTags::creerUnNouveauTag(QString nom){
    if(!GestionnaireEnregistrementTag::existe(nom)){
        //mise a jour dans la mémoire
        GestionnaireEnregistrementTag::creerTag(nom);

        //mise a jour de la liste
        this->ajouterTagByString(nom);
    }
    else
        ;

}

void GestionnaireDesTags::supprimerUnTag(Tag *tag){
    if(!GestionnaireEnregistrementTag::existe(tag->getNom())){
        //mise a jour de la memoire
        GestionnaireEnregistrementTag::supprimerTag(tag->getNom());
        //mise a jour de la liste
        this->supprimerTag(tag);
    }
    else
        ;
}

//private
void GestionnaireDesTags::tagerUnFichier(QString fich){
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
