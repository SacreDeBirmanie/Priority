#ifndef TAG_H
#define TAG_H

#include <QString>
#include <QStringList>

class Tag{
private :
    QString nom;
    QStringList fichiers;

public :
    Tag(QString nom);

    QString getNom();
    void setNom(QString n);

    void supprimerFichier(QString fich);
    bool ajouterFichier(QString fichier);
};


#endif // TAG_H
