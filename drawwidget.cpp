#include "drawwidget.h"

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{

}

void DrawWidget::clear()
{
    Rects.clear();
}

void DrawWidget::mousePressEvent(QMouseEvent *e)
{
    isPressed = true;
    curr.setX(e->pos().x());
    curr.setY(e->pos().y());
    temp.setX(e->pos().x());
    temp.setY(e->pos().y());
}

void DrawWidget::mouseMoveEvent(QMouseEvent *e)
{
    temp.setX(e->pos().x());
    temp.setY(e->pos().y());
}

void DrawWidget::mouseReleaseEvent(QMouseEvent *e)
{
    isPressed = false;
    Rects.push_back(QRect(curr.x(),curr.y(),temp.x()-curr.x(),temp.y()-curr.y()));
}

void DrawWidget::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.setPen(Qt::SolidLine);

    p.setPen(QColor(0,0,0));
    p.drawRect(QRect(0,0,width()-1,height()-1));

    p.setPen(QColor(255,0,0));
    for(int i=0;i<Rects.size();i++){
        p.drawRect(Rects[i]);
    }

    if(isPressed){
        p.drawRect(QRect(curr.x(),curr.y(),temp.x()-curr.x(),temp.y()-curr.y()));
    }
    update();
}
