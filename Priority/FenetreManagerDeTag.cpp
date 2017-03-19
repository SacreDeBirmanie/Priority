#include "FenetreManagerDeTag.hpp"

#include <QStringList>
#include <iostream>

FenetreManagerDeTag::FenetreManagerDeTag(GestionnaireDesTags* gest,QWidget *parent) : QWidget(parent){
    gestionnaire = gest;
    setLayout(this->positionnementManagerDesTags);



    textNomTag = new QLineEdit();
    boutonCreerTag = new QPushButton("creer le tag");

    ajouterLesTagsALaSelection = new QPushButton("ajouter les tags à la selection", actionsLies);
    ajouterLesTagsALaSelection->setStyleSheet("background-color: green;border : none");

    supprimerLesTagsSelectionne = new QPushButton("ajouter les tags à la selection", actionsLies);
    actionsLies->setFixedHeight(this->height()*0.5);


    actionsLies->setStyleSheet("border: 3px solid black; border-radius: 10px;");

    positionnementBarreAjoutTag->addWidget(textNomTag);
    positionnementBarreAjoutTag->addWidget(boutonCreerTag);

    positionnementManagerDesTags->addWidget(actionsLies);
    positionnementManagerDesTags->addLayout(positionnementBarreAjoutTag);
    positionnementManagerDesTags->addLayout(positionnementTagsDisponibles);
    positionnerTags(4);

    connect(supprimerLesTagsSelectionne, SIGNAL(clicked()), this , SLOT(supprimerTags()));
    connect(textNomTag, SIGNAL(returnPressed()), this , SLOT(creerUnNouveauTag()));
    connect(boutonCreerTag, SIGNAL(clicked()), this , SLOT(creerUnNouveauTag()));


}

FenetreManagerDeTag::~FenetreManagerDeTag(){
    ;
}

QPushButton* FenetreManagerDeTag::getAjouterLesTagsALaSelection(){
    return ajouterLesTagsALaSelection;
}

void FenetreManagerDeTag::update(){
    positionnerTags(4);
}

//PRIVATE
void FenetreManagerDeTag::effacerLayout(QLayout *item)
{
    while (item->count() > 0) {
        QLayoutItem *child = item->takeAt(0);
        if (child == 00) continue;
        if (child->layout() != 0) effacerLayout(child->layout());
        if (child->widget()) delete child->widget();
        delete child;
    }
}

void FenetreManagerDeTag::positionnerTags(int largeurMax){
    QStringList laliste = this->gestionnaire->listeDesNomTags();
    listeBoutonsTags.clear();

    effacerLayout(this->positionnementTagsDisponibles);

    int placementHauteur = 0;
    int placementLargeur = 0;
    QStringList::const_iterator i = laliste.begin();
    while (i != laliste.end()) {
        QString nom_tag = (*i).toLocal8Bit().constData();
        QPushButton* tmp = new QPushButton(nom_tag + " : " + QString::number(gestionnaire->compterFichiers(nom_tag)));
        tmp->setAccessibleName(nom_tag);
        listeBoutonsTags.append(tmp);
        tmp->setCheckable(true);
        tmp->setToolTip("nom_du_tag : nombre fichiers associés");
        tmp->setChecked(false);
        tmp->setStyleSheet("background-color: white;");
        connect(tmp,SIGNAL(clicked()),this,SLOT(modificationBoutonTag()));
        this->positionnementTagsDisponibles->addWidget(tmp,placementHauteur,placementLargeur);
        if(placementLargeur<largeurMax-1){
            placementLargeur++;
        }
        else{
            placementLargeur = 0;
            placementHauteur++;
        }
        i++;
    }


}
QStringList FenetreManagerDeTag::recupererBoutonsSelectionne(){
    QStringList laliste;
    QList<QPushButton*>::const_iterator i = listeBoutonsTags.begin();
    while (i != listeBoutonsTags.end()) {
        if((*i)->isChecked())
            laliste.append((*i)->accessibleName());
        i++;
    }
    return laliste;

}

//SLOT
void FenetreManagerDeTag::creerUnNouveauTag(){
    QString tmp = this->textNomTag->text();
    this->gestionnaire->creerUnNouveauTag(tmp);
    this->textNomTag->clear();
    this->positionnerTags(4);

}

void FenetreManagerDeTag::supprimerTags(){
    QList<QPushButton*>::const_iterator i = listeBoutonsTags.begin();
    while (i != listeBoutonsTags.end()) {
        gestionnaire->supprimerTag((*i)->accessibleName());
        i++;
    }

}

void FenetreManagerDeTag::modificationBoutonTag(){
    QPushButton* bouton = qobject_cast<QPushButton*>(sender());

    if(!bouton) {
        return;
    }

    if(bouton->isChecked()){
        bouton->setStyleSheet("background-color: blue;");

    }
    else{
        bouton->setStyleSheet("background-color: white;");
    }


}



