#include "delegate.h"
#include <QTextEdit>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QDebug>

Delegate::Delegate(QObject *parent)
    :QItemDelegate(parent)
{

}

QWidget* Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(QString(index.data().typeName()) == "int")
    {
        int row = index.row();
        QModelIndex nameIndex = index.model()->index(row, 0, QModelIndex());
        QString name = (index.model()->data(nameIndex, Qt::EditRole)).toString();
        if(name.endsWith("Color"))
        {
            QSlider *editor = new QSlider(Qt::Horizontal, parent);
            editor->setRange(0, 255);
            return editor;
        }
        else
        {
            QSpinBox *editor = new QSpinBox(parent);
            editor->setRange(-32000, 32000);
            return editor;
        }
    }
    else if(QString(index.data().typeName()) == "QString")
    {
        QTextEdit *editor = new QTextEdit(parent);
        editor->setDisabled(true);
        return editor;
    }
    else if(QString(index.data().typeName()) == "bool")
    {
        QCheckBox *editor = new QCheckBox(parent);
        return editor;
    }
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(QString(index.data().typeName()) == "int")
    {
        int row = index.row();
        QModelIndex nameIndex = index.model()->index(row, 0, QModelIndex());
        QString name = (index.model()->data(nameIndex, Qt::EditRole)).toString();
        int value = (index.model()->data(index, Qt::EditRole)).toInt();
        if(name.endsWith("Color"))
        {
            QSlider *slider = static_cast<QSlider*>(editor);
            slider->setValue(value);
        }
        else
        {
            QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
            spinBox->setValue(value);
        }
    }
    else if(QString(index.data().typeName()) == "QString")
    {
        QString value = (index.model()->data(index, Qt::EditRole)).toString();

        QTextEdit *textEdit = static_cast<QTextEdit*>(editor);
        textEdit->setText(value);
    }
    else if(QString(index.data().typeName()) == "bool")
    {
        bool value = (index.model()->data(index, Qt::EditRole)).toBool();
        QCheckBox *checkBox = static_cast<QCheckBox*>(editor);
        checkBox->setChecked(value);
    }
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(QString(index.data().typeName()) == "int")
    {
        int row = index.row();
        QModelIndex nameIndex = model->index(row, 0, QModelIndex());
        QString name = (index.model()->data(nameIndex, Qt::EditRole)).toString();
        if(name.endsWith("Color"))
        {
            QSlider *slider = static_cast<QSlider*>(editor);
            model->setData(index, slider->value(), Qt::EditRole);
        }
        else
        {
            QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
            spinBox->interpretText();
            model->setData(index, spinBox->value(), Qt::EditRole);
        }
    }
    if(QString(index.data().typeName()) == "QString")
    {
        QTextEdit *textEdit = static_cast<QTextEdit*>(editor);
        model->setData(index, textEdit->toPlainText(), Qt::EditRole);
    }
    if(QString(index.data().typeName()) == "bool")
    {
        QCheckBox *checkBox = static_cast<QCheckBox*>(editor);
        model->setData(index, checkBox->isChecked(), Qt::EditRole);
    }
}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
