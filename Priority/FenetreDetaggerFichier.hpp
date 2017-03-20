#ifndef FENETREDETAGGERFICHIER_HPP
#define FENETREDETAGGERFICHIER_HPP

#include <QWidget>
#include <QPushButton>
#include <QSplitter>

#include "GestionnaireDesTags.hpp"


class FenetreDetaggerFichier : public QSplitter {
    Q_OBJECT

    private :
        GestionnaireDesTags* gestionnaire;
        QStringList fichiers;

        QList<QPushButton*> listeBoutonsTags;

        QPushButton* revenirFenetrePrincipal;
        QPushButton* supprimerSelection;

        void modificationBoutonTag();

    public :
        FenetreDetaggerFichier();

        void genererFenetre(QStringList fich);
        void supprimerLaSelection();

        void nettoyerFenetre();

        QPushButton* getRevenirFenetrePrincipal();
        QPushButton* getSupprimerSelection();
};
#endif // FENETREDETAGGERFICHIER_HPP
