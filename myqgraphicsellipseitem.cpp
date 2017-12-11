#include "myqgraphicsellipseitem.h"


myQGraphicsEllipseItem::myQGraphicsEllipseItem(qreal x, qreal y, qreal width, qreal height, QString name, QGraphicsItem *parent)
    : myQGraphicsItem(x, y, width, height, name, parent)
{
    properties.push_back("r1");
    properties.push_back("r2");
    resetModel();
}

void myQGraphicsEllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->setBrush(brush());
    painter->drawEllipse(rect());
}

int myQGraphicsEllipseItem::r1()
{
    return rect().height()/2;
}

void myQGraphicsEllipseItem::setR1(int r1)
{
    QRectF newRect = rect();
    newRect.setHeight(r1*2);
    setRect(newRect);
}

int myQGraphicsEllipseItem::r2()
{
    return rect().width()/2;
}

void myQGraphicsEllipseItem::setR2(int r2)
{
    QRectF newRect = rect();
    newRect.setWidth(r2*2);
    setRect(newRect);
}
