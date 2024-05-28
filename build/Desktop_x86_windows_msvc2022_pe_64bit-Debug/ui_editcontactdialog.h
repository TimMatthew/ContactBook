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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *deleteButton;
    QPushButton *OKButon;
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
        scrollArea = new QScrollArea(editContactDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(40, 70, 531, 141));
        scrollArea->setWidgetResizable(true);
        scrollAreaNumbers = new QWidget();
        scrollAreaNumbers->setObjectName("scrollAreaNumbers");
        scrollAreaNumbers->setGeometry(QRect(0, 0, 529, 139));
        scrollArea->setWidget(scrollAreaNumbers);
        widget = new QWidget(editContactDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(80, 270, 451, 28));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        deleteButton = new QPushButton(widget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setFont(font);

        horizontalLayout->addWidget(deleteButton);

        OKButon = new QPushButton(widget);
        OKButon->setObjectName("OKButon");
        OKButon->setFont(font);

        horizontalLayout->addWidget(OKButon);

        addNumberButton = new QPushButton(widget);
        addNumberButton->setObjectName("addNumberButton");
        addNumberButton->setFont(font);

        horizontalLayout->addWidget(addNumberButton);


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
    } // retranslateUi

};

namespace Ui {
    class editContactDialog: public Ui_editContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCONTACTDIALOG_H
