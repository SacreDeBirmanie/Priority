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

class FenetreManagerDeTag : public QWidget {
    Q_OBJECT

    private :
        GestionnaireDesTags* gestionnaire;

        QPushButton* boutonCreerTag;
        QLineEdit *textNomTag;
        QList<QPushButton*> listeBoutonsTags;

        QVBoxLayout *positionnementManagerDesTags = new QVBoxLayout;

        QVBoxLayout *positionnementBarreAjoutTag = new QVBoxLayout;
        QGridLayout *positionnementTagsDisponibles = new QGridLayout;

        void positionnerTags(int largeurMax);
        void effacerLayout(QLayout *item);

    public :
        FenetreManagerDeTag(GestionnaireDesTags* gest,QWidget *parent);
        ~FenetreManagerDeTag();

    public slots :
        void creerUnNouveauTag();

};


#endif // FENETREMANAGERDETAG_H
