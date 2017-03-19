#ifndef FENETREMANAGERDETAG_H
#define FENETREMANAGERDETAG_H
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLineEdit>
#include <QList>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSplitter>

#include "GestionnaireDesTags.hpp"

class FenetreManagerDeTag : public QSplitter {
    Q_OBJECT

    private :
        GestionnaireDesTags* gestionnaire;

        QSplitter* actionsLies = new QSplitter();
        QWidget* espaceTags = new QWidget();
        QWidget* espaceTagsEtCreation = new QWidget();

        QPushButton* boutonCreerTag;
        QPushButton* ajouterLesTagsALaSelection;
        QPushButton* supprimerLesTagsSelectionne;
        QLineEdit *textNomTag;
        QList<QPushButton*> listeBoutonsTags;

        QVBoxLayout *positionnementBarreAjoutTag = new QVBoxLayout;
        QGridLayout *positionnementTagsDisponibles = new QGridLayout;

        void positionnerTags(int largeurMax);
        void effacerLayout(QLayout *item);

    public :
        FenetreManagerDeTag(GestionnaireDesTags* gest,QWidget *parent = 0);
        ~FenetreManagerDeTag();
        QPushButton* getAjouterLesTagsALaSelection();
        QStringList recupererBoutonsSelectionne();
        void update();

    public slots :
        void creerUnNouveauTag();
        void supprimerTags();
        void modificationBoutonTag();

};


#endif // FENETREMANAGERDETAG_H
