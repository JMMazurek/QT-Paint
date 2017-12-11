#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QComboBox>
#include "myqgraphicsrectitem.h"
#include "myqgraphicsellipseitem.h"
#include "myqgraphicslineitem.h"
#include "myqgraphicspathitem.h"
#include "myqgraphicsfanitem.h"

enum Shape {
    RectangleItem,
    EllipseItem,
    LineItem,
    PathItem,
    FanItem
};

class myQGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    myQGraphicsScene(QObject *parent = nullptr);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
private:
    bool drawing;
    Shape selectedShape;
    myQGraphicsItem *temp;
    myQGraphicsItem *modelHolder;
public slots:
    void changeSelectedShape(int index);
};

#endif // MYQGRAPHICSSCENE_H
