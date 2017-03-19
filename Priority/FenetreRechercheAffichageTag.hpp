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
        QPushButton *boutonclear_filter;

        QGridLayout *gridLayout;
        QTreeView *tree;
        QDirModel *directory;
        TagModel *tagmodel;
        QVector<Tag*> *active_tag;

        QCompleter * completer;

        void setUpDirTree();
        QStringList filtrerTag();


    public :
        FenetreRechercheAffichageTag(GestionnaireDesTags* gest,QWidget *parent = 0);
        ~FenetreRechercheAffichageTag();
        QStringList recupererSelection();
        QTreeView* getTreeView();

    public slots :
        void filtrerTag_onclick();
        void clearfilter_onclick();
};


#endif // FENETRERECHERCHEAFFICHAGETAG_H