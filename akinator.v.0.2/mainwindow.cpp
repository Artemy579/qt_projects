#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*ui->pb_yes->hide();
    ui->pb_no->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    */
    ui->spinBox->setRange(1, 2000);
    create_msg_box();
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(pushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::create_msg_box(){
    msg_box = new QMessageBox;
    pb_less = new QPushButton("Меньше");
    pb_greater = new QPushButton("Больше");
    pb_thats_it = new QPushButton("Угадал");
    pb_terminate = new QPushButton("Завершить");
    msg_box->addButton(pb_less, QMessageBox::NoRole);
    msg_box->addButton(pb_greater, QMessageBox::YesRole);
    msg_box->addButton(pb_thats_it, QMessageBox::AcceptRole);
    msg_box->addButton(pb_terminate, QMessageBox::RejectRole);
}


void MainWindow::pushButton_clicked()
{
   a = ui->spinBox->text().toInt();
   c = a;
   try_to_guess();
}

void MainWindow::try_to_guess(){
    //Попытаться угадать

    msg_box->setText("Ваше число больше 1999?");
    msg_box->exec();
    do {

        if (msg_box->clickedButton() == pb_less){

                do {
                b -= a;
                msg_box->setText("Ваше число " + QString::number(b));
            } while (b > c);
            a /= 2;
            msg_box->exec();
            n++;
            emit next_attempt();
        }
        if (msg_box->clickedButton() == pb_greater){

                do {
                    b += a;
                    msg_box->setText("Ваше число " + QString::number(b));

                } while (b < c);
                a /= 2;
                msg_box->exec();
                n++;
            emit next_attempt();
        }
        if(msg_box->clickedButton() == pb_terminate){
            QMessageBox::information(this, "Ошибка" ,"Программа была прервана пользователем");
            return;
        }
        if (msg_box->clickedButton() == pb_thats_it){
            QMessageBox::information(this, "Успех!", "Отгадано за " + QString::number(n) + " попыток");
            emit next_attempt();
            return;
        }

    } while (msg_box->clickedButton() != pb_terminate || msg_box->clickedButton() != pb_thats_it);


}




































/*void MainWindow::on_spinBox_textChanged(const QString &arg1)
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
   }
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

}*/







