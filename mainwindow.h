#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "myqgraphicsrectitem.h"
#include "delegate.h"
#include "coloreditor.h"
#include "myqgraphicsscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    myQGraphicsScene *scene;

public slots:
    void changeModel(QStandardItemModel *model);
};

#endif // MAINWINDOW_H
