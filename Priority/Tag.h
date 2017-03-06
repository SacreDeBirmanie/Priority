#ifndef TAG_H
#define TAG_H
#include <string>
#include <ArrayList>
#include <QtXml>

public class tag{
private :
    QString nom;
    QList<QString> fichiers;

public :
    QString getNom(){
        return nom;
    }

    void setNom(QString n){
        nom = n;
    }

    void supprimerFichier(QString fich){
        int i = fichiers.indexOf(fich);
        if(i>=0){
            fichiers.erase(i);
        }
        else{
            console.log("impossible de supprimer le tag : tag inexistant pour ce fichier")
        }
    }

    void ajouter



}


#endif // TAG_H
