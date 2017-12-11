#ifndef MYQGRAPHICSELLIPSEITEM_H
#define MYQGRAPHICSELLIPSEITEM_H

#include "myqgraphicsitem.h"

class myQGraphicsEllipseItem : public myQGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(int r1 READ r1 WRITE setR1)
    Q_PROPERTY(int r2 READ r2 WRITE setR2)
public:
    myQGraphicsEllipseItem(qreal x, qreal y, qreal width, qreal height, QString name, QGraphicsItem *parent = Q_NULLPTR);
    int r1();
    void setR1(int r1);
    int r2();
    void setR2(int r2);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); myQGraphicsEllipseItem();
};

#endif // MYQGRAPHICSELLIPSEITEM_H
