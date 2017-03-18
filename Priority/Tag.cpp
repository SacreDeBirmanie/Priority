#include "Tag.hpp"

Tag::Tag(QString nom){
    this->nom = nom;
}


QString Tag::getNom(){
    return this->nom;
}
void Tag::setNom(QString n){
    this->nom = n;
}

int Tag::compterFichiers(){
    return this->fichiers.count();
}

void Tag::supprimerFichier(QString fich){
    int resultat = this->fichiers.indexOf(fich,0);
    if(resultat >= 0)
        this->fichiers.removeAt(resultat);
    else
        ;
}
bool Tag::ajouterFichier(QString fichier){
    if(!this->fichiers.contains(fichier)){
        this->fichiers.append(fichier);
        return true;
    }
    else
        return false;
}
