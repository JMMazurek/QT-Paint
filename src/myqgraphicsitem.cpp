#include "myqgraphicsitem.h"
#include <QDebug>

myQGraphicsItem::myQGraphicsItem(qreal x, qreal y, qreal width, qreal height, QString name, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, width, height, parent)
{
    model = new QStandardItemModel(this);
    setFlags(ItemIsMovable);
    sX = x;
    sY = y;

    this->name = name;

    properties.push_back("typeName");
    properties.push_back("brushRColor");
    properties.push_back("brushGColor");
    properties.push_back("brushBColor");
    properties.push_back("penRColor");
    properties.push_back("penGColor");
    properties.push_back("penBColor");
    properties.push_back("penWidth");
    properties.push_back("z");

    resetModel();
}

void myQGraphicsItem::resetModel()
{
    model->clear();
    model->setColumnCount(2);
    model->setRowCount(properties.size());

    for(int i = 0; i < properties.size(); i++)
    {
        QModelIndex nameIndex = model->index(i, 0, QModelIndex());
        QModelIndex valueIndex = model->index(i, 1, QModelIndex());

        QByteArray array = properties.at(i).toUtf8();
        char* nameChar = array.data();

        model->setData(nameIndex, properties.at(i));
        model->setData(valueIndex, property(nameChar));
    }
    connect(model, SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)),
            this, SLOT(modelUpdated(QModelIndex)));
}

void myQGraphicsItem::modelUpdated(const QModelIndex &index)
{
    int row = index.row();
    QModelIndex nameIndex = model->index(row, 0, QModelIndex());
    QString name = (index.model()->data(nameIndex, Qt::EditRole)).toString();
    QVariant value = index.model()->data(index, Qt::EditRole);

    QByteArray array = name.toUtf8();
    char* nameChar = array.data();
    setProperty(nameChar, value);
}

void myQGraphicsItem::copyModelData(QStandardItemModel *model)
{
    int rows = model->rowCount();
    for(int row = 0; row < rows; row++)
    {
        QModelIndex nameIndex = model->index(row, 0, QModelIndex());
        QModelIndex valueIndex = model->index(row, 1, QModelIndex());
        QString name = model->data(nameIndex, Qt::EditRole).toString();
        QVariant value = model->data(valueIndex, Qt::EditRole);
        QByteArray array = name.toUtf8();
        char* nameChar = array.data();
        setProperty(nameChar, value);
    }

    resetModel();
}

QString myQGraphicsItem::typeName()
{
    return name;
}

void myQGraphicsItem::setTypeName(QString typeName)
{
    //name = typeName;
}

void myQGraphicsItem::select()
{
    emit selected(model);
}

void myQGraphicsItem::setBrushRColor(int r)
{
    QColor color = brush().color();
    color.setRed(r);
    setBrush(QBrush(color));
}

int myQGraphicsItem::brushRColor()
{
    QColor color = brush().color();
    return color.red();
}

void myQGraphicsItem::setBrushGColor(int g)
{
    QColor color = brush().color();
    color.setGreen(g);
    setBrush(QBrush(color));
}

int myQGraphicsItem::brushGColor()
{
    QColor color = brush().color();
    return color.green();
}

void myQGraphicsItem::setBrushBColor(int b)
{
    QColor color = brush().color();
    color.setBlue(b);
    setBrush(QBrush(color));
}

int myQGraphicsItem::brushBColor()
{
    QColor color = brush().color();
    return color.blue();
}

void myQGraphicsItem::setPenRColor(int r)
{
    QPen newPen(pen());
    QColor color = newPen.color();
    color.setRed(r);
    newPen.setColor(color);
    setPen(newPen);
}

int myQGraphicsItem::penRColor()
{
    QColor color = pen().color();
    return color.red();
}

void myQGraphicsItem::setPenGColor(int g)
{
    QPen newPen(pen());
    QColor color = newPen.color();
    color.setGreen(g);
    newPen.setColor(color);
    setPen(newPen);
}

int myQGraphicsItem::penGColor()
{
    QColor color = pen().color();
    return color.green();
}

void myQGraphicsItem::setPenBColor(int b)
{
    QPen newPen(pen());
    QColor color = newPen.color();
    color.setBlue(b);
    newPen.setColor(color);
    setPen(newPen);
}

int myQGraphicsItem::penBColor()
{
    QColor color = pen().color();
    return color.blue();
}

void myQGraphicsItem::setPenWidth(int w)
{
    QPen newPen(pen());
    newPen.setWidth(w);
    setPen(newPen);
}

int myQGraphicsItem::penWidth()
{
    return pen().width();
}

void myQGraphicsItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    emit selected(model);
}

void myQGraphicsItem::drawing(int x1, int y1)
{
    int x, y, h, w;
    x = x1 < sX ? x1 : sX;
    y = y1 < sY ? y1 : sY;
    h = abs(y1 - sY);
    w = abs(x1 - sX);
    this->setRect(0, 0, w, h);
    this->setPos(x, y);
}

void myQGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->setBrush(brush());
    painter->drawRect(rect());
}
