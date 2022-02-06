#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QPolygon>
#include <QPalette>
#include <QSize>
#include <QDebug>
#include <QGuiApplication>
#include <QScreen>

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

private slots:
    void timer_timeout();
    void draw_rec();
private:
    Ui::MainWindow *ui;
    QTimer timer;
    QPolygon polygon_base;
};
#endif // MAINWINDOW_H
