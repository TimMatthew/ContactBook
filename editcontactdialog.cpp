#include "editcontactdialog.h"
#include "ui_editcontactdialog.h"
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLineEdit>

editContactDialog::editContactDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editContactDialog)
{
    ui->setupUi(this);
    setStyleSheet("QDialog{"
                  "background-color: lightgrey;}");
    ui->scrollAreaNumbers->setStyleSheet("QScrollArea{"
                                         "border: 1px solid black,"
                                         "border-radius: 10px;}");
}

editContactDialog::~editContactDialog()
{
    delete ui;
}

void editContactDialog::setContact(const Contact &contact)
{
    contactToEdit = contact;
    ui->nameLine->setText(contactToEdit.getContactName());
    loadNumbers();
}

void editContactDialog::loadNumbers()
{
    QVBoxLayout *layout = new QVBoxLayout(ui->scrollAreaNumbers);
    int i = 1;

    for (const QString &number : contactToEdit.getPhoneNumbers()) {
        QWidget *newNumberWidget = new QWidget(ui->scrollAreaNumbers);
        newNumberWidget->setFixedSize(441, 41);

        QHBoxLayout *numberLayout = new QHBoxLayout(newNumberWidget);

        QLabel *nameLabel = new QLabel(newNumberWidget);
        nameLabel->setFont(QFont("Franklin Gothic Book", 12));
        nameLabel->setText(QString("Phone Number #%1").arg(i));
        numberLayout->addWidget(nameLabel);

        QLineEdit *numberLine = new QLineEdit(number, newNumberWidget);
        numberLine->setObjectName(QString("numberLine%1").arg(i));  // Set object name for later retrieval
        numberLayout->addWidget(numberLine);

        // Add the remove button to all numbers except the first one
        if (i > 1) {
            QPushButton *removeButton = new QPushButton("X", newNumberWidget);
            removeButton->setObjectName(QString("removeButton%1").arg(i));
            removeButton->setFixedSize(20, 20);
            numberLayout->addWidget(removeButton);

            // Connect the remove button's clicked signal to a slot to remove the corresponding number widget
            connect(removeButton, &QPushButton::clicked, [=]() {
                delete newNumberWidget;
            });
        }

        layout->addWidget(newNumberWidget);
        i++;
    }
    ui->scrollAreaNumbers->setLayout(layout);
}


void editContactDialog::on_OKButon_clicked()
{
    QString updatedName = ui->nameLine->text();
    QVector<QString> updatedNumbers;

    // Retrieve the numbers from the line edits
    int i = 1;
    while (true) {
        QLineEdit *numberLine = findChild<QLineEdit *>(QString("numberLine%1").arg(i));
        if (!numberLine) {
            break;
        }
        updatedNumbers.append(numberLine->text());
        i++;
    }

    // Update the contact information
    contactToEdit.setContactName(updatedName);
    contactToEdit.setPhoneNumbers(updatedNumbers);

    // Emit the signal to inform the main window about the update
    emit contactUpdated(contactToEdit, this);


    accept();
}

void editContactDialog::on_deleteButton_clicked()
{
    emit contactDeleted(contactToEdit, this);
    hide();
}

void editContactDialog::on_addNumberButton_clicked()
{
    int numberIndex = ui->scrollAreaNumbers->layout()->count() + 1;

    QWidget *newNumberWidget = new QWidget(ui->scrollAreaNumbers);
    newNumberWidget->setFixedSize(441, 41);

    QHBoxLayout *numberLayout = new QHBoxLayout(newNumberWidget);

    QLabel *nameLabel = new QLabel(newNumberWidget);
    nameLabel->setFont(QFont("Franklin Gothic Book", 12));
    nameLabel->setText(QString("Phone Number #%1").arg(numberIndex));
    numberLayout->addWidget(nameLabel);

    QLineEdit *numberLine = new QLineEdit(newNumberWidget);
    numberLine->setObjectName(QString("numberLine%1").arg(numberIndex));
    numberLayout->addWidget(numberLine);

    // Create a button to remove the number
    QPushButton *removeButton = new QPushButton("X", newNumberWidget);
    removeButton->setObjectName(QString("removeButton%1").arg(numberIndex));
    removeButton->setFixedSize(20, 20);
    numberLayout->addWidget(removeButton);

    // Connect the remove button's clicked signal to a slot to remove the corresponding number widget
    connect(removeButton, &QPushButton::clicked, [=]() {
        delete newNumberWidget;
    });

    // Add the new widget to the scroll area's layout
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaNumbers->layout());
    layout->addWidget(newNumberWidget);
}




