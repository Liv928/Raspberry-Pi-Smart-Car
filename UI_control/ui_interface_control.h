/********************************************************************************
** Form generated from reading UI file 'interface_control.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_CONTROL_H
#define UI_INTERFACE_CONTROL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interface_control
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *interface_control)
    {
        if (interface_control->objectName().isEmpty())
            interface_control->setObjectName(QString::fromUtf8("interface_control"));
        interface_control->resize(400, 300);
        centralWidget = new QWidget(interface_control);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, -10, 81, 71));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 80, 81, 71));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 80, 81, 71));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(140, 170, 81, 71));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(240, 80, 81, 71));
        interface_control->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(interface_control);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 27));
        interface_control->setMenuBar(menuBar);
        mainToolBar = new QToolBar(interface_control);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        interface_control->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(interface_control);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        interface_control->setStatusBar(statusBar);

        retranslateUi(interface_control);

        QMetaObject::connectSlotsByName(interface_control);
    } // setupUi

    void retranslateUi(QMainWindow *interface_control)
    {
        interface_control->setWindowTitle(QApplication::translate("interface_control", "interface_control", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("interface_control", "forward", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("interface_control", "left", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("interface_control", "brake", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("interface_control", "back", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("interface_control", "right", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class interface_control: public Ui_interface_control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_CONTROL_H
