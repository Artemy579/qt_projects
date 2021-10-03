#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(progress_bar_start()));
    ld = Qt::RightToLeft;
    o = Qt::Vertical;
    step = 1;
    state_number = max_state_number;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::progress_bar_start(){
    if (ui->progressBar->value() == 0){
        next_state();
        ui->progressBar->setLayoutDirection(ld);
        ui->progressBar->setOrientation(o);
    }
    ui->progressBar->setValue(ui->progressBar->value() + step);

    switch (o){
    case Qt::Vertical:
        setFixedHeight(height() + step);
        break;
    case Qt::Horizontal:
        setFixedWidth(width() + step);
        break;
    }

    if(ui->progressBar->value() == ui->progressBar->maximum())
        step = -1;
}

void MainWindow::next_state(){
    step = 1;
    switch(state_number){
    case 0:
        ld = Qt::RightToLeft;
        o = Qt::Horizontal;
        break;
    case 1:
        ld = Qt::LeftToRight;
        o = Qt::Vertical;
        break;
    case 2:
        ld = Qt::RightToLeft;
        o = Qt::Vertical;
        break;
    case 3:
        ld = Qt::LeftToRight;
        o = Qt::Horizontal;
        break;
    }

    ++state_number;
    state_number &= 0x3;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton->text() == "Начать"){
        timer.start(20);
        ui->pushButton->setText("Отмена");

    }
    else{
        timer.stop();
        ui->pushButton->setText("Начать");
    }
}



