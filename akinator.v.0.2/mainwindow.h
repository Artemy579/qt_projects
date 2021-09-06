#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void next_attempt();
private slots:
    void pushButton_clicked();
    void try_to_guess();
private:
    Ui::MainWindow *ui;
    int a = 0;
    int b = 2000;
    int c = 0;
    int n = 0;
    QMessageBox *msg_box;
    QPushButton *pb_less;
    QPushButton *pb_greater;
    QPushButton *pb_thats_it;
    QPushButton *pb_terminate;

    void create_msg_box();

};
#endif // MAINWINDOW_H
