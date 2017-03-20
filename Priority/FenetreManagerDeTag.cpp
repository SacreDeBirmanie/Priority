#include "FenetreManagerDeTag.hpp"

#include <QStringList>
#include <QMessageBox>
#include <iostream>

FenetreManagerDeTag::FenetreManagerDeTag(GestionnaireDesTags* gest,QWidget *parent) : QSplitter(parent){
    gestionnaire = gest;
    this->setOrientation(Qt::Vertical);

    actionsLies = new QSplitter(Qt::Vertical);
    espaceTags = new QWidget();
    espaceTagsEtCreation = new QWidget();

    textNomTag = new QLineEdit();
    textNomTag->setPlaceholderText("Saississez un nouveau tag");
    boutonCreerTag = new QPushButton("Créer le tag");

    this->addWidget(actionsLies);
    this->addWidget(espaceTagsEtCreation);

    espaceTagsEtCreation->setLayout(positionnementBarreAjoutTag);
    positionnementBarreAjoutTag->addWidget(textNomTag,0,0,1,3);
    positionnementBarreAjoutTag->addWidget(boutonCreerTag,0,3,1,1);



    supprimerLesTagsSelectionne = new QPushButton("Supprimer les tags sélectionnés");
    actionsLies->addWidget(supprimerLesTagsSelectionne);
    ajouterLesTagsALaSelection = new QPushButton("Associer le(s) fichier(s) à un tag");
    actionsLies->addWidget(ajouterLesTagsALaSelection);

    espaceTags->setLayout(positionnementTagsDisponibles);

    positionnerTags(4);

    this->size();
    QList<int> sizes;
    sizes << this->size().height()*0.13 << this->size().height()*0.87;
    this->setSizes(sizes);

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

    effacerLayout(this->positionnementBarreAjoutTag);
    textNomTag = new QLineEdit();
    textNomTag->setPlaceholderText("Saississez un nouveau tag");
    boutonCreerTag = new QPushButton("Créer le tag");

    connect(textNomTag, SIGNAL(returnPressed()), this , SLOT(creerUnNouveauTag()));
    connect(boutonCreerTag, SIGNAL(clicked()), this , SLOT(creerUnNouveauTag()));

    positionnementBarreAjoutTag->addWidget(textNomTag,0,0,1,3);
    positionnementBarreAjoutTag->addWidget(boutonCreerTag,0,3,1,1);
    int placementHauteur = 5;
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
        this->positionnementBarreAjoutTag->addWidget(tmp,placementHauteur,placementLargeur);
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
    if(!this->gestionnaire->creerUnNouveauTag(tmp)){
        QMessageBox::warning(this,"Priority","Echec : Un tag porte déjà ce nom");
    }

    this->textNomTag->clear();
    this->positionnerTags(4);

}

void FenetreManagerDeTag::supprimerTags(){
    QString liste;
    QList<QPushButton*>::const_iterator i = listeBoutonsTags.begin();
    while (i != listeBoutonsTags.end()) {
        if((*i)->isChecked()){
           liste += "   " + (*i)->accessibleName();
        }
        i++;
   }
    int reponse = QMessageBox::question(this, "Suppression de tags", "vous allez supprimer les tags suivants suivants :\n"+ liste + "\n" + "Voulez-vous continuer ?", QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes){
        i = listeBoutonsTags.begin();
        while (i != listeBoutonsTags.end()) {
            if((*i)->isChecked()){
               this->gestionnaire->supprimerTag((*i)->accessibleName());
            }
            i++;
       }

        QMessageBox::information(this, "suppression réussie", "Les tags ont été supprimé correctement");
        }
        else if (reponse == QMessageBox::No){
            QMessageBox::critical(this, "suppression annulée", "La suppression des tags a été annulée.");
        }
        this->positionnerTags(4);
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



