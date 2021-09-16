#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    label_pos_start = ui->label->pos();
    label_pos_end.setX(ui->label->width() + label_pos_start.x());
    label_pos_end.setY(ui->label->height() + label_pos_start.y());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    curr.setX(e->pos().x());
    curr.setY(e->pos().y());
    temp.setX(e->pos().x());
    temp.setY(e->pos().y());

    if(e->pos().x()<label_pos_start.x() || e->pos().x()>label_pos_end.x() ||
            e->pos().y()<label_pos_start.y() || e->pos().y()>label_pos_end.y())
    {}
    else{
        isPressed = true;
        curr.setX(e->pos().x());
        curr.setY(e->pos().y());
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(isPressed &&
            (e->pos().x()>label_pos_start.x() && e->pos().x()<label_pos_end.x() &&
             e->pos().y()>label_pos_start.y() && e->pos().y()<label_pos_end.y())
      ){
        temp.setX(e->pos().x());
        temp.setY(e->pos().y());
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    isPressed = false;
    Rects.push_back(QRect(curr.x(),curr.y(),temp.x()-curr.x(),temp.y()-curr.y()));
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.setPen(Qt::SolidLine);
    p.setPen(QColor(255,0,0));

    for(int i=0;i<Rects.size();i++){
        p.drawRect(Rects[i]);
    }

    if(isPressed){
        p.drawRect(QRect(curr.x(),curr.y(),temp.x()-curr.x(),temp.y()-curr.y()));
    }
    update();
}

