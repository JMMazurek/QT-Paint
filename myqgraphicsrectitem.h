#ifndef MYQGRAPHICSRECTITEM_H
#define MYQGRAPHICSRECTITEM_H

#include <QGraphicsRectItem>
#include<QStandardItemModel>
#include "myqgraphicsitem.h"

class myQGraphicsRectItem : public myQGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(int width READ width WRITE setWidth)
    Q_PROPERTY(int height READ height WRITE setHeight)
public:
    myQGraphicsRectItem(qreal x, qreal y, qreal width, qreal height, QString name, QGraphicsItem *parent = Q_NULLPTR);
    int width();
    void setWidth(int width);
    int height();
    void setHeight(int height);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MYQGRAPHICSRECTITEM_H
