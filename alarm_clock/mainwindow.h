#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLCDNumber>
#include <QElapsedTimer>

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
    void timer_start();
    void push_button_clicked();

private:
    Ui::MainWindow *ui;
    qint16 hours, min, sec, mil_sec = 0;
    int remaining_time = 0;
    int timeout = 0;
    QTimer timer;
    QElapsedTimer elapsed_timer;
    QString string1;
};
#endif // MAINWINDOW_H
