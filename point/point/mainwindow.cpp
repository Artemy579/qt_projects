#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start_program(){
    a = ui->spinBox->value();
    for (int i = 0; i < a; i++) {
        QRadioButton *button = new QRadioButton(this);
        button->setGeometry(b,10,10,10);
        button->show();
        b += 20;
    }
}

void MainWindow::on_pushButton_clicked()
{
    start_program();
}

