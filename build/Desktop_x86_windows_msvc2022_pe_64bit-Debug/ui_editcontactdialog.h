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
    QPushButton *OKButon;
    QScrollArea *scrollArea;
    QWidget *scrollAreaNumbers;
    QPushButton *addNumberButton;

    void setupUi(QDialog *editContactDialog)
    {
        if (editContactDialog->objectName().isEmpty())
            editContactDialog->setObjectName("editContactDialog");
        editContactDialog->resize(614, 337);
        nameLine = new QLineEdit(editContactDialog);
        nameLine->setObjectName("nameLine");
        nameLine->setGeometry(QRect(141, 30, 431, 22));
        nameLabel = new QLabel(editContactDialog);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(40, 30, 95, 22));
        QFont font;
        font.setFamilies({QString::fromUtf8("Franklin Gothic Book")});
        font.setPointSize(12);
        nameLabel->setFont(font);
        OKButon = new QPushButton(editContactDialog);
        OKButon->setObjectName("OKButon");
        OKButon->setGeometry(QRect(110, 250, 131, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Franklin Gothic Book")});
        font1.setPointSize(14);
        OKButon->setFont(font1);
        scrollArea = new QScrollArea(editContactDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(40, 70, 531, 141));
        scrollArea->setWidgetResizable(true);
        scrollAreaNumbers = new QWidget();
        scrollAreaNumbers->setObjectName("scrollAreaNumbers");
        scrollAreaNumbers->setGeometry(QRect(0, 0, 529, 139));
        scrollArea->setWidget(scrollAreaNumbers);
        addNumberButton = new QPushButton(editContactDialog);
        addNumberButton->setObjectName("addNumberButton");
        addNumberButton->setGeometry(QRect(330, 250, 161, 41));
        addNumberButton->setFont(font);

        retranslateUi(editContactDialog);

        QMetaObject::connectSlotsByName(editContactDialog);
    } // setupUi

    void retranslateUi(QDialog *editContactDialog)
    {
        editContactDialog->setWindowTitle(QCoreApplication::translate("editContactDialog", "Edit the contact", nullptr));
        nameLabel->setText(QCoreApplication::translate("editContactDialog", "Contact Name", nullptr));
        OKButon->setText(QCoreApplication::translate("editContactDialog", "OK", nullptr));
        addNumberButton->setText(QCoreApplication::translate("editContactDialog", "+ Add another number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editContactDialog: public Ui_editContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCONTACTDIALOG_H
