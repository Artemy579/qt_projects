#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QRadioButton>
#include <QBoxLayout>
#include <QTimer>

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
    void start_program();

    void spinbox_value_changed(int value);

    void add_radiobutton(unsigned count, QBoxLayout* l);

    void remove_radiobutton(unsigned count, QBoxLayout* l);
private:
    Ui::MainWindow *ui;
     QTimer timer;
};
#endif // MAINWINDOW_H
