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
#include <QMenu>
#include <QDesktopServices>
#include <QUrl>

#include "GestionnaireDesTags.hpp"
#include "FenetreDetaggerFichier.hpp"
#include "TagModel.hpp"

class FenetreRechercheAffichageTag : public QWidget {
    Q_OBJECT

    private :
        GestionnaireDesTags* gestionnaire;

        FenetreDetaggerFichier* fenetreDetagger;

        QPushButton *boutonRechercheTag;
        QLineEdit *textRechercheTag;
        QLabel *tags_filter;
        QPushButton *boutonclear_filter;
        QPushButton* deselectionTree;

        QGridLayout *gridLayout;
        QTreeView *tree;
        QDirModel *directory;
        TagModel *tagmodel;
        QVector<Tag*> *active_tag;
        bool isDirModel;

        QCompleter * completer;

        QMenu* contextMenu;
        QAction* ouvrirAction;

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
        void tout_deselectionner();
        void ouvrirFichier();
        void onCustomContextMenu(const QPoint &point);
};


#endif // FENETRERECHERCHEAFFICHAGETAG_H
