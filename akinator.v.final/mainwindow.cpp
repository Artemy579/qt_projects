#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   
    ui->spinBox->setRange(1, 2000);
    create_msg_box();
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(pushButton_clicked()));
    connect(this, SIGNAL(next_attempt(bool)), this, SLOT(try_to_guess(bool)), Qt::QueuedConnection);
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
    msg_box->setIconPixmap(QPixmap("://icons/akinator-ask.png"));
}


void MainWindow::pushButton_clicked()
{
    ui->spinBox->setEnabled(false);
    a = ui->spinBox->minimum();
    b = ui->spinBox->maximum();
   emit next_attempt();
}

void MainWindow::try_to_guess(bool gen_new_nmb){
    //Попытаться угадать
    if (gen_new_nmb){
        ++n;
        c = ((b - a) / 2) + a;
    }
    msg_box->setText("Ваше число: " + QString::number(c) + "?");
    msg_box->exec();

    if (msg_box->clickedButton() == pb_less){
        bool userLies = !(c >= ui->spinBox->value());
        if (!userLies)
            b = c;
        else
            QMessageBox::information(this, "Ошибка" ,"Вы врёте");
        emit next_attempt(!userLies);
        return;
    }
    if (msg_box->clickedButton() == pb_greater){
        bool userLies = !(c <= ui->spinBox->value());
        if (!userLies)
            a = c;
        else
            QMessageBox::information(this, "Ошибка" ,"Вы врёте");
        emit next_attempt(!userLies);
        return;
    }
    if (msg_box->clickedButton() == pb_thats_it){
        bool userLies = (c != ui->spinBox->value());
        if (userLies){
            QMessageBox::information(this, "Ошибка" ,"Вы врёте");
            emit next_attempt(!userLies);
            return;
        }
        QMessageBox::information(this, "Успех!", "Отгадано за " + QString::number(n) + " попыток");
        ui->spinBox->setEnabled(true);
        return;
    }
    //Прервано пользователем
    {
        QMessageBox::information(this, "Ошибка" ,"Угадывание числа прервано пользователем");
        return;
    }

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







