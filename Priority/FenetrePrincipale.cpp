#include "FenetrePrincipale.hpp"

#include <iostream>

FenetrePrincipale::FenetrePrincipale(){

    gestionnaire = new GestionnaireDesTags();
    gestionnaire->recupererLesTags();

    fenetreRAT = new FenetreRechercheAffichageTag(gestionnaire);
    fenetre.addWidget(fenetreRAT);
    fenetreMDT = new FenetreManagerDeTag(gestionnaire);
    fenetre.addWidget(fenetreMDT);

    fenetre.setFrameStyle(QFrame::Box);
    QObject::connect(fenetreMDT->getAjouterLesTagsALaSelection(), SIGNAL(clicked()), this , SLOT(ajouterTagsSelection()));
    QObject::connect(fenetreRAT, SIGNAL(modificationTags()), this , SLOT(updateMDT()));


    fenetre.showMaximized();





}

void FenetrePrincipale::ajouterTagsSelection(){
    QStringList fichiers = fenetreRAT->recupererSelection();
    QStringList tags = fenetreMDT->recupererBoutonsSelectionne();

    QStringList::const_iterator i = tags.begin();
    while (i != tags.end()){
            gestionnaire->tagger((*i).toLocal8Bit().constData() ,fichiers);
            i++;
    }

    fenetreMDT->update();

}

void FenetrePrincipale::updateMDT(){
    fenetreMDT->update();
}
