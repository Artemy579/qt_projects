#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(spinbox_value_changed(int)));
    connect(&timer, SIGNAL(timeout()), this, SLOT(spinbox_value_changed(int)));
    connect(&timer, SIGNAL(timeout()), this, SLOT(add_radiobutton()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(time_out()));
    timer.start(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::spinbox_value_changed(int value){
    QBoxLayout* l = qobject_cast<QBoxLayout*>(ui->wgt_rb->layout());
    const int difference = value - l->count();
    if (difference > 0)
        add_radiobutton(difference, l);
    else if (difference < 0)
        remove_radiobutton(-difference, l);
}

void MainWindow::time_out(){
    if(vector.empty())
        return;

    ++rb_idx;

    if(rb_idx >= vector.size()){
        rb_idx = 0;
    }
    vector[rb_idx]->setChecked(true);
}

void MainWindow::add_radiobutton(unsigned count, QBoxLayout *l){
    for (unsigned i = 0; i < count; ++i) {
        QRadioButton *button = new QRadioButton;
        l->addWidget(button);
        vector.append(button);
    }

}


void MainWindow::remove_radiobutton(unsigned count, QBoxLayout *l){

    for (unsigned i = 0; i < count; ++i){
        QLayoutItem *item = l->takeAt(l->count() - 1);
        delete item->widget();
        delete item;
        vector.pop_back();
    }
}
