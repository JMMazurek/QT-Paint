#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new myQGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->tableView->setItemDelegate(new Delegate(this));

    ui->comboBox->addItem("Rectangle", RectangleItem);
    ui->comboBox->addItem("Ellipse", EllipseItem);
    ui->comboBox->addItem("Line", LineItem);
    ui->comboBox->addItem("Path", PathItem);
    ui->comboBox->addItem("Fan", FanItem);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), scene, SLOT(changeSelectedShape(int)));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeModel(QStandardItemModel *model)
{
    if(ui->tableView->model() != model)
        ui->tableView->setModel(model);
}
