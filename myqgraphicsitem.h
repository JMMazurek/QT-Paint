#ifndef MYQGRAPHICSITEM_H
#define MYQGRAPHICSITEM_H

#include <QGraphicsItem>
#include<QStandardItemModel>
#include <QPen>
#include <QGraphicsSceneEvent>
#include <QPainter>


class myQGraphicsItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    Q_PROPERTY(QString typeName READ typeName WRITE setTypeName)
    Q_PROPERTY(int brushRColor READ brushRColor WRITE setBrushRColor)
    Q_PROPERTY(int brushGColor READ brushGColor WRITE setBrushGColor)
    Q_PROPERTY(int brushBColor READ brushBColor WRITE setBrushBColor)
    Q_PROPERTY(int penRColor READ penRColor WRITE setPenRColor)
    Q_PROPERTY(int penGColor READ penGColor WRITE setPenGColor)
    Q_PROPERTY(int penBColor READ penBColor WRITE setPenBColor)
    Q_PROPERTY(int penWidth READ penWidth WRITE setPenWidth)
    Q_PROPERTY(int z READ zValue WRITE setZValue)

public:
    QString typeName();
    void setTypeName(QString typeName);
    void setBrushRColor(int r);
    int brushRColor();
    void setBrushGColor(int g);
    int brushGColor();
    void setBrushBColor(int b);
    int brushBColor();
    void setPenRColor(int r);
    int penRColor();
    void setPenGColor(int g);
    int penGColor();
    void setPenBColor(int b);
    int penBColor();
    void setPenWidth(int w);
    int penWidth();
    virtual void drawing(int x, int y);
    QStandardItemModel *model;
    myQGraphicsItem(qreal x, qreal y, qreal width, qreal height, QString name, QGraphicsItem *parent = Q_NULLPTR);
    void copyModelData(QStandardItemModel *model);
    void select();
    void resetModel();
public slots:
    void modelUpdated(const QModelIndex &index);
protected:
    int sX, sY;
    QVector<QString> properties;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QString name;
signals:
    void selected(QStandardItemModel *model);
};

#endif // MYQGRAPHICSITEM_H
