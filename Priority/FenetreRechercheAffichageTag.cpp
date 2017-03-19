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

    active_tag = new QVector<Tag*>();

    connect(textRechercheTag, SIGNAL(returnPressed()), this , SLOT(filtrerTag_onclick()));
    connect(boutonRechercheTag, SIGNAL(clicked()), this , SLOT(filtrerTag_onclick()));
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


QStringList FenetreRechercheAffichageTag::filtrerTag(){
    QStringList liste = this->gestionnaire->recupererLesFichiers(active_tag->at(0));
    if(active_tag->size()==1){
        return liste;
    }else{
        QVectorIterator<Tag*> i(*active_tag);
        QSet<QString> intersection = liste.toSet();
        while (i.hasNext()){
            intersection = intersection.intersect(this->gestionnaire->recupererLesFichiers(i.next()).toSet());
        }
        return intersection.toList();
    }
    return liste;
}

//SLOT
void FenetreRechercheAffichageTag::filtrerTag_onclick(){
    QString tmp = this->textRechercheTag->text();
    if(tmp.isNull()||tmp.isEmpty()){
        active_tag->clear();
        setUpDirTree();
    }else{
        Tag *tag = gestionnaire->getTag(tmp);
        if(tag != NULL){
            active_tag->append(tag);
            QStringList list= filtrerTag();
            QStringList headers;
            headers << tr("Nom");
            tagmodel = new TagModel(headers, list);
            tree->setModel(tagmodel);
        }else{
            QMessageBox msgBox;
            msgBox.setText("Tag inconnu");
            msgBox.exec();
            setUpDirTree();
        }
    }
}
