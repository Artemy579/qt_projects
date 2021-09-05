#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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


    void on_spinBox_textChanged(const QString &arg1);

    void on_spinBox_editingFinished();

    void on_pb_yes_clicked();

    void on_pb_no_clicked();



private:
    Ui::MainWindow *ui;
    int a = 0;
    int b = 2000;
    int c = 0;
};
#endif // MAINWINDOW_H
