#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent*e)override;
    void mouseMoveEvent(QMouseEvent*e)override;
    void mouseReleaseEvent(QMouseEvent*e)override;
    void paintEvent(QPaintEvent*e)override;

private:
    Ui::MainWindow *ui;
    bool isPressed = false;
    QPoint curr,temp,label_pos_start,label_pos_end;
    QList<QRect> Rects;
};
#endif // MAINWINDOW_H
