/********************************************************************************
** Form generated from reading UI file 'editcontactdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCONTACTDIALOG_H
#define UI_EDITCONTACTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editContactDialog
{
public:
    QLineEdit *nameLine;
    QLabel *nameLabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaNumbers;
    QLabel *wrongNumber;
    QLabel *emptyNumber;
    QLabel *emptyName;
    QPushButton *addNumberButton;
    QPushButton *OKButon;
    QPushButton *deleteButton;

    void setupUi(QDialog *editContactDialog)
    {
        if (editContactDialog->objectName().isEmpty())
            editContactDialog->setObjectName("editContactDialog");
        editContactDialog->resize(614, 337);
        editContactDialog->setStyleSheet(QString::fromUtf8("background-color:  rgb(210, 255, 252);"));
        nameLine = new QLineEdit(editContactDialog);
        nameLine->setObjectName("nameLine");
        nameLine->setGeometry(QRect(141, 30, 431, 22));
        nameLine->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 10px;\n"
"border: 2px solid black;"));
        nameLabel = new QLabel(editContactDialog);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(40, 30, 95, 22));
        QFont font;
        font.setFamilies({QString::fromUtf8("Franklin Gothic Book")});
        font.setPointSize(12);
        nameLabel->setFont(font);
        scrollArea = new QScrollArea(editContactDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(40, 70, 531, 141));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: white;"));
        scrollArea->setWidgetResizable(true);
        scrollAreaNumbers = new QWidget();
        scrollAreaNumbers->setObjectName("scrollAreaNumbers");
        scrollAreaNumbers->setGeometry(QRect(0, 0, 529, 139));
        scrollArea->setWidget(scrollAreaNumbers);
        wrongNumber = new QLabel(editContactDialog);
        wrongNumber->setObjectName("wrongNumber");
        wrongNumber->setGeometry(QRect(130, 230, 341, 21));
        QFont font1;
        font1.setPointSize(12);
        wrongNumber->setFont(font1);
        wrongNumber->setStyleSheet(QString::fromUtf8("color: darkred;"));
        wrongNumber->setAlignment(Qt::AlignCenter);
        emptyNumber = new QLabel(editContactDialog);
        emptyNumber->setObjectName("emptyNumber");
        emptyNumber->setEnabled(true);
        emptyNumber->setGeometry(QRect(130, 230, 341, 21));
        emptyNumber->setFont(font1);
        emptyNumber->setStyleSheet(QString::fromUtf8("color: darkred;"));
        emptyNumber->setAlignment(Qt::AlignCenter);
        emptyName = new QLabel(editContactDialog);
        emptyName->setObjectName("emptyName");
        emptyName->setEnabled(true);
        emptyName->setGeometry(QRect(130, 230, 341, 21));
        emptyName->setFont(font1);
        emptyName->setStyleSheet(QString::fromUtf8("color: darkred;"));
        emptyName->setAlignment(Qt::AlignCenter);
        addNumberButton = new QPushButton(editContactDialog);
        addNumberButton->setObjectName("addNumberButton");
        addNumberButton->setGeometry(QRect(383, 270, 146, 41));
        addNumberButton->setFont(font);
        addNumberButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 2px solid black;\n"
"border-radius: 10px;"));
        OKButon = new QPushButton(editContactDialog);
        OKButon->setObjectName("OKButon");
        OKButon->setGeometry(QRect(232, 270, 145, 41));
        OKButon->setFont(font);
        OKButon->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 2px solid black;\n"
"border-radius: 10px;"));
        deleteButton = new QPushButton(editContactDialog);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(80, 270, 146, 41));
        deleteButton->setFont(font);
        deleteButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 2px solid black;\n"
"border-radius: 10px;"));

        retranslateUi(editContactDialog);

        QMetaObject::connectSlotsByName(editContactDialog);
    } // setupUi

    void retranslateUi(QDialog *editContactDialog)
    {
        editContactDialog->setWindowTitle(QCoreApplication::translate("editContactDialog", "Edit the contact", nullptr));
        nameLabel->setText(QCoreApplication::translate("editContactDialog", "Contact Name", nullptr));
        wrongNumber->setText(QCoreApplication::translate("editContactDialog", "Invalid input to phone numbers!", nullptr));
        emptyNumber->setText(QCoreApplication::translate("editContactDialog", "The number is empty!", nullptr));
        emptyName->setText(QCoreApplication::translate("editContactDialog", "The name is empty!", nullptr));
        addNumberButton->setText(QCoreApplication::translate("editContactDialog", "Add number", nullptr));
        OKButon->setText(QCoreApplication::translate("editContactDialog", "OK", nullptr));
        deleteButton->setText(QCoreApplication::translate("editContactDialog", "Delete contact", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editContactDialog: public Ui_editContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCONTACTDIALOG_H
