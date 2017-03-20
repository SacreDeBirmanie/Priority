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
    QStringList getFichiers();
    int compterFichiers();

    bool supprimerFichier(QString fich);
    bool ajouterFichier(QString fichier);
};


#endif // TAG_H
