#ifndef FENETREDETAGGERFICHIER_HPP
#define FENETREDETAGGERFICHIER_HPP

#include <QWidget>
#include <QPushButton>
#include <QSplitter>
#include <QGridLayout>

#include "GestionnaireDesTags.hpp"


class FenetreDetaggerFichier : public QSplitter {
    Q_OBJECT

    private :
        GestionnaireDesTags* gestionnaire;
        QStringList fichiers;
        QWidget* choix;

        QGridLayout* layout;
        QList<QPushButton*> listeBoutonsTags;

        QPushButton* revenirFenetrePrincipal;
        QPushButton* supprimerSelection;


    public :
        FenetreDetaggerFichier(GestionnaireDesTags* gest);

        void genererFenetre(QStringList fich);


        void nettoyerFenetre();

        QPushButton* getRevenirFenetrePrincipal();
        QPushButton* getSupprimerSelection();

    public slots :
        void modificationBoutonTag();
        void supprimerLaSelection();
};
#endif // FENETREDETAGGERFICHIER_HPP
