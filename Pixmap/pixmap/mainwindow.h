#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QBitmap>
#include <QPalette>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QTimer>
#include <QCursor>
#include <math.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setFormStyle();

private slots:
    void bt_change();
    void timer_timeout();
private:
    Ui::MainWindow *ui;
    QPixmap img_paw, img_close_bt, img_close_bt_pressed;
    QTimer timer;
protected:
    void mouseMoveEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
