#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QProgressBar>
#include <QTimer>
#include <QMainWindow>

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

    void on_pushButton_clicked();

    void progress_bar_start();

private:
    int a = 500;
    int counter = 0;
    QTimer *timer = new QTimer(this);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H