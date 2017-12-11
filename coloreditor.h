#ifndef COLOREDITOR_H
#define COLOREDITOR_H

#include <QLabel>

class ColorEditor : public QWidget
{
public:
    ColorEditor(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    QColor Color();
    void setColor(QColor color);
protected:
    void mousePressEvent(QMouseEvent *ev);
    void setBackgroundColor(QColor color);
    QColor color;
};

#endif // COLOREDITOR_H
