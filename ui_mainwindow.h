/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *normalSearchButton;
    QPushButton *binarySearchButton;
    QPushButton *generateDataButton;
    QPushButton *mergeSortButton;
    QPushButton *stlSortButton;
    QPushButton *findButton;
    QLabel *arrayStatus;
    QLabel *arrayStatus_2;
    QLineEdit *datasetInput;
    QListWidget *listWidget;
    QLabel *dataSizeText;
    QLabel *mergeMethodText;
    QLabel *searchMethodText;
    QLineEdit *numberInput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 90, 181, 16));
        normalSearchButton = new QPushButton(centralwidget);
        normalSearchButton->setObjectName(QString::fromUtf8("normalSearchButton"));
        normalSearchButton->setGeometry(QRect(100, 130, 91, 24));
        binarySearchButton = new QPushButton(centralwidget);
        binarySearchButton->setObjectName(QString::fromUtf8("binarySearchButton"));
        binarySearchButton->setGeometry(QRect(100, 170, 91, 24));
        generateDataButton = new QPushButton(centralwidget);
        generateDataButton->setObjectName(QString::fromUtf8("generateDataButton"));
        generateDataButton->setGeometry(QRect(100, 390, 121, 24));
        mergeSortButton = new QPushButton(centralwidget);
        mergeSortButton->setObjectName(QString::fromUtf8("mergeSortButton"));
        mergeSortButton->setGeometry(QRect(341, 380, 151, 24));
        stlSortButton = new QPushButton(centralwidget);
        stlSortButton->setObjectName(QString::fromUtf8("stlSortButton"));
        stlSortButton->setGeometry(QRect(340, 410, 151, 24));
        findButton = new QPushButton(centralwidget);
        findButton->setObjectName(QString::fromUtf8("findButton"));
        findButton->setGeometry(QRect(600, 270, 80, 24));
        arrayStatus = new QLabel(centralwidget);
        arrayStatus->setObjectName(QString::fromUtf8("arrayStatus"));
        arrayStatus->setGeometry(QRect(360, 60, 101, 16));
        arrayStatus_2 = new QLabel(centralwidget);
        arrayStatus_2->setObjectName(QString::fromUtf8("arrayStatus_2"));
        arrayStatus_2->setGeometry(QRect(110, 310, 101, 16));
        datasetInput = new QLineEdit(centralwidget);
        datasetInput->setObjectName(QString::fromUtf8("datasetInput"));
        datasetInput->setGeometry(QRect(100, 350, 113, 24));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(280, 100, 256, 271));
        dataSizeText = new QLabel(centralwidget);
        dataSizeText->setObjectName(QString::fromUtf8("dataSizeText"));
        dataSizeText->setGeometry(QRect(600, 110, 141, 16));
        mergeMethodText = new QLabel(centralwidget);
        mergeMethodText->setObjectName(QString::fromUtf8("mergeMethodText"));
        mergeMethodText->setGeometry(QRect(600, 140, 151, 16));
        searchMethodText = new QLabel(centralwidget);
        searchMethodText->setObjectName(QString::fromUtf8("searchMethodText"));
        searchMethodText->setGeometry(QRect(600, 170, 161, 16));
        numberInput = new QLineEdit(centralwidget);
        numberInput->setObjectName(QString::fromUtf8("numberInput"));
        numberInput->setGeometry(QRect(590, 240, 113, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Choose Your Search Method:", nullptr));
        normalSearchButton->setText(QCoreApplication::translate("MainWindow", "Normal Search", nullptr));
        binarySearchButton->setText(QCoreApplication::translate("MainWindow", "Binary Search", nullptr));
        generateDataButton->setText(QCoreApplication::translate("MainWindow", "Generate Dataset", nullptr));
        mergeSortButton->setText(QCoreApplication::translate("MainWindow", "Sort Using Merge Sort", nullptr));
        stlSortButton->setText(QCoreApplication::translate("MainWindow", "Sort Using STL Sort", nullptr));
        findButton->setText(QCoreApplication::translate("MainWindow", "Find It!", nullptr));
        arrayStatus->setText(QCoreApplication::translate("MainWindow", "Unsorted Array", nullptr));
        arrayStatus_2->setText(QCoreApplication::translate("MainWindow", "Input Dataset Size", nullptr));
        dataSizeText->setText(QString());
        mergeMethodText->setText(QString());
        searchMethodText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
