#ifndef MYQGRAPHICSFANITEM_H
#define MYQGRAPHICSFANITEM_H


#include <QPainterPath>
#include "myqgraphicsitem.h"

class myQGraphicsFanItem : public myQGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(bool oddEvenFill READ oddEvenFill WRITE setOddEvenFill);
public:
    myQGraphicsFanItem(qreal x, qreal y, qreal width, qreal height, QString name, QGraphicsItem *parent = Q_NULLPTR);
    void drawing(int x1, int y1);
    bool oddEvenFill();
    void setOddEvenFill(bool fill);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath path;
    int minX, minY, maxX, maxY;
};

#endif // MYQGRAPHICSFANITEM_H
