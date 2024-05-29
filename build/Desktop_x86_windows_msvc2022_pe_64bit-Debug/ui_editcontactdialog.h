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
#include <QtWidgets/QHBoxLayout>
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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *deleteButton;
    QPushButton *OKButon;
    QPushButton *addNumberButton;
    QLabel *wrongNumber;
    QLabel *emptyNumber;
    QLabel *emptyName;

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
        layoutWidget = new QWidget(editContactDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(80, 270, 451, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        deleteButton = new QPushButton(layoutWidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setFont(font);
        deleteButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 2px solid black;\n"
"border-radius: 10px;"));

        horizontalLayout->addWidget(deleteButton);

        OKButon = new QPushButton(layoutWidget);
        OKButon->setObjectName("OKButon");
        OKButon->setFont(font);
        OKButon->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 2px solid black;\n"
"border-radius: 10px;"));

        horizontalLayout->addWidget(OKButon);

        addNumberButton = new QPushButton(layoutWidget);
        addNumberButton->setObjectName("addNumberButton");
        addNumberButton->setFont(font);
        addNumberButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 2px solid black;\n"
"border-radius: 10px;"));

        horizontalLayout->addWidget(addNumberButton);

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

        retranslateUi(editContactDialog);

        QMetaObject::connectSlotsByName(editContactDialog);
    } // setupUi

    void retranslateUi(QDialog *editContactDialog)
    {
        editContactDialog->setWindowTitle(QCoreApplication::translate("editContactDialog", "Edit the contact", nullptr));
        nameLabel->setText(QCoreApplication::translate("editContactDialog", "Contact Name", nullptr));
        deleteButton->setText(QCoreApplication::translate("editContactDialog", "Delete contact", nullptr));
        OKButon->setText(QCoreApplication::translate("editContactDialog", "OK", nullptr));
        addNumberButton->setText(QCoreApplication::translate("editContactDialog", "Add number", nullptr));
        wrongNumber->setText(QCoreApplication::translate("editContactDialog", "Invalid input to phone numbers!", nullptr));
        emptyNumber->setText(QCoreApplication::translate("editContactDialog", "The number is empty!", nullptr));
        emptyName->setText(QCoreApplication::translate("editContactDialog", "The name is empty!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editContactDialog: public Ui_editContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCONTACTDIALOG_H
