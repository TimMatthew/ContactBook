#include "editcontactdialog.h"
#include "ui_editcontactdialog.h"
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QRegularExpression>

editContactDialog::editContactDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editContactDialog)
{
    ui->setupUi(this);
    ui->scrollAreaNumbers->setStyleSheet("QScrollArea{"
                                         "border: 1px solid black,"
                                         "border-radius: 10px;}");

    emptyName = ui->emptyName;
    emptyNumber = ui->emptyNumber;
    wrongNumber = ui->wrongNumber;

    emptyName->hide();
    emptyNumber->hide();
    wrongNumber->hide();
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
        numberLine->setObjectName(QString("numberLine%1").arg(i));
        numberLayout->addWidget(numberLine);

        if (i > 1) {
            QPushButton *removeButton = new QPushButton("X", newNumberWidget);
            removeButton->setObjectName(QString("removeButton%1").arg(i));
            removeButton->setFixedSize(20, 20);
            numberLayout->addWidget(removeButton);

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
    QRegularExpression qre("\\p{L}");

    bool isAllright=true;

    if(updatedName.isEmpty()){
        isAllright=false;
        wrongNumber->hide();
        emptyNumber->hide();
        emptyName->show();
    }
    else{
        int i = 1;
        while (true) {
            QLineEdit *numberLine = findChild<QLineEdit *>(QString("numberLine%1").arg(i));
            if (!numberLine) {
                break;
            }
            if(numberLine->text().isEmpty()){

                isAllright = false;
                wrongNumber->hide();
                emptyNumber->show();
                emptyName->hide();
                break;
            }
            else if(numberLine->text().contains(qre)){

                isAllright = false;
                wrongNumber->show();
                emptyNumber->hide();
                emptyName->hide();
                break;
            }
            else{
                isAllright=true;
                updatedNumbers.append(numberLine->text());
            }
            i++;
        }
    }

    if(isAllright){
        contactToEdit.setContactName(updatedName);
        contactToEdit.setPhoneNumbers(updatedNumbers);

        emit contactUpdated(contactToEdit, this);
        accept();
    }

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


    QPushButton *removeButton = new QPushButton("X", newNumberWidget);
    removeButton->setObjectName(QString("removeButton%1").arg(numberIndex));
    removeButton->setFixedSize(20, 20);
    numberLayout->addWidget(removeButton);

    connect(removeButton, &QPushButton::clicked, [=]() {
        delete newNumberWidget;
    });

    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaNumbers->layout());
    layout->addWidget(newNumberWidget);
}
