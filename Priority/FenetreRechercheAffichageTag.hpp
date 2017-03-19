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
#include <QVector>
#include <QVectorIterator>
#include <QMessageBox>
#include <QCompleter>
#include <QLabel>

#include "GestionnaireDesTags.hpp"
#include "TagModel.hpp"

class FenetreRechercheAffichageTag : public QWidget {
    Q_OBJECT

    private :
        GestionnaireDesTags* gestionnaire;

        QPushButton *boutonRechercheTag;
        QLineEdit *textRechercheTag;
        QLabel *tags_filter;

        QGridLayout *gridLayout;
        QTreeView *tree;
        QDirModel *directory;
        TagModel *tagmodel;
        QVector<Tag*> *active_tag;

         QCompleter * completer;

        void setUpDirTree();
        QStringList filtrerTag();


    public :
        FenetreRechercheAffichageTag(GestionnaireDesTags* gest,QWidget *parent,QLayout *mainLayout);
        ~FenetreRechercheAffichageTag();

    public slots :
        void filtrerTag_onclick();
};


#endif // FENETRERECHERCHEAFFICHAGETAG_H
