#include "FenetreRechercheAffichageTag.hpp"

FenetreRechercheAffichageTag::FenetreRechercheAffichageTag(GestionnaireDesTags* gest,QWidget *parent) : QWidget(parent){
    gestionnaire = gest;
    gridLayout = new QGridLayout();
    parent->layout()->addWidget(gridLayout->parentWidget());
    boutonRechercheTag = new QPushButton("Filtrer");
    textRechercheTag = new QLineEdit();
    textRechercheTag->setPlaceholderText("Entrer le ou les tag(s) pour filtrer les fichiers");
    gridLayout->addWidget(textRechercheTag,0,0,3,1);
    gridLayout->addWidget(boutonRechercheTag,0,3,1,1);
}

FenetreRechercheAffichageTag::~FenetreRechercheAffichageTag(){

}
