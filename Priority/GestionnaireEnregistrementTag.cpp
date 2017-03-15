#include "GestionnaireEnregistrementTag.hpp"

#include <iostream>

#include "Navigation_Repertoire.hpp"

using namespace std;

const QString GestionnaireEnregistrementTag::NOM_DOSSIER_TAGS = QString(".TAGS");
const QString GestionnaireEnregistrementTag::CHEMIN_DOSSIER_TAGS = QString("");
const QString GestionnaireEnregistrementTag::EXTENSION = QString(".xml");


GestionnaireEnregistrementTag::GestionnaireEnregistrementTag(QString nom_fichier_tag){
    this->nom_fichier = nom_fichier_tag;
    this->dom = new QDomDocument(nom_fichier_tag);
    QFile xml_doc(CHEMIN_DOSSIER_TAGS+NOM_DOSSIER_TAGS +"/"+ nom_fichier_tag + EXTENSION);// On choisit le fichier contenant les informations XML.
    if(!xml_doc.open(QIODevice::ReadOnly))// Si l'on n'arrive pas à ouvrir le fichier XML.
    {
        //QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé");
        return;

    }
    if (!dom->setContent(&xml_doc)) // Si l'on n'arrive pas à associer le fichier XML à l'objet DOM.
    {
        xml_doc.close();
        //QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être attribué à l'objet QDomDocument.");
        return;
    }

    xml_doc.close(); // Dans tous les cas, on doit fermer le document XML : on n'en a plus besoin, tout est compris dans l'objet DOM.


}

QStringList GestionnaireEnregistrementTag::recupererFichiers(){
    QStringList laliste;

    QDomNodeList conteneur = this->dom->elementsByTagName("fichiers");
    for(int i = 0; i<conteneur.size();i++)
    {
        if(conteneur.at(i).isElement()){
            QDomElement tmp_conteneur = conteneur.at(i).toElement();
            QDomNodeList fichiers = tmp_conteneur.elementsByTagName("fichier");

            for(int i = 0; i<fichiers.size();i++){
                if(fichiers.at(i).isElement()){
                    QDomElement tmp_fichier = fichiers.at(i).toElement();
                    laliste.append(tmp_fichier.lastChild().nodeValue());
                }
            }
        }



    }

    return laliste;
}

void GestionnaireEnregistrementTag::tagger(QString nom_fich){
    QDomElement dom_element = this->dom->documentElement();

    QDomElement nouveau_element = this->dom->createElement("fichier");
    QDomText texte = this->dom->createTextNode(nom_fich);

    nouveau_element.appendChild(texte);
    QDomNodeList fichiers = this->dom->elementsByTagName("fichiers");
    if(fichiers.size()==0){
        QDomElement nouveau_conteneur = this->dom->createElement("fichiers");
        nouveau_conteneur.appendChild(nouveau_element);
        this->dom->appendChild(nouveau_conteneur);
    }
    else{
        if(fichiers.at(0).isElement()){
            QDomElement conteneur_existant = fichiers.at(0).toElement();
            conteneur_existant.appendChild(nouveau_element);
        }
    }


    Navigation_Repertoire::ecrire(CHEMIN_DOSSIER_TAGS+NOM_DOSSIER_TAGS + "/" + this->nom_fichier + EXTENSION , this->dom->toString() );
}

void GestionnaireEnregistrementTag::detagger(QString nom_fich){

    QDomNodeList conteneur = this->dom->elementsByTagName("fichiers");
    for(int i = 0; i<conteneur.size();i++)
    {
        if(conteneur.at(i).isElement()){
            QDomElement tmp_conteneur = conteneur.at(i).toElement();
            QDomNodeList fichiers = tmp_conteneur.elementsByTagName("fichier");

            for(int i = 0; i<fichiers.size();i++){
                if(fichiers.at(i).isElement()){
                    QDomElement tmp_fichier = fichiers.at(i).toElement();
                    if(tmp_fichier.lastChild().nodeValue() == nom_fich){
                        tmp_conteneur.removeChild(tmp_fichier);
                    }else
                        ;
                }
            }
        }

    }
    Navigation_Repertoire::ecrire(CHEMIN_DOSSIER_TAGS+NOM_DOSSIER_TAGS + "/" + this->nom_fichier + EXTENSION , this->dom->toString() );
}



GestionnaireEnregistrementTag::~GestionnaireEnregistrementTag()

{
    free(this->dom);

}

//fonctions statiques

QStringList GestionnaireEnregistrementTag::listeDesTags(){
    QStringList filtre;
    filtre << "*.xml";
    if(!Navigation_Repertoire::existe_dossier(CHEMIN_DOSSIER_TAGS+GestionnaireEnregistrementTag::NOM_DOSSIER_TAGS)){
        cout<<"pas de dossier"<<endl;
        if(Navigation_Repertoire::creerDossier(CHEMIN_DOSSIER_TAGS,NOM_DOSSIER_TAGS))
            cout<<"succès création dossier TAGS"<<endl;
        else
            cout<<"échec création dossier TAGS"<<endl;
    }
    return Navigation_Repertoire::listeDesFichiers(CHEMIN_DOSSIER_TAGS+NOM_DOSSIER_TAGS, filtre, false);
}

bool GestionnaireEnregistrementTag::existe(QString nom){
   return Navigation_Repertoire::existe_fichier(CHEMIN_DOSSIER_TAGS+NOM_DOSSIER_TAGS+"/" + nom + EXTENSION);
}

void GestionnaireEnregistrementTag::creerTag(QString nom){
    cout<<"création tag"<<endl;
    if(!Navigation_Repertoire::existe_fichier(CHEMIN_DOSSIER_TAGS+GestionnaireEnregistrementTag::NOM_DOSSIER_TAGS+"/" + nom + EXTENSION)){
        cout<<"le tag n'existe pas"<<endl;
        Navigation_Repertoire::creerFichier(CHEMIN_DOSSIER_TAGS+GestionnaireEnregistrementTag::NOM_DOSSIER_TAGS+"/", nom + EXTENSION);

    }
    else{
        cout<<"le tag existe déjà"<<endl;
    }
}

void GestionnaireEnregistrementTag::supprimerTag(QString nom){
     Navigation_Repertoire::supprimerFichier(GestionnaireEnregistrementTag::CHEMIN_DOSSIER_TAGS+GestionnaireEnregistrementTag::NOM_DOSSIER_TAGS, nom + GestionnaireEnregistrementTag::EXTENSION);
}



