#include "coloreditor.h"
#include <QColorDialog>

ColorEditor::ColorEditor(QWidget *parent, Qt::WindowFlags f)
    :QWidget(parent, f)
{
    color.setRgb(100, 100, 100);
    setAutoFillBackground(true);
    setBackgroundColor(color);
}

void ColorEditor::mousePressEvent(QMouseEvent *ev)
{
    color = QColorDialog::getColor(color);
    /*emit commitData(this);
    emit closeEditor(this);*/
    //setBackgroundColor(color);
}

QColor ColorEditor::Color()
{
    return color;
}

void ColorEditor::setColor(QColor color)
{
    this->color = color;
    setBackgroundColor(color);
}

void ColorEditor::setBackgroundColor(QColor color)
{
    QPalette palette(palette());
    palette.setColor(backgroundRole(), color);
    palette.setColor(foregroundRole(), color);
    setPalette(palette);
}
