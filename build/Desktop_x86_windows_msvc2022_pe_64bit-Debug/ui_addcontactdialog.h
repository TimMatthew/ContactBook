/********************************************************************************
** Form generated from reading UI file 'addcontactdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCONTACTDIALOG_H
#define UI_ADDCONTACTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addContactDialog
{
public:
    QPushButton *OKButton;
    QPushButton *addNumberButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaNumbers;
    QWidget *layoutWidget;
    QHBoxLayout *nameLayout;
    QLabel *nameLabel;
    QLineEdit *nameLine;
    QLabel *wrongNumber;
    QLabel *emptyName;
    QLabel *emptyNumber;

    void setupUi(QDialog *addContactDialog)
    {
        if (addContactDialog->objectName().isEmpty())
            addContactDialog->setObjectName("addContactDialog");
        addContactDialog->resize(548, 329);
        addContactDialog->setStyleSheet(QString::fromUtf8("background-color:rgb(206, 253, 255);"));
        OKButton = new QPushButton(addContactDialog);
        OKButton->setObjectName("OKButton");
        OKButton->setGeometry(QRect(110, 260, 101, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Franklin Gothic Book")});
        font.setPointSize(14);
        OKButton->setFont(font);
        OKButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 2px solid black;\n"
"border-radius: 15px;"));
        addNumberButton = new QPushButton(addContactDialog);
        addNumberButton->setObjectName("addNumberButton");
        addNumberButton->setGeometry(QRect(280, 260, 171, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Franklin Gothic Book")});
        font1.setPointSize(12);
        addNumberButton->setFont(font1);
        addNumberButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 2px solid black;\n"
"border-radius: 15px;"));
        scrollArea = new QScrollArea(addContactDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(30, 60, 491, 161));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: white;"));
        scrollArea->setWidgetResizable(true);
        scrollAreaNumbers = new QWidget();
        scrollAreaNumbers->setObjectName("scrollAreaNumbers");
        scrollAreaNumbers->setGeometry(QRect(0, 0, 489, 159));
        scrollArea->setWidget(scrollAreaNumbers);
        layoutWidget = new QWidget(addContactDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 20, 491, 24));
        nameLayout = new QHBoxLayout(layoutWidget);
        nameLayout->setObjectName("nameLayout");
        nameLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setFont(font1);

        nameLayout->addWidget(nameLabel);

        nameLine = new QLineEdit(layoutWidget);
        nameLine->setObjectName("nameLine");
        nameLine->setStyleSheet(QString::fromUtf8("background-color: white; \n"
"border-radius: 5px;\n"
"border: 2px solid black;"));

        nameLayout->addWidget(nameLine);

        wrongNumber = new QLabel(addContactDialog);
        wrongNumber->setObjectName("wrongNumber");
        wrongNumber->setGeometry(QRect(110, 230, 341, 21));
        QFont font2;
        font2.setPointSize(12);
        wrongNumber->setFont(font2);
        wrongNumber->setStyleSheet(QString::fromUtf8("color: darkred;"));
        wrongNumber->setAlignment(Qt::AlignCenter);
        emptyName = new QLabel(addContactDialog);
        emptyName->setObjectName("emptyName");
        emptyName->setEnabled(true);
        emptyName->setGeometry(QRect(110, 230, 341, 21));
        emptyName->setFont(font2);
        emptyName->setStyleSheet(QString::fromUtf8("color: darkred;"));
        emptyName->setAlignment(Qt::AlignCenter);
        emptyNumber = new QLabel(addContactDialog);
        emptyNumber->setObjectName("emptyNumber");
        emptyNumber->setEnabled(true);
        emptyNumber->setGeometry(QRect(110, 230, 341, 21));
        emptyNumber->setFont(font2);
        emptyNumber->setStyleSheet(QString::fromUtf8("color: rgb(255, 47, 47);"));
        emptyNumber->setAlignment(Qt::AlignCenter);

        retranslateUi(addContactDialog);

        QMetaObject::connectSlotsByName(addContactDialog);
    } // setupUi

    void retranslateUi(QDialog *addContactDialog)
    {
        addContactDialog->setWindowTitle(QCoreApplication::translate("addContactDialog", "Add a new contact", nullptr));
        OKButton->setText(QCoreApplication::translate("addContactDialog", "OK", nullptr));
        addNumberButton->setText(QCoreApplication::translate("addContactDialog", "+ Add another number", nullptr));
        nameLabel->setText(QCoreApplication::translate("addContactDialog", "Contact Name", nullptr));
        wrongNumber->setText(QCoreApplication::translate("addContactDialog", "Invalid input to phone numbers!", nullptr));
        emptyName->setText(QCoreApplication::translate("addContactDialog", "The name is empty!", nullptr));
        emptyNumber->setText(QCoreApplication::translate("addContactDialog", "The number is empty!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addContactDialog: public Ui_addContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONTACTDIALOG_H
