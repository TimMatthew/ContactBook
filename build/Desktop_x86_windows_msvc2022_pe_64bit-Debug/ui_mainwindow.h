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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
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
    QScrollArea *scrollArea;
    QWidget *scrollAreaContacts;
    QWidget *widget;
    QLabel *noContactsLabel;
    QMenuBar *menubar;
    QMenu *menuOpenfrom_file;
    QMenu *menuSave;
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
        addButton->setGeometry(QRect(400, 570, 71, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Franklin Gothic Book")});
        font1.setPointSize(48);
        addButton->setFont(font1);
        addButton->setStyleSheet(QString::fromUtf8("background-color: lightgreen;\n"
"border-radius: 35px;\n"
"color: white;\n"
""));
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
        noContactsLabel = new QLabel(scrollAreaContacts);
        noContactsLabel->setObjectName("noContactsLabel");
        noContactsLabel->setGeometry(QRect(60, 200, 321, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Franklin Gothic Book")});
        font2.setPointSize(18);
        noContactsLabel->setFont(font2);
        noContactsLabel->setAlignment(Qt::AlignCenter);
        scrollArea->setWidget(scrollAreaContacts);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 490, 27));
        QFont font3;
        font3.setPointSize(12);
        menubar->setFont(font3);
        menubar->setStyleSheet(QString::fromUtf8("background-color: white;"));
        menuOpenfrom_file = new QMenu(menubar);
        menuOpenfrom_file->setObjectName("menuOpenfrom_file");
        menuOpenfrom_file->setFont(font3);
        menuSave = new QMenu(menubar);
        menuSave->setObjectName("menuSave");
        menuSave->setFont(font3);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOpenfrom_file->menuAction());
        menubar->addAction(menuSave->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Contact Book", nullptr));
        searchLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "  Search contacts by name...", nullptr));
        searchImage->setText(QString());
        addButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        noContactsLabel->setText(QCoreApplication::translate("MainWindow", "There is no contacts so far...", nullptr));
        menuOpenfrom_file->setTitle(QCoreApplication::translate("MainWindow", "Open from file", nullptr));
        menuSave->setTitle(QCoreApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
