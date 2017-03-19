#ifndef FENETRERECHERCHEAFFICHAGETAG_H
#define FENETRERECHERCHEAFFICHAGETAG_H
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QDirModel>
#include <QTreeView>
#include <QSplitter>

#include "GestionnaireDesTags.hpp"
#include "TagModel.hpp"

class FenetreRechercheAffichageTag : public QWidget {
    Q_OBJECT

    private :
        GestionnaireDesTags* gestionnaire;

        QPushButton *boutonRechercheTag;
        QLineEdit *textRechercheTag;

        QGridLayout *gridLayout;
        QTreeView *tree;
        QDirModel *directory;
        TagModel *tagmodel;

        void setUpDirTree();


    public :
        FenetreRechercheAffichageTag(GestionnaireDesTags* gest,QWidget *parent,QLayout *mainLayout);
        ~FenetreRechercheAffichageTag();

    public slots :
        void filtrerTag();
};


#endif // FENETRERECHERCHEAFFICHAGETAG_H
