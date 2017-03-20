#ifndef TAGMODEL_H
#define TAGMODEL_H


#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

class TagItem;

/**
 * @brief The TagModel Le modele de donnée utilisé par la TreeView
 */
class TagModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    TagModel(const QStringList &headers, const QStringList data,
              QObject *parent = 0);
    ~TagModel();

    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    bool setHeaderData(int section, Qt::Orientation orientation,
                       const QVariant &value, int role = Qt::EditRole) override;

    bool insertColumns(int position, int columns,
                       const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int position, int columns,
                       const QModelIndex &parent = QModelIndex()) override;
    bool insertRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex()) override;

private:
    void setupModelData(const QStringList &lines, TagItem *parent);
    TagItem *getItem(const QModelIndex &index) const;

    TagItem *rootItem;
};


#endif // TAGMODEL_H