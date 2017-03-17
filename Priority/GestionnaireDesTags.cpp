#include "GestionnaireDesTags.hpp"

#include "GestionnaireEnregistrementTag.hpp"
#include <iostream>

//public
GestionnaireDesTags::GestionnaireDesTags(){
    ;
}

void GestionnaireDesTags::recupererLesTags(){
    QStringList tags = GestionnaireEnregistrementTag::listeDesTags();

    QStringListIterator iterator(tags);
    while (iterator.hasNext()){
        Tag* tmp = new Tag(iterator.next().toLocal8Bit().constData());
        this->lestags.insert(tmp->getNom(), tmp);
        recupererLesFichiers(tmp);

    }
}

void GestionnaireDesTags::creerUnNouveauTag(QString nom_tag){
    QHash<QString, Tag*>::const_iterator i = this->lestags.find(nom_tag);
    if(i == this->lestags.end()){
        //mise a jour dans la mémoire
        GestionnaireEnregistrementTag::creerTag(nom_tag);

        //mise a jour de la liste
        this->ajouterTagByString(nom_tag);
    }
    else{
        ;
    }
}

void GestionnaireDesTags::supprimerTag(QString nom_tag){
    QHash<QString, Tag*>::const_iterator i = this->lestags.find(nom_tag);
    if(i != this->lestags.end()){
        //mise a jour de la memoire
        GestionnaireEnregistrementTag::supprimerTag(nom_tag);
        //mise a jour de la liste
        this->supprimerTagListe(nom_tag);
    }
    else{
        ;
    }
}

void GestionnaireDesTags::tagger(QString nom_tag, QString chemin_fichier){
    QHash<QString, Tag*>::const_iterator i = this->lestags.find(nom_tag);
    if(i != this->lestags.end()){
        if(i.value()->ajouterFichier(chemin_fichier)){
            GestionnaireEnregistrementTag *memoire = new GestionnaireEnregistrementTag(nom_tag);
            memoire->tagger(chemin_fichier);
        }
        else
            ;
    }
    else
        ;
}

void GestionnaireDesTags::detagger(QString nom_tag, QString chemin_fichier){

    GestionnaireEnregistrementTag *memoire = new GestionnaireEnregistrementTag(nom_tag);
    memoire->detagger(chemin_fichier);


    Tag * tag = getTag(nom_tag);
    tag->supprimerFichier(chemin_fichier);
}

QStringList GestionnaireDesTags::listeDesNomTags(){
    QHash<QString, Tag*>::const_iterator i = this->lestags.begin();
    QStringList laliste;
    while (i != this->lestags.end()){
            laliste.append(i.value()->getNom());
            i++;
    }

    return laliste;
}

//private
Tag* GestionnaireDesTags::getTag(QString nom_tag){
     QHash<QString, Tag*>::iterator i = this->lestags.find(nom_tag);
     while (i != this->lestags.end() && i.key() == nom_tag) {
         return i.value();
     }

     return NULL;
 }

void GestionnaireDesTags::recupererLesFichiers(Tag* tag){
     GestionnaireEnregistrementTag *document = new GestionnaireEnregistrementTag(tag->getNom());

     QStringList liste = document->recupererFichiers();

     QStringListIterator iterator(liste);
     while (iterator.hasNext()){
         tag->ajouterFichier(iterator.next().toLocal8Bit().constData());
     }

}


void GestionnaireDesTags::ajouterTagByString(QString nom){
    Tag* tmp_tag = new Tag(nom);
    this->lestags.insert(tmp_tag->getNom(),tmp_tag);
}

void GestionnaireDesTags::supprimerTagListe(QString nom_tag){
    QHash<QString, Tag*>::const_iterator i = this->lestags.find(nom_tag);
    while (i != this->lestags.end() && i.key() == nom_tag){
        if(i.value()==0){
            this->lestags.erase(i);
        }else
            i++;
    }

}
