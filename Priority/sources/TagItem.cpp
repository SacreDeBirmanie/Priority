/*
    TagItem.cpp

    A container for items of data supplied by the simple tree model.
*/

#include "headers/TagItem.hpp"

#include <QStringList>

TagItem::TagItem(const QVector<QVariant> &data, TagItem *parent)
{
    parentItem = parent;
    itemData = data;
}

TagItem::~TagItem()
{
    qDeleteAll(childItems);
}

TagItem *TagItem::child(int number)
{
    return childItems.value(number);
}

int TagItem::childCount() const
{
    return childItems.count();
}

int TagItem::childNumber() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<TagItem*>(this));

    return 0;
}

int TagItem::columnCount() const
{
    return itemData.count();
}

QVariant TagItem::data(int column) const
{
    return itemData.value(column);
}

bool TagItem::insertChildren(int position, int count, int columns)
{
    if (position < 0 || position > childItems.size())
        return false;

    for (int row = 0; row < count; ++row) {
        QVector<QVariant> data(columns);
        TagItem *item = new TagItem(data, this);
        childItems.insert(position, item);
    }

    return true;
}

bool TagItem::insertColumns(int position, int columns)
{
    if (position < 0 || position > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.insert(position, QVariant());

    foreach (TagItem *child, childItems)
        child->insertColumns(position, columns);

    return true;
}

TagItem *TagItem::parent()
{
    return parentItem;
}

bool TagItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > childItems.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete childItems.takeAt(position);

    return true;
}

bool TagItem::removeColumns(int position, int columns)
{
    if (position < 0 || position + columns > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.remove(position);

    foreach (TagItem *child, childItems)
        child->removeColumns(position, columns);

    return true;
}

bool TagItem::setData(int column, const QVariant &value)
{
    if (column < 0 || column >= itemData.size())
        return false;

    itemData[column] = value;
    return true;
}
