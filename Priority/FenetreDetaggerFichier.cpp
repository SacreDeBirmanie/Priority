#include "FenetreDetaggerFichier.hpp"
#include <QTextLine>
#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <iostream>

FenetreDetaggerFichier::FenetreDetaggerFichier(GestionnaireDesTags* gest){
    gestionnaire = gest;
    this->setOrientation(Qt::Vertical);
    layout = new QGridLayout();

    choix = new QWidget;
    revenirFenetrePrincipal = new QPushButton("revenir au menu principal");
    supprimerSelection = new QPushButton("supprimer la selection");
    QHBoxLayout* layoutChoix = new QHBoxLayout;
    choix->setLayout(layoutChoix);
    layoutChoix->addWidget(revenirFenetrePrincipal);
    layoutChoix->addWidget(supprimerSelection);
    this->addWidget(choix);



    connect(revenirFenetrePrincipal, SIGNAL(clicked()), this , SLOT(close()));
    connect(supprimerSelection, SIGNAL(clicked()), this , SLOT(supprimerLaSelection()));
}

void FenetreDetaggerFichier::genererFenetre(QStringList fich){
    this->fichiers = fich;
    QStringList::iterator i = fichiers.begin();
    QWidget* objetTags = new QWidget();
    this->addWidget(objetTags);
    objetTags->setLayout(layout);
        while (i != fichiers.end()) {
            QStringList liste_tmp = gestionnaire->listeDesNomTags((*i).toLocal8Bit().constData());
            QStringList listeDesTags;
            QStringList::const_iterator j = liste_tmp.constBegin();

            int placementHauteur = 0;
            int placementLargeur = 0;
            int largeurMax = 5;

            while (j != liste_tmp.end()) {
                if(!listeDesTags.contains((*j).toLocal8Bit().constData())){
                    listeDesTags.append((*j).toLocal8Bit().constData());
                    QPushButton* tmp = new QPushButton ((*j).toLocal8Bit().constData());
                    listeBoutonsTags.append(tmp);
                    tmp->setAccessibleName((*j).toLocal8Bit().constData());
                    tmp->setCheckable(true);
                    tmp->setChecked(false);
                    tmp->setStyleSheet("background-color: white;");
                    connect(tmp,SIGNAL(clicked()),this,SLOT(modificationBoutonTag()));
                    layout->addWidget(tmp,placementHauteur,placementLargeur);

                    if(placementLargeur<largeurMax-1){
                        placementLargeur++;
                    }
                    else{
                        placementLargeur = 0;
                        placementHauteur++;
                    }

                }
                j++;
            }
            i++;

        }

        i = fichiers.begin();
        QGraphicsScene* scene= new QGraphicsScene;
        QGraphicsView*  vue;
        while (i != fichiers.end()) {
                scene->addText((*i).toLocal8Bit().constData());
                i++;
        }
        vue = new QGraphicsView(scene,this);


}

void FenetreDetaggerFichier::supprimerLaSelection(){
    QList<QPushButton*>::const_iterator i = listeBoutonsTags.begin();
    while (i != listeBoutonsTags.end()) {
        if((*i)->isChecked())
            gestionnaire->detagger((*i)->accessibleName(),fichiers);
        i++;
    }
    this->close();
}

void FenetreDetaggerFichier::nettoyerFenetre(){

}

QPushButton* FenetreDetaggerFichier::getRevenirFenetrePrincipal(){
    return revenirFenetrePrincipal;
}
QPushButton* FenetreDetaggerFichier::getSupprimerSelection(){
    return supprimerSelection;
}

void FenetreDetaggerFichier::modificationBoutonTag(){
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
