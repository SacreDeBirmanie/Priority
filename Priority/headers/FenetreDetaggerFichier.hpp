#ifndef FENETREDETAGGERFICHIER_HPP
#define FENETREDETAGGERFICHIER_HPP

#include <QWidget>
#include <QPushButton>
#include <QSplitter>
#include <QGridLayout>

#include "headers/GestionnaireDesTags.hpp"
/**
 * @brief FenetreDetaggerFichier Pop-up de suppression de tag pour un fichier
 */

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

        /**
         * @brief Constructeur de la classe
         * @param gest le gestionnaire de tag
         */
        FenetreDetaggerFichier(GestionnaireDesTags* gest);

        /**
         * @brief Création de la fenêtre
         * @param fich les fichiers sélectionné
         */
        void genererFenetre(QStringList fich);

        /**
         * @brief réinitialise la fenêtre
         */
        void nettoyerFenetre();

        QPushButton* getRevenirFenetrePrincipal();
        QPushButton* getSupprimerSelection();

    public slots :
        void modificationBoutonTag();
        void supprimerLaSelection();

    signals :
        void seFerme();

};
#endif // FENETREDETAGGERFICHIER_HPP
