#include "addcontactdialog.h"
#include "ui_addcontactdialog.h"
#include "mainwindow.h"
#include "contact.h"
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QRegularExpression>

addContactDialog::addContactDialog(MainWindow *mainWindow, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addContactDialog),
    mainWindowRef(mainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout(ui->scrollAreaNumbers);
    layout->setAlignment(Qt::AlignTop);
    ui->scrollAreaNumbers->setLayout(layout);

    emptyName = ui->emptyName;
    emptyNumber = ui->emptyNumber;
    wrongNumber = ui->wrongNumber;

    emptyName->hide();
    emptyNumber->hide();
    wrongNumber->hide();

    addNumberWidget(1);
}

addContactDialog::~addContactDialog()
{
    delete ui;
}

void addContactDialog::onOKButtonClicked()
{

    QString name = ui->nameLine->text();
    QVector<QString> phoneNumbers;
    bool isAllright = true;
    QRegularExpression qre("\\p{L}");


    if(name.isEmpty()){
        isAllright=false;
        wrongNumber->hide();
        emptyNumber->hide();
        emptyName->show();
    }
    else{

        QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaNumbers->layout());

        bool isAllright = true;
        for (int i = 0; i < layout->count(); ++i)
        {
            QWidget *widget = layout->itemAt(i)->widget();
            if (widget)
            {
                QLineEdit *lineEdit = widget->findChild<QLineEdit *>();
                if (lineEdit)
                {
                    QString phoneNumber = lineEdit->text();

                    if(phoneNumber.isEmpty()){

                        isAllright=false;
                        wrongNumber->hide();
                        emptyName->hide();
                        emptyNumber->show();
                        break;
                    }
                    else if(phoneNumber.contains(qre)){

                        isAllright=false;
                        wrongNumber->show();
                        emptyName->hide();
                        emptyNumber->hide();
                        break;
                    }
                    else phoneNumbers.append(phoneNumber);
                }
            }
        }

        if(isAllright){
            Contact newContact(name, phoneNumbers);
            QWidget *contactWidget = mainWindowRef->createContactWidget(newContact, 1);
            mainWindowRef->contactsLayout->addWidget(contactWidget);

            hide();
        }
    }
}

void addContactDialog::onAddNumberButtonClicked()
{
    addNumberWidget(ui->scrollAreaNumbers->layout()->count() + 1);
}

void addContactDialog::addNumberWidget(int number)
{
    QWidget *newNumberWidget = new QWidget(ui->scrollAreaNumbers);
    newNumberWidget->setFixedSize(441, 41);

    QLabel *newLabel = new QLabel(newNumberWidget);
    newLabel->setGeometry(10, 10, 124, 22);
    newLabel->setFont(QFont("Franklin Gothic Book", 12));
    newLabel->setText(QString("Phone Number #%1").arg(number));

    QLineEdit *newLineEdit = new QLineEdit(newNumberWidget);
    newLineEdit->setGeometry(140, 10, 291, 22);

    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaNumbers->layout());
    layout->addWidget(newNumberWidget);
}

bool addContactDialog::isNumbersUnique(const QList<QWidget*> numbersToAdd){
    return true;
}
