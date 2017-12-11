#include "myqgraphicslineitem.h"
#include <QStyleOptionGraphicsItem>
#include <QDebug>

myQGraphicsLineItem::myQGraphicsLineItem(qreal x, qreal y, qreal width, qreal height, QString name, QGraphicsItem *parent)
    : myQGraphicsItem(x, y, width, height, name, parent)
{
    s = true;
}

void myQGraphicsLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->setBrush(brush());
    //painter->drawLine(0, 0, eX, eY);
    QRect rect = option->rect;
    if(s)
        painter->drawLine(rect.topLeft(), rect.bottomRight());
    else
          painter->drawLine(rect.topRight(), rect.bottomLeft());
}

void myQGraphicsLineItem::drawing(int x1, int y1)
{
    myQGraphicsItem::drawing(x1, y1);
    s = (x1 > sX && y1 > sY) || (x1 < sX && y1 < sY);
}
