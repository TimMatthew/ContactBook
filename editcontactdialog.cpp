#include "editcontactdialog.h"
#include "ui_editcontactdialog.h"
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

        QLabel *nameLabel = new QLabel(newNumberWidget);
        nameLabel->setGeometry(10, 10, 124, 22);
        nameLabel->setFont(QFont("Franklin Gothic Book", 12));
        nameLabel->setText(QString("Phone Number #%1").arg(i));

        QLineEdit *numberLine = new QLineEdit(number, newNumberWidget);
        numberLine->setObjectName(QString("numberLine%1").arg(i));  // Set object name for later retrieval
        numberLine->setGeometry(140, 10, 291, 22);

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
    emit contactUpdated(contactToEdit);

    accept();
}
