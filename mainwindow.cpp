#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dw = new DrawWidget(this);
    dw->setGeometry(20,10,1140,870);
    dw->show();

    connect(ui->pushButton,&QPushButton::clicked,this,[this]{
        dw->clear();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
