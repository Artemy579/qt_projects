#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->label, SIGNAL(clicked()), this, SLOT(bt_change()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
    timer.start(10);
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
    QPixmap texture = QPixmap(":/img/images/Tileable-Dirty-Ground-Texture.png");
    QBrush dirt = QBrush(texture);
    QPalette pal = palette();
    pal.setBrush(QPalette::Window, dirt);
    setPalette(pal);
}

void MainWindow::bt_change(){

    this->close();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    /*
    int width_widget = this->width() / 2;
    int height_widget = this->height() / 2;
    QRect geom = this->geometry();
    geom.moveTo(0,0);
    QPoint center = geom.center();
    QPoint mouse_pos = event->pos();

    int projection_x = mouse_pos.x() - center.x();
    int projection_y = mouse_pos.y() - center.y();
    int step_x = projection_x * 5 / width_widget;
    int step_y = projection_y * 5 / height_widget;
    QPoint form_position = pos();
    double dx = std::pow(center.x() - mouse_pos.x(), 2);
    double dy = std::pow(center.y() - mouse_pos.y(), 2);
    double d = std::sqrt(dx + dy);
    if(d < 170){
        QMainWindow::mouseMoveEvent(event);
        return;
    }
    this->move(form_position.x() + step_x, form_position.y() + step_y);*/
    QMainWindow::mouseMoveEvent(event);
}

void MainWindow::timer_timeout() {
    QPoint globalCursorPos = QCursor::pos();
    QPoint form_based_pos = this->mapFromGlobal(globalCursorPos);
    if(form_based_pos.x() < 0 || form_based_pos.y() < 0 || form_based_pos.x() >= this->width() || form_based_pos.y() >= this->height()){
        return;
    }
    QPoint mouse_pos = form_based_pos;
    int width_widget = this->width() / 2;
    int height_widget = this->height() / 2;
    QRect geom = this->geometry();
    geom.moveTo(0,0);
    QPoint center = geom.center();

    int projection_x = mouse_pos.x() - center.x();
    int projection_y = mouse_pos.y() - center.y();
    int step_x = projection_x * 5 / width_widget;
    int step_y = projection_y * 5 / height_widget;
    QPoint form_position = pos();
    double dx = std::pow(center.x() - mouse_pos.x(), 2);
    double dy = std::pow(center.y() - mouse_pos.y(), 2);
    double d = std::sqrt(dx + dy);
    if(d < 150){
        return;
    }
    this->move(form_position.x() + step_x, form_position.y() + step_y);
}


