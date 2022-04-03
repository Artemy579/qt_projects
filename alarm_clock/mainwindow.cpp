#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this,  SLOT(timer_start()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(push_button_clicked()));
    connect(ui->pushButton_stop, SIGNAL(clicked()), this, SLOT(button_stop()));
    ui->lcdNumber->setDigitCount(16);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::push_button_clicked(){
    timer.start(100);
    const quint16 hours = ui->spinBox_hours->value();
    const quint16 min = ui->spinBox_min->value();
    const quint16 sec = ui->spinBox_sec->value();
    const quint16 mil_sec = ui->spinBox_mil_sec->value();
    ui->spinBox_sec->setDisplayIntegerBase(2);
    timeout = mil_sec + sec * 1000 + min * 1000*60 + hours *1000*60*60;

    string1 = QString::number(hours)+ ":" + QString::number(min) +  ":" + QString::number(sec) + ":" + QString::number(mil_sec);

    elapsed_timer.start();
    timer.start(1);
}

void MainWindow::timer_start(){
    int remaining_time = timeout - elapsed_timer.elapsed();
    if (remaining_time <= 0){
        timer.stop();
        string1 = QString::asprintf("%2u:% %2u:% %3u:%", 0, 0, 0, 0);
         ui->lcdNumber->display(string1);
        return;
    }
    const quint16 hours = remaining_time / (1000*60*60);
    remaining_time = remaining_time % (1000*60*60);

    const quint16 min = remaining_time / (1000*60);
    remaining_time = remaining_time % (1000*60);

    const quint16 sec = remaining_time / 1000;
    remaining_time = remaining_time % 1000;

    const quint16 mil_sec = remaining_time;

    string1 = QString::asprintf("%2u:%2u:%2u:%3u", hours, min, sec, mil_sec);
     ui->lcdNumber->display(string1);



}

void MainWindow::button_stop(){
    timer.stop();
    ui->lcdNumber->display(0);
    return;
}
