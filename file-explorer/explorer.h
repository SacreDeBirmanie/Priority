#ifndef EXPLORER_H
#define EXPLORER_H
#include <QDialog>
#include <QtCore>
#include <QtGui>

class Explorer : public QDialog
{
    Q_OBJECT

public:
    explicit Explorer(QWidget *parent = 0);
    ~Explorer();

private:
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;


private slots:
    void on_treeView_clicked(QModelIndex index);
};

#endif // EXPLORER_H
