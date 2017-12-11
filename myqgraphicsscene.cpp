#include "myqgraphicsscene.h"
#include <QDebug>

myQGraphicsScene::myQGraphicsScene(QObject *parent)
    :QGraphicsScene(parent)
{
    drawing = false;
    temp = nullptr;
    modelHolder = new myQGraphicsItem(0, 0, 0, 0, "Settings");
    connect(modelHolder, SIGNAL(selected(QStandardItemModel*)), this->parent(), SLOT(changeModel(QStandardItemModel*)));
    modelHolder->select();
    selectedShape = RectangleItem;
}

void myQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem *item = itemAt(event->scenePos(), QTransform());
    if(event->button() == Qt::LeftButton)
    {
        if(!item)
        {
            drawing = true;
            int x = event->scenePos().x();
            int y = event->scenePos().y();
            myQGraphicsItem *newItem;
            switch(selectedShape)
            {
                case RectangleItem: newItem = new myQGraphicsRectItem(x, y, 0, 0, "Rectangle"); break;
                case EllipseItem:  newItem = new myQGraphicsEllipseItem(x, y, 0, 0, "Ellipse"); break;
                case LineItem:  newItem = new myQGraphicsLineItem(x, y, 0, 0, "Line"); break;
                case PathItem:  newItem = new myQGraphicsPathItem(x, y, 0, 0, "Path"); break;
                case FanItem:  newItem = new myQGraphicsFanItem(x, y, 0, 0, "Fan"); break;
            }

            connect(newItem, SIGNAL(selected(QStandardItemModel*)), this->parent(), SLOT(changeModel(QStandardItemModel*)));
            newItem->copyModelData(modelHolder->model);
            newItem->select();
            this->addItem(newItem);
            temp = newItem;
        }
    }
    else if(event->button() == Qt::RightButton)
    {
        modelHolder->select();
        if(item)
        {
           removeItem(item);
        }
    }
    QGraphicsScene::mousePressEvent(event);
}

void myQGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(drawing)
    {
        int x = event->scenePos().x();
        int y = event->scenePos().y();
        temp->drawing(x, y);
        temp->select();
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void myQGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(drawing)
    {
        drawing = false;
        temp->resetModel();
        temp = nullptr;
    }
    QGraphicsScene::mouseReleaseEvent(event);
}

void myQGraphicsScene::changeSelectedShape(int index)
{
    QComboBox *combo = qobject_cast<QComboBox*>(sender());
    selectedShape = (Shape)combo->itemData(index).toInt();
}

