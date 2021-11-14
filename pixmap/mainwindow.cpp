#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(bt_change()));
    setFormStyle();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setFormStyle()
{
    //img_paw.load("F:/Qt Creator/Projects/pixmap/images/paw.svg");
    //ui->img_label->setPixmap(img_paw.scaled(img_paw.size()));
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->widget->setStyleSheet("background:transparent;");
    setMouseTracking(true);

}

void MainWindow::bt_change(){
    this->close();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    qDebug()<<event->pos();
    QPoint pos_on_centralwidget (event->pos() - ui->centralwidget->pos());
    QPoint &mp = pos_on_centralwidget;

    //ui->pb_bye->setGeometry(120,30,88,34);

    QPoint btn_rmove(0,0);
    QRect paw_geometry(ui->img_label->geometry());
    const QPoint diff(mp - ui->img_label->geometry().center());//Отрицательные значения если курсор левее или выше кнопки

    const int btn_half_width = ui->img_label->width() / 2;
    const int btn_half_height = ui->img_label->height() / 2;
    static const int marg = 5;
    const bool is_in_left_margin = diff.x() <= 0 && diff.x() >= -marg - btn_half_width;
    const bool is_in_right_margin = diff.x() > 0 && diff.x() <= marg + btn_half_width;
    const bool is_in_top_margin = diff.y() <= 0 && diff.y() >= -marg - btn_half_height;
    const bool is_in_bottom_margin = diff.y() > 0 && diff.y() <= marg + btn_half_height;
    const bool in_x_margin = is_in_left_margin || is_in_right_margin;
    const bool in_y_margin = is_in_top_margin || is_in_bottom_margin;
    const bool in_button_heigth = mp.y() >= paw_geometry.top() && mp.y() <= paw_geometry.bottom();
    const bool in_button_width = mp.x() >= paw_geometry.left() && mp.x() <= paw_geometry.right();

    if (!(in_x_margin && in_y_margin))
        return;

    if(is_in_left_margin && in_y_margin){
        btn_rmove.setX(-(diff.x() + btn_half_width));
    }
    if(is_in_right_margin && in_y_margin){
        btn_rmove.setX(-(diff.x() - btn_half_width));
    }
    if(is_in_top_margin && in_x_margin){
        btn_rmove.setY(-(diff.y() + btn_half_height));
    }
    if(is_in_bottom_margin && in_x_margin){
        btn_rmove.setY(-(diff.y() - btn_half_height));
    }

    if (in_button_heigth && !in_button_width){
        btn_rmove.setY(0);
    }

    if (!in_button_heigth && in_button_width){
        btn_rmove.setX(0);
    }

    if(paw_geometry.contains(mp)) {
       QPoint diff(paw_geometry.center() - mp);
       diff.setX((diff.x() >= 0) ? 1 : -1);
       diff.setY((diff.y() >= 0) ? 1 : -1);

       QRect g = paw_geometry;
       QPoint p(btn_half_width + marg, btn_half_height + marg);
       p.setX(p.x() * diff.x() + mp.x());
       p.setY(p.y() * diff.y() + mp.y());
       g.moveCenter(p);
       ui->img_label->setGeometry(g);
       return;
   }
}




