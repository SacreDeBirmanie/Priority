#include "FenetreManagerDeTag.hpp"

#include <QStringList>
#include <iostream>

FenetreManagerDeTag::FenetreManagerDeTag(GestionnaireDesTags* gest,QWidget *parent) : QWidget(parent){
    gestionnaire = gest;
    setLayout(this->positionnementManagerDesTags);

    textNomTag = new QLineEdit();
    boutonCreerTag = new QPushButton("creer le tag");

    positionnementBarreAjoutTag->addWidget(textNomTag);
    positionnementBarreAjoutTag->addWidget(boutonCreerTag);

    positionnementManagerDesTags->addLayout(positionnementBarreAjoutTag);

    positionnementManagerDesTags->addLayout(positionnementTagsDisponibles);

    positionnerTags(4);


    connect(textNomTag, SIGNAL(returnPressed()), this , SLOT(creerUnNouveauTag()));
    connect(boutonCreerTag, SIGNAL(clicked()), this , SLOT(creerUnNouveauTag()));


}

FenetreManagerDeTag::~FenetreManagerDeTag(){
    ;
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

    effacerLayout(this->positionnementTagsDisponibles);

    int placementHauteur = 0;
    int placementLargeur = 0;
    QStringList::const_iterator i = laliste.begin();
    while (i != laliste.end()) {
        QPushButton* tmp = new QPushButton((*i).toLocal8Bit().constData());
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

//SLOT
void FenetreManagerDeTag::creerUnNouveauTag(){
    QString tmp = this->textNomTag->text();
    this->gestionnaire->creerUnNouveauTag(tmp);
    this->textNomTag->clear();
    this->positionnerTags(4);
}



