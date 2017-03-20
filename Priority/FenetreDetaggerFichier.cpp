#include "FenetreDetaggerFichier.hpp"
#include <QTextLine>
#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <iostream>

FenetreDetaggerFichier::FenetreDetaggerFichier(){
    this->setOrientation(Qt::Vertical);
    layout = new QGridLayout();

    revenirFenetrePrincipal = new QPushButton();
    supprimerSelection = new QPushButton();
}

void FenetreDetaggerFichier::genererFenetre(QStringList fich){
    this->fichiers = fich;
    QStringList::iterator i = fichiers.begin();
    QWidget* objetTags = new QWidget();
    this->addWidget(objetTags);
    objetTags->setLayout(layout);

        std::cout<<"lol"<<std::endl;
        while (i != fichiers.end()) {
            std::cout<<(*i).toLocal8Bit().constData()<<std::endl;
            QStringList listeDesTags = gestionnaire->listeDesNomTags((*i).toLocal8Bit().constData());
            std::cout<<"bre"<<std::endl;
            QStringList::const_iterator j = listeDesTags.begin();
            while (j != listeDesTags.end()) {
                std::cout<<"lol"<<std::endl;
                if(!listeDesTags.contains((*j).toLocal8Bit().constData())){
                    QPushButton* tmp = new QPushButton ((*j).toLocal8Bit().constData());
                    listeBoutonsTags.append(tmp);
                    tmp->setCheckable(true);
                    tmp->setChecked(false);
                    tmp->setStyleSheet("background-color: white;");
                    connect(tmp,SIGNAL(clicked()),this,SLOT(modificationBoutonTag()));
                    layout->addWidget(tmp);

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
