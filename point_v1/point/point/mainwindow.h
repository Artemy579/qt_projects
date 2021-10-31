#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QRadioButton>
#include <QBoxLayout>
#include <QTimer>
#include <QVector>

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
    void spinbox_value_changed(int value);

    void add_radiobutton(unsigned count, QBoxLayout* l);

    void remove_radiobutton(unsigned count, QBoxLayout* l);

    void time_out();
private:
    Ui::MainWindow *ui;
     QTimer timer;
     QVector<QRadioButton*> vector;
     int rb_idx = 0;
};
#endif // MAINWINDOW_H
