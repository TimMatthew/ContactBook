/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *searchWidget;
    QLineEdit *searchLine;
    QLabel *searchImage;
    QPushButton *addButton;
    QPushButton *editButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaContacts;
    QWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(490, 690);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 255, 252);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        searchWidget = new QWidget(centralwidget);
        searchWidget->setObjectName("searchWidget");
        searchWidget->setGeometry(QRect(20, 30, 451, 71));
        searchLine = new QLineEdit(searchWidget);
        searchLine->setObjectName("searchLine");
        searchLine->setGeometry(QRect(10, 20, 321, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Franklin Gothic Book")});
        font.setPointSize(12);
        searchLine->setFont(font);
        searchLine->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border: 2px solid grey;\n"
"border-radius: 10px;"));
        searchImage = new QLabel(searchWidget);
        searchImage->setObjectName("searchImage");
        searchImage->setGeometry(QRect(370, 0, 71, 71));
        searchImage->setPixmap(QPixmap(QString::fromUtf8("search_icon_small.png")));
        searchImage->setScaledContents(true);
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(60, 580, 111, 41));
        addButton->setFont(font);
        addButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 10px;\n"
"border: 2px solid lightgrey;"));
        editButton = new QPushButton(centralwidget);
        editButton->setObjectName("editButton");
        editButton->setGeometry(QRect(310, 580, 111, 41));
        editButton->setFont(font);
        editButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 2px solid lightgrey;\n"
"border-radius: 10px;"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(20, 120, 451, 431));
        scrollArea->setWidgetResizable(true);
        scrollAreaContacts = new QWidget();
        scrollAreaContacts->setObjectName("scrollAreaContacts");
        scrollAreaContacts->setGeometry(QRect(0, 0, 449, 429));
        widget = new QWidget(scrollAreaContacts);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 10, 411, 61));
        scrollArea->setWidget(scrollAreaContacts);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 490, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Contact Book", nullptr));
        searchLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "  Search contacts by name...", nullptr));
        searchImage->setText(QString());
        addButton->setText(QCoreApplication::translate("MainWindow", "Add contact", nullptr));
        editButton->setText(QCoreApplication::translate("MainWindow", "Edit contact", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
