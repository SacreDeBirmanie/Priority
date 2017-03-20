#include "headers/Tag.hpp"

Tag::Tag(QString nom){
    this->nom = nom;
}


QString Tag::getNom(){
    return this->nom;
}
void Tag::setNom(QString n){
    this->nom = n;
}

QStringList Tag::getFichiers(){
    return this->fichiers;
}

int Tag::compterFichiers(){
    return this->fichiers.count();
}

bool Tag::supprimerFichier(QString fich){
    int resultat = this->fichiers.indexOf(fich,0);
    if(resultat >= 0){
        this->fichiers.removeAt(resultat);
        return true;
    }
    else{
        return false;
    }
}
bool Tag::ajouterFichier(QString fichier){
    if(!this->fichiers.contains(fichier)){
        this->fichiers.append(fichier);
        return true;
    }
    else
        return false;
}
