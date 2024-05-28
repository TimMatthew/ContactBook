/********************************************************************************
** Form generated from reading UI file 'contactwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTWIDGET_H
#define UI_CONTACTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactWidget
{
public:

    void setupUi(QWidget *ContactWidget)
    {
        if (ContactWidget->objectName().isEmpty())
            ContactWidget->setObjectName("ContactWidget");
        ContactWidget->resize(400, 300);

        retranslateUi(ContactWidget);

        QMetaObject::connectSlotsByName(ContactWidget);
    } // setupUi

    void retranslateUi(QWidget *ContactWidget)
    {
        ContactWidget->setWindowTitle(QCoreApplication::translate("ContactWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactWidget: public Ui_ContactWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTWIDGET_H
