#include "FenetreRechercheAffichageTag.hpp"
#include <iostream>

FenetreRechercheAffichageTag::FenetreRechercheAffichageTag(GestionnaireDesTags* gest,QWidget *parent) : QWidget(parent){
    //QSplitter *splitterMain = (QSplitter*)parent;
    gestionnaire = gest;
    gridLayout = new QGridLayout();
    QHBoxLayout *layout = new QHBoxLayout;
    this->setLayout(layout);
    layout->addLayout(gridLayout);
    boutonRechercheTag = new QPushButton("Filtrer");
    textRechercheTag = new QLineEdit();
    textRechercheTag->setPlaceholderText("Entrez le ou les tag(s) pour filtrer les fichiers");
    boutonclear_filter = new QPushButton("Effacer");
    boutonclear_filter->setEnabled(false);
    deselectionTree = new QPushButton("Tout déselectionner");
    gridLayout->addWidget(textRechercheTag,0,0,1,3);
    gridLayout->addWidget(boutonRechercheTag,0,3,1,1);
    gridLayout->addWidget(deselectionTree,2,0,1,1);
    tags_filter = new QLabel();
    gridLayout->addWidget(tags_filter,1,0,1,3);
    gridLayout->addWidget(boutonclear_filter,1,3,1,1);
    tags_filter->hide();
    directory = new QDirModel(parent);
    tree = new QTreeView();
    tree->setSelectionMode( QAbstractItemView::MultiSelection );
    setUpDirTree();

    contextMenu = new QMenu(tree);
    contextMenu->addAction("Ouvrir", this, SLOT(ouvrirFichier()));
    contextMenu->addAction("enlever tags", this, SLOT(enleverTags()));
    tree->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(tree, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onCustomContextMenu(const QPoint &)));



    gridLayout->addWidget(tree,3,0,7,4);

    active_tag = new QVector<Tag*>();

    completer = new QCompleter(gestionnaire->listeDesNomTags(), this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    textRechercheTag->setCompleter(completer);

    fenetreDetagger = new FenetreDetaggerFichier();

    connect(textRechercheTag, SIGNAL(returnPressed()), this , SLOT(filtrerTag_onclick()));
    connect(boutonRechercheTag, SIGNAL(clicked()), this , SLOT(filtrerTag_onclick()));
    connect(deselectionTree, SIGNAL(clicked()), this , SLOT(tout_deselectionner()));
    connect(boutonclear_filter, SIGNAL(clicked()), this , SLOT(clearfilter_onclick()));
}

FenetreRechercheAffichageTag::~FenetreRechercheAffichageTag(){

}

void FenetreRechercheAffichageTag::setUpDirTree(){
    isDirModel = true;
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
        tags_filter->setText("Tag : "+active_tag->at(0)->getNom());
        tags_filter->show();
        return liste;
    }else{
        QVectorIterator<Tag*> i(*active_tag);
        QSet<QString> intersection = liste.toSet();
        QString filter = "Tags : ";
        while (i.hasNext()){
            Tag* t = i.next();
            filter.append(t->getNom()+" ");
            intersection = intersection.intersect(this->gestionnaire->recupererLesFichiers(t).toSet());
        }
        tags_filter->setText(filter);
        tags_filter->show();
        return intersection.toList();
    }
    return liste;
}

//SLOT
void FenetreRechercheAffichageTag::filtrerTag_onclick(){
    QString tmp = this->textRechercheTag->text();
    if(!tmp.isNull()&&!tmp.isEmpty()){
        Tag *tag = gestionnaire->getTag(tmp);
        if(tag != NULL){
            if(!active_tag->contains(tag)){
                active_tag->append(tag);
                QStringList list= filtrerTag();
                QStringList headers;
                headers << tr("Nom");
                tagmodel = new TagModel(headers, list);
                tree->setModel(tagmodel);
                boutonclear_filter->setEnabled(true);
                isDirModel = false;
            }
        }else{
            QMessageBox msgBox;
            msgBox.setText("Tag inconnu");
            msgBox.exec();
            setUpDirTree();
        }
        textRechercheTag->clear();
    }


}

void FenetreRechercheAffichageTag::clearfilter_onclick(){
    active_tag->clear();
    tags_filter->setText("");
    tags_filter->hide();
    boutonclear_filter->setEnabled(false);
    setUpDirTree();

}


QStringList FenetreRechercheAffichageTag::recupererSelection(){
    QStringList laliste;
    QModelIndexList selection = tree->selectionModel()->selectedRows();
    if(isDirModel){
        for (int i = 0; i < selection.size(); i++){
            laliste.append(directory->filePath(selection[i]));
        }
    }else{
        for (int i = 0; i < selection.size(); i++){
            laliste.append(selection[i].data().toString());
        }
    }

    return laliste;
}

void FenetreRechercheAffichageTag::tout_deselectionner(){
    tree->clearSelection();
}

QTreeView* FenetreRechercheAffichageTag::getTreeView(){
    return tree;
}

void FenetreRechercheAffichageTag::onCustomContextMenu(const QPoint &point)
{
    contextMenu->exec(tree->mapToGlobal(point));
}

void FenetreRechercheAffichageTag::ouvrirFichier(){
    QStringList fichiers = recupererSelection();

    for(int i=0;i<fichiers.size();i++){
        QDesktopServices::openUrl(QUrl(fichiers.at(i)));
    }
}

void FenetreRechercheAffichageTag::enleverTags(){
    QStringList fichiers = recupererSelection();

    fenetreDetagger->genererFenetre(fichiers);



}
