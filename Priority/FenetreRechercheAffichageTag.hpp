#ifndef FENETRERECHERCHEAFFICHAGETAG_H
#define FENETRERECHERCHEAFFICHAGETAG_H
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QDirModel>
#include <QTreeView>
#include "GestionnaireDesTags.hpp"

class FenetreRechercheAffichageTag : public QWidget {
    Q_OBJECT

    private :
        GestionnaireDesTags* gestionnaire;

        QPushButton *boutonRechercheTag;
        QLineEdit *textRechercheTag;

        QGridLayout *gridLayout;
        QTreeView *tree;
        QDirModel *directory;
        //TagModel *tagmodel;


    public :
        FenetreRechercheAffichageTag(GestionnaireDesTags* gest,QWidget *parent);
        ~FenetreRechercheAffichageTag();

    public slots :

};


#endif // FENETRERECHERCHEAFFICHAGETAG_H
