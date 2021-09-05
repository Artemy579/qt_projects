#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pb_yes->hide();
    ui->pb_no->hide();
    ui->label_2->hide();
    ui->label_3->hide();
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_spinBox_textChanged(const QString &arg1)
{
    ui->spinBox->setRange(1, 2000);
    a = ui->spinBox->text().toUInt();
    c = a;

}


void MainWindow::on_spinBox_editingFinished()
{

    ui->pb_yes->show();
    ui->pb_no->show();
    ui->label_3->setText("Ваше число больше 1999?");
    ui->label_3->show();
    void on_pb_yes_clicked();
    ui->label_2->show();
}



void MainWindow::on_pb_no_clicked()
{
qDebug()<<a;

    if(b < c){

            a /= 2;
            do {
                b += a;
                ui->label_2 -> setText(QString::number(b));
            } while (b < c);

    }
    if(b > c){

            do {
                b -= a;
                  ui->label_2 -> setText(QString::number(b));
            } while (b > c);

    }

    if(b == c){
        ui->label_3->setText("Ваше число");
        ui->label_2 -> setText(QString::number(b));
    }


    void on_spinBox_editingFinished();
   // b -= a;
    ui->label_3->setText("Ваше число меньше");
    ui->label_2 -> setText(QString::number(b));

   /*for (int i = 2000; b > a; i++) {

    b -= a;
   }*/
}


void MainWindow::on_pb_yes_clicked()
{
    qDebug()<<a;
    if(b < c){

            a /= 2;

            do {
                b += a;
                ui->label_2 -> setText(QString::number(b));
            } while (b < c);

    }
    if(b > c){

            do {
                b -= a;
                  ui->label_2 -> setText(QString::number(b));
            } while (b > c);

    }

    if(b == c){
        ui->label_3->setText("Ваше число");
        ui->label_2 -> setText(QString::number(b));
    }

}


