#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QWidget>
#include <QSplitter>
#include <QHBoxLayout>

#include "headers/FenetreManagerDeTag.hpp"
#include "headers/FenetreRechercheAffichageTag.hpp"

/**
 * @brief The FenetrePrincipale La fenêtre principale
 */
class FenetrePrincipale : public QWidget{
    Q_OBJECT

    private :
        QSplitter fenetre;


        GestionnaireDesTags* gestionnaire;

        FenetreRechercheAffichageTag* fenetreRAT;
        FenetreManagerDeTag* fenetreMDT;


    public :
        FenetrePrincipale();

    public slots :
        void ajouterTagsSelection();
        void updateMDT();

};

#endif // FENETREPRINCIPALE_H
