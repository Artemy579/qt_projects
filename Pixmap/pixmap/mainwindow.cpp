#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->label, SIGNAL(clicked()), this, SLOT(bt_change()));
    setFormStyle();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setFormStyle()
{
    img_close_bt.load("://images/close-61x61.png");
    img_close_bt_pressed.load("://images/close-pressed-61x61.png");
    ui->label->setPixmaps(img_close_bt, img_close_bt_pressed);


    setWindowFlags(Qt::FramelessWindowHint);
    const QPixmap pm = QPixmap(":/img/images/paw.svg");
    setFixedSize(pm.size());
    setMask(QBitmap(pm.createMaskFromColor(Qt::black, Qt::MaskOutColor)));
    //    QPalette pal = palette();
    //    pal.setColor(QPalette::Window, Qt::yellow);
    //    setPalette(pal);
    setMouseTracking(true);

}

void MainWindow::bt_change(){

    this->close();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){

}




