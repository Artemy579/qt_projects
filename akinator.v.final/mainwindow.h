#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QDebug>
#include <QRandomGenerator>

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
    void next_attempt(bool gen_new_nmb = true);
private slots:
    void pushButton_clicked();
    void try_to_guess(bool gen_new_nmb);
private:
    Ui::MainWindow *ui;
    int a = 0;//Все числа меньше данного уже проверены
    int b = 2000;//Все числа больше данного уже проверены
    int c = 0;//Проверяемое число
    int n = 0;//Количество попыток

    QMessageBox *msg_box;
    QPushButton *pb_less;
    QPushButton *pb_greater;
    QPushButton *pb_thats_it;
    QPushButton *pb_terminate;

    void create_msg_box();

};
#endif // MAINWINDOW_H
