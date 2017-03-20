#include "FenetreDetaggerFichier.hpp"
#include <QTextLine>
#include <QVBoxLayout>
#include <QWidget>

FenetreDetaggerFichier::FenetreDetaggerFichier(){
    this->setOrientation(Qt::Vertical);

    revenirFenetrePrincipal = new QPushButton();
    supprimerSelection = new QPushButton();
}

void FenetreDetaggerFichier::genererFenetre(QStringList fich){
    this->fichiers = fich;
    QStringList::const_iterator i = fichiers.begin();
    QStringList listeDesTags;
    QWidget* objetTags = new QWidget();
    this->addWidget(objetTags);
        while (i != fichiers.end()) {
            if(!listeDesTags.contains((*i).toLocal8Bit().constData())){
                QPushButton* tmp = new QPushButton ((*i).toLocal8Bit().constData());
                tmp->setCheckable(true);
                tmp->setChecked(false);
                tmp->setStyleSheet("background-color: white;");
                connect(tmp,SIGNAL(clicked()),this,SLOT(modificationBoutonTag()));
                //objetTags->addWidget(tmp);
            }

        }

        i = fichiers.begin();
        while (i != fichiers.end()) {
               /* QTextLine* tmp_line = new QTextLine ((*i).toLocal8Bit().constData());
                this->addWidget(tmp_line);*/
        }


}

void FenetreDetaggerFichier::supprimerLaSelection(){
    QList<QPushButton*>::const_iterator i = listeBoutonsTags.begin();
    while (i != listeBoutonsTags.end()) {
        if((*i)->isChecked())
            /*gestionnaire->detagger((*i)->accessibleName(),fichiers);*/
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
