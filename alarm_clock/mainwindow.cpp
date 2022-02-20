#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this,  SLOT(timer_start()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(push_button_clicked()));
    ui->lcdNumber->setDigitCount(16);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::push_button_clicked(){
    timer.start(100);
    hours = ui->spinBox_hours->value();
    min = ui->spinBox_min->value();
    sec = ui->spinBox_sec->value();
    mil_sec = ui->spinBox_mil_sec->value();
    ui->spinBox_sec->setDisplayIntegerBase(100);
    timeout = mil_sec + sec * 1000 + min * 1000*60 + hours *1000*60;//ui->spinBox_mil_sec->value();

    string1 = QString::number(hours)+ ":" + QString::number(min) +  ":" + QString::number(sec) + ":" + QString::number(mil_sec);

    elapsed_timer.start();
    timer.start(1);


    if(remaining_time == 0){
        ui->lcdNumber->display(--sec);

    }
}

void MainWindow::timer_start(){
    remaining_time = timeout - elapsed_timer.elapsed();
    if (remaining_time <= 0){
        timer.stop();
        return;
    }
    --mil_sec;
    if(mil_sec == 0){
        --sec;
        mil_sec = 999;
    }

    if(sec == 0){
        --min;
        sec = 60;
    }

    if(min == 0){
        --hours;
        min = 60;
    }

    string1 = QString::number(hours)+ ":" + QString::number(min)  +  ":" + QString::number(sec) + ":" + QString::number(mil_sec);
    ui->lcdNumber->display(string1);

}


