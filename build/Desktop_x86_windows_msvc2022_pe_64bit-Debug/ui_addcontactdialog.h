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

    void setupUi(QDialog *addContactDialog)
    {
        if (addContactDialog->objectName().isEmpty())
            addContactDialog->setObjectName("addContactDialog");
        addContactDialog->resize(548, 329);
        OKButton = new QPushButton(addContactDialog);
        OKButton->setObjectName("OKButton");
        OKButton->setGeometry(QRect(120, 260, 101, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Franklin Gothic Book")});
        font.setPointSize(14);
        OKButton->setFont(font);
        addNumberButton = new QPushButton(addContactDialog);
        addNumberButton->setObjectName("addNumberButton");
        addNumberButton->setGeometry(QRect(280, 260, 171, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Franklin Gothic Book")});
        font1.setPointSize(12);
        addNumberButton->setFont(font1);
        scrollArea = new QScrollArea(addContactDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(30, 60, 491, 161));
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

        nameLayout->addWidget(nameLine);


        retranslateUi(addContactDialog);

        QMetaObject::connectSlotsByName(addContactDialog);
    } // setupUi

    void retranslateUi(QDialog *addContactDialog)
    {
        addContactDialog->setWindowTitle(QCoreApplication::translate("addContactDialog", "Add a new contact", nullptr));
        OKButton->setText(QCoreApplication::translate("addContactDialog", "OK", nullptr));
        addNumberButton->setText(QCoreApplication::translate("addContactDialog", "+ Add another number", nullptr));
        nameLabel->setText(QCoreApplication::translate("addContactDialog", "Contact Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addContactDialog: public Ui_addContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONTACTDIALOG_H
