#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setBrush(QPalette::Background, Qt::yellow);
    this->setPalette(palette);

    polygon_base  << QPoint(0, 85) << QPoint(75, 75)
                  << QPoint(100, 10) << QPoint(125, 75)
                  << QPoint(200, 85) << QPoint(150, 125)
                  << QPoint(160, 190) << QPoint(100, 150)
                  << QPoint(40, 190) << QPoint(50, 125)
                  << QPoint(0, 85);
    connect(&timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
    timer.start(50);
    draw_rec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw_rec(){
    QPolygon polygon = polygon_base;

    static double k = 1;
    static double delta =  0.1;
    k += delta;
    for (int i = 0; i < polygon.size(); ++i) {

        polygon[i].setX(std::round(polygon[i].x() * k));
        polygon[i].setY(std::round(polygon[i].y() * k));
    }
    const QSize my_size = QSize(polygon[4].x()+1, polygon[6].y()+1);
    const QSize bound_size = polygon.boundingRect().size();
    setFixedSize(my_size);//works correct
    //setFixedSize(bound_size);//works wrong
    qDebug()<<"my_size: "<<my_size<<" polygon.boundingRect().size(): "<<bound_size;
    qDebug()<<" k: "<<k;
    setMask(polygon);
    QScreen *pscreen = QGuiApplication::primaryScreen();
    QRect rect = geometry();
    rect.moveCenter(pscreen->availableGeometry().center());
    setGeometry(rect);

    if(rect.height() >= pscreen->availableGeometry().height()){
       delta = -0.1;
    }

}

void MainWindow::timer_timeout(){
    draw_rec();
}


