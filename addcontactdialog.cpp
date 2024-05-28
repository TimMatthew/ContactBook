#include "addcontactdialog.h"
#include "ui_addcontactdialog.h"
#include "mainwindow.h"
#include "contact.h"
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

addContactDialog::addContactDialog(MainWindow *mainWindow, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addContactDialog),
    mainWindowRef(mainWindow)
{
    ui->setupUi(this);

    // Create a layout for the scroll area content
    QVBoxLayout *layout = new QVBoxLayout(ui->scrollAreaNumbers);
    layout->setAlignment(Qt::AlignTop);
    ui->scrollAreaNumbers->setLayout(layout);

    addNumberWidget(1);
}

addContactDialog::~addContactDialog()
{
    delete ui;
}

void addContactDialog::on_OKButton_clicked()
{
    QString name = ui->nameLine->text();
    QVector<QString> phoneNumbers;
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaNumbers->layout());
    for (int i = 0; i < layout->count(); ++i)
    {
        QWidget *widget = layout->itemAt(i)->widget();
        if (widget)
        {
            QLineEdit *lineEdit = widget->findChild<QLineEdit *>();
            if (lineEdit)
            {
                QString phoneNumber = lineEdit->text();
                phoneNumbers.append(phoneNumber);
            }
        }
    }
    Contact newContact(name, phoneNumbers);

    QWidget *contactWidget = mainWindowRef->createContactWidget(newContact);
    mainWindowRef->contactsLayout->addWidget(contactWidget);

    hide();
}

void addContactDialog::on_addNumberButton_clicked()
{
    // Add a new number widget
    addNumberWidget(ui->scrollAreaNumbers->layout()->count() + 1);
}

void addContactDialog::addNumberWidget(int number)
{
    // Create new numberWidget
    QWidget *newNumberWidget = new QWidget(ui->scrollAreaNumbers);
    newNumberWidget->setFixedSize(441, 41); // Set the same size as the original

    // Create and configure the new label
    QLabel *newLabel = new QLabel(newNumberWidget);
    newLabel->setGeometry(10, 10, 124, 22);
    newLabel->setFont(QFont("Franklin Gothic Book", 12));
    newLabel->setText(QString("Phone Number #%1").arg(number));

    // Create and configure the new line edit
    QLineEdit *newLineEdit = new QLineEdit(newNumberWidget);
    newLineEdit->setGeometry(140, 10, 291, 22);

    // Add the new numberWidget to the scroll area layout
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaNumbers->layout());
    layout->addWidget(newNumberWidget);

    // Adjust the scroll area's widget size to fit new content
    ui->scrollAreaNumbers->adjustSize();
}
