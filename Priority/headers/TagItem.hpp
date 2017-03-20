#ifndef TAGITEM_H
#define TAGITEM_H
#include <QList>
#include <QVariant>
#include <QVector>

/**
 * @brief The TagItem Définition d'un tag pour la TreeView
 */
class TagItem
{
public:
    explicit TagItem(const QVector<QVariant> &data, TagItem *parent = 0);
    ~TagItem();

    TagItem *child(int number);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    bool insertChildren(int position, int count, int columns);
    bool insertColumns(int position, int columns);
    TagItem *parent();
    bool removeChildren(int position, int count);
    bool removeColumns(int position, int columns);
    int childNumber() const;
    bool setData(int column, const QVariant &value);

private:
    QList<TagItem*> childItems;
    QVector<QVariant> itemData;
    TagItem *parentItem;
};
#endif // TAGITEM_H
