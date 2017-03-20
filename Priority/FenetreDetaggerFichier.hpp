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

        QGridLayout* layout;
        QList<QPushButton*> listeBoutonsTags;

        QPushButton* revenirFenetrePrincipal;
        QPushButton* supprimerSelection;


    public :
        FenetreDetaggerFichier();

        void genererFenetre(QStringList fich);
        void supprimerLaSelection();

        void nettoyerFenetre();

        QPushButton* getRevenirFenetrePrincipal();
        QPushButton* getSupprimerSelection();

    public slots :
        void modificationBoutonTag();
};
#endif // FENETREDETAGGERFICHIER_HPP
