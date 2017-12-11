#ifndef MYQGRAPHICSLINEITEM_H
#define MYQGRAPHICSLINEITEM_H

#include "myqgraphicsitem.h"

class myQGraphicsLineItem : public myQGraphicsItem
{
    Q_OBJECT
public:
    myQGraphicsLineItem(qreal x, qreal y, qreal width, qreal height, QString name, QGraphicsItem *parent = Q_NULLPTR);
    void drawing(int x1, int y1);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool s;
};

#endif // MYQGRAPHICSLINEITEM_H
