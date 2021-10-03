#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    progress_bar_start();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::progress_bar_start(){
    connect(timer, SIGNAL(timeout()), this, SLOT(progress_bar_start()));
    timer->start(150);
    if(counter <= 100){
        counter += 1;
        ui->progressBar->setValue(counter);
    }
}



void MainWindow::on_pushButton_clicked()
{

}



