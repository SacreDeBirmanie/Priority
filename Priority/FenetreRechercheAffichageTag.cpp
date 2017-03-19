#include "FenetreRechercheAffichageTag.hpp"

FenetreRechercheAffichageTag::FenetreRechercheAffichageTag(GestionnaireDesTags* gest,QWidget *parent,QLayout *mainLayout) : QWidget(parent){
    //QSplitter *splitterMain = (QSplitter*)parent;
    gestionnaire = gest;
    gridLayout = new QGridLayout();
    QHBoxLayout *layout = (QHBoxLayout*)mainLayout;
    layout->addLayout(gridLayout);
    boutonRechercheTag = new QPushButton("Filtrer");
    textRechercheTag = new QLineEdit();
    textRechercheTag->setPlaceholderText("Entrer le ou les tag(s) pour filtrer les fichiers");
    gridLayout->addWidget(textRechercheTag,0,0,1,3);
    gridLayout->addWidget(boutonRechercheTag,0,3,1,1);
    directory = new QDirModel(parent);
    tree = new QTreeView();
    setUpDirTree();
    gridLayout->addWidget(tree,1,0,7,4);

    connect(textRechercheTag, SIGNAL(returnPressed()), this , SLOT(filtrerTag()));
    connect(boutonRechercheTag, SIGNAL(clicked()), this , SLOT(filtrerTag()));
}

FenetreRechercheAffichageTag::~FenetreRechercheAffichageTag(){

}

void FenetreRechercheAffichageTag::setUpDirTree(){
    tree->setModel(directory);
    tree->setRootIndex(directory->index(QDir::homePath()));
    tree->setColumnWidth(0,700);
    tree->setColumnHidden(1,true);
    tree->setColumnHidden(2,true);
    tree->setColumnHidden(3,true);
}

//SLOT
void FenetreRechercheAffichageTag::filtrerTag(){
    QString tmp = this->textRechercheTag->text();
    if(tmp.isNull()||tmp.isEmpty()){
        setUpDirTree();
    }else{
        QStringList headers;
        headers << tr("Nom");

        QStringList list= this->gestionnaire->recupererLesFichiers(gestionnaire->getTag(tmp));
        tagmodel = new TagModel(headers, list);
        tree->setModel(tagmodel);
    }
}
