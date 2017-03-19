#include "FenetreRechercheAffichageTag.hpp"

FenetreRechercheAffichageTag::FenetreRechercheAffichageTag(GestionnaireDesTags* gest,QWidget *parent,QLayout *mainLayout) : QWidget(parent){
    //QSplitter *splitterMain = (QSplitter*)parent;
    gestionnaire = gest;
    gridLayout = new QGridLayout();
    QVBoxLayout *layout = (QVBoxLayout*)mainLayout;
    layout->addLayout(gridLayout);
    boutonRechercheTag = new QPushButton("Filtrer");
    textRechercheTag = new QLineEdit();
    textRechercheTag->setPlaceholderText("Entrer le ou les tag(s) pour filtrer les fichiers");
    gridLayout->addWidget(textRechercheTag,0,0,1,3);
    gridLayout->addWidget(boutonRechercheTag,0,3,1,1);
    directory = new QDirModel();
    QModelIndex index = directory->index(QDir::homePath());
    tree = new QTreeView();
    tree->setModel(directory);
    tree->setRootIndex(index);
    gridLayout->addWidget(tree,1,0,7,4);

    connect(textRechercheTag, SIGNAL(returnPressed()), this , SLOT(filtrerTag()));
    connect(boutonRechercheTag, SIGNAL(clicked()), this , SLOT(filtrerTag()));
}

FenetreRechercheAffichageTag::~FenetreRechercheAffichageTag(){

}

//SLOT
void FenetreRechercheAffichageTag::filtrerTag(){
    QString tmp = this->textRechercheTag->text();
    if(tmp.isNull()||tmp.isEmpty()){
        QModelIndex index = directory->index(QDir::homePath());
        tree->setModel(directory);
        tree->setRootIndex(index);
    }else{
        QStringList headers;
        headers << tr("Title");

        QStringList list= this->gestionnaire->recupererLesFichiers(gestionnaire->getTag(tmp));
        tagmodel = new TagModel(headers, list);
        tree->setModel(tagmodel);
    }
}
