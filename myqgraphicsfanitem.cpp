#include "myqgraphicsfanitem.h"
#include <QStyleOptionGraphicsItem>
#include <QDebug>

myQGraphicsFanItem::myQGraphicsFanItem(qreal x, qreal y, qreal width, qreal height, QString name, QGraphicsItem *parent)
    : myQGraphicsItem(x, y, width, height, name, parent)
{
    minX = maxX = x;
    minY = maxY = y;
    properties.push_back("oddEvenFill");
    resetModel();
}

void myQGraphicsFanItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->setBrush(brush());
    painter->drawPath(path);
}

void myQGraphicsFanItem::drawing(int x1, int y1)
{
    int h, w;
    int offX = 0;
    int offY = 0;
    if(x1 > maxX)
        maxX = x1;
    if(y1 > maxY)
        maxY = y1;
    if(x1 < minX)
    {
        offX = x1 - minX;
        minX = x1;
    }
    if(y1 < minY)
    {
        offY = y1 - minY;
        minY = y1;
    }
    path.translate(-offX, -offY);
    h = maxY - minY;
    w = maxX - minX;
    this->setRect(0, 0, w, h);
    this->setPos(minX, minY);
    path.lineTo(x1-minX, y1-minY);
}

void myQGraphicsFanItem::setOddEvenFill(bool fill)
{
    if(fill)
        path.setFillRule(Qt::OddEvenFill);
    else
        path.setFillRule(Qt::WindingFill);
}

bool myQGraphicsFanItem::oddEvenFill()
{
    return path.fillRule() == Qt::OddEvenFill;
}
