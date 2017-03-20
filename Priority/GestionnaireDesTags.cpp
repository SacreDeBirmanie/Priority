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
    QHash<QString, Tag*>::iterator i = this->lestags.find(nom_tag);
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
    QHash<QString, Tag*>::iterator i = this->lestags.find(nom_tag);
    if(i != this->lestags.end()){
        //mise a jour de la memoire
        GestionnaireEnregistrementTag::supprimerTag(nom_tag);
        std::cout<<nom_tag.toStdString()<<std::endl;
        //mise a jour de la liste
        this->supprimerTagListe(nom_tag);
         std::cout<<nom_tag.toStdString()<<std::endl;
    }
    else{
        ;
    }
}

void GestionnaireDesTags::tagger(QString nom_tag, QString chemin_fichier){
    QHash<QString, Tag*>::iterator i = this->lestags.find(nom_tag);
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

void GestionnaireDesTags::tagger(QString nom_tag, QStringList noms_fichiers){

    QHash<QString, Tag*>::iterator i = this->lestags.find(nom_tag);
    if(i != this->lestags.end()){
        QStringListIterator iterator(noms_fichiers);
        GestionnaireEnregistrementTag *memoire = new GestionnaireEnregistrementTag(nom_tag);
        while (iterator.hasNext()){
                QString tmp = iterator.next().toLocal8Bit().constData();
                if(i.value()->ajouterFichier(tmp)){
                    memoire->tagger(tmp);
                }
                else
                    ;
        }
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

void GestionnaireDesTags::detagger(QString nom_tag, QStringList fichiers){

    QHash<QString, Tag*>::iterator i = this->lestags.find(nom_tag);
    if(i != this->lestags.end()){
        QStringListIterator iterator(fichiers);
        GestionnaireEnregistrementTag *memoire = new GestionnaireEnregistrementTag(nom_tag);
        while (iterator.hasNext()){
                QString tmp = iterator.next().toLocal8Bit().constData();
                if(i.value()->supprimerFichier(tmp)){
                    memoire->detagger(tmp);
                }
                else
                    ;
        }
    }
    else
        ;
}

QStringList GestionnaireDesTags::listeDesNomTags(){
    QHash<QString, Tag*>::iterator i = this->lestags.begin();
    QStringList laliste;
    while (i != this->lestags.end()){
            laliste.append(i.value()->getNom());
            i++;
    }

    return laliste;
}

QStringList GestionnaireDesTags::listeDesNomTags(QString nom_fichier){
    std::cout<<"aaaaaa"<<std::endl;
    std::cout<<lestags.size()<<std::endl;
    QHash<QString, Tag*>::iterator i = lestags.begin();
    std::cout<<"qqsdqdqsd"<<std::endl;
    QStringList laliste;

    while (i != lestags.end()){
        std::cout<<"lqqqol"<<std::endl;
            Tag* tmp = i.value();
            if(tmp->getFichiers().contains(nom_fichier))
                laliste.append(tmp->getNom());
            i++;
    }

    return laliste;
}

int  GestionnaireDesTags::compterFichiers(QString nom_tag){
    QHash<QString, Tag*>::iterator i = this->lestags.find(nom_tag);
    int tmp = 0;
    int count = 0;
    while (i != this->lestags.end() && i.key() == nom_tag && count<3) {
        tmp =  i.value()->compterFichiers();
        i++;
    }

    return tmp;
}

//private
Tag* GestionnaireDesTags::getTag(QString nom_tag){
     QHash<QString, Tag*>::iterator i = this->lestags.find(nom_tag);
     while (i != this->lestags.end() && i.key() == nom_tag) {
         return i.value();
     }

     return NULL;
 }

QStringList GestionnaireDesTags::recupererLesFichiers(Tag* tag){
     GestionnaireEnregistrementTag *document = new GestionnaireEnregistrementTag(tag->getNom());

     QStringList liste = document->recupererFichiers();

     QStringListIterator iterator(liste);
     while (iterator.hasNext()){
         tag->ajouterFichier(iterator.next().toLocal8Bit().constData());
     }
     return liste;
}


void GestionnaireDesTags::ajouterTagByString(QString nom){
    Tag* tmp_tag = new Tag(nom);
    this->lestags.insert(tmp_tag->getNom(),tmp_tag);
}

void GestionnaireDesTags::supprimerTagListe(QString nom_tag){
    this->lestags.remove(nom_tag);
}
