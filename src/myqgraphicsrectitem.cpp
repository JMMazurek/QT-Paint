#include "myqgraphicsrectitem.h"
#include <QDebug>

myQGraphicsRectItem::myQGraphicsRectItem(qreal x, qreal y, qreal width, qreal height, QString name, QGraphicsItem *parent)
    : myQGraphicsItem(x, y, width, height, name, parent)
{
    properties.push_back("width");
    properties.push_back("height");
    resetModel();
}

void myQGraphicsRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->setBrush(brush());
    painter->drawRect(rect());
}

int myQGraphicsRectItem::width()
{
    return rect().width();
}

void myQGraphicsRectItem::setWidth(int width)
{
    QRectF newRect = rect();
    newRect.setWidth(width);
    setRect(newRect);
}

int myQGraphicsRectItem::height()
{
    return rect().height();
}

void myQGraphicsRectItem::setHeight(int height)
{
    QRectF newRect = rect();
    newRect.setHeight(height);
    setRect(newRect);
}
