#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = nullptr);
    void clear();
private:
    bool isPressed = false;
    QList<QRect> Rects;
    QPoint curr,temp;
protected:
    void mousePressEvent(QMouseEvent*e)override;
    void mouseMoveEvent(QMouseEvent*e)override;
    void mouseReleaseEvent(QMouseEvent*e)override;
    void paintEvent(QPaintEvent*e)override;

};

#endif // DRAWWIDGET_H
