#ifndef MYQGRAPHICSPATHITEM_H
#define MYQGRAPHICSPATHITEM_H

#include <QPainterPath>
#include "myqgraphicsitem.h"

class myQGraphicsPathItem : public myQGraphicsItem
{
    Q_OBJECT
public:
    myQGraphicsPathItem(qreal x, qreal y, qreal width, qreal height, QString name, QGraphicsItem *parent = Q_NULLPTR);
    void drawing(int x1, int y1);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath path;
    int minX, minY, maxX, maxY;
};
#endif // MYQGRAPHICSPATHITEM_H
