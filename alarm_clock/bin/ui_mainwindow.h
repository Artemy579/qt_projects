/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLCDNumber *lcdNumber;
    QLabel *label_hours;
    QLabel *label_min;
    QLabel *label_sec;
    QLabel *label_mil_sec;
    QSpinBox *spinBox_hours;
    QSpinBox *spinBox_min;
    QSpinBox *spinBox_sec;
    QSpinBox *spinBox_mil_sec;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(852, 513);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 210, 851, 301));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1, 1, 851, 201));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setProperty("intValue", QVariant(0));

        gridLayout->addWidget(lcdNumber, 0, 0, 1, 4);

        label_hours = new QLabel(widget);
        label_hours->setObjectName(QString::fromUtf8("label_hours"));

        gridLayout->addWidget(label_hours, 1, 0, 1, 1);

        label_min = new QLabel(widget);
        label_min->setObjectName(QString::fromUtf8("label_min"));

        gridLayout->addWidget(label_min, 1, 1, 1, 1);

        label_sec = new QLabel(widget);
        label_sec->setObjectName(QString::fromUtf8("label_sec"));

        gridLayout->addWidget(label_sec, 1, 2, 1, 1);

        label_mil_sec = new QLabel(widget);
        label_mil_sec->setObjectName(QString::fromUtf8("label_mil_sec"));

        gridLayout->addWidget(label_mil_sec, 1, 3, 1, 1);

        spinBox_hours = new QSpinBox(widget);
        spinBox_hours->setObjectName(QString::fromUtf8("spinBox_hours"));
        spinBox_hours->setMaximum(999);

        gridLayout->addWidget(spinBox_hours, 2, 0, 1, 1);

        spinBox_min = new QSpinBox(widget);
        spinBox_min->setObjectName(QString::fromUtf8("spinBox_min"));
        spinBox_min->setAccelerated(false);
        spinBox_min->setMaximum(999);
        spinBox_min->setStepType(QAbstractSpinBox::DefaultStepType);
        spinBox_min->setDisplayIntegerBase(10);

        gridLayout->addWidget(spinBox_min, 2, 1, 1, 1);

        spinBox_sec = new QSpinBox(widget);
        spinBox_sec->setObjectName(QString::fromUtf8("spinBox_sec"));
        spinBox_sec->setMaximum(999);

        gridLayout->addWidget(spinBox_sec, 2, 2, 1, 1);

        spinBox_mil_sec = new QSpinBox(widget);
        spinBox_mil_sec->setObjectName(QString::fromUtf8("spinBox_mil_sec"));
        spinBox_mil_sec->setMinimum(0);
        spinBox_mil_sec->setMaximum(999);
        spinBox_mil_sec->setValue(0);

        gridLayout->addWidget(spinBox_mil_sec, 2, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Alarm clock", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label_hours->setText(QCoreApplication::translate("MainWindow", "                         \320\247\320\260\321\201\321\213", nullptr));
        label_min->setText(QCoreApplication::translate("MainWindow", "                    \320\234\320\270\320\275\321\203\321\202\321\213", nullptr));
        label_sec->setText(QCoreApplication::translate("MainWindow", "                     \320\241\320\265\320\272\321\203\320\275\320\264\321\213", nullptr));
        label_mil_sec->setText(QCoreApplication::translate("MainWindow", "                 \320\234\320\270\320\273\320\270\321\201\320\265\320\272\321\203\320\275\320\264\321\213", nullptr));
        spinBox_mil_sec->setPrefix(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
