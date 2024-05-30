#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addcontactdialog.h"
#include "editcontactdialog.h"
#include "contactwidget.h"
#include "contact.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap searchIcon(":/data/search_icon_small.png");
    int searchIconW = ui->searchImage->width();
    int searchIconH = ui->searchImage->height();
    ui->searchImage->setPixmap(searchIcon.scaled(searchIconW, searchIconH, Qt::KeepAspectRatio));

    contactsLayout = new QVBoxLayout();
    contactsLayout->setAlignment(Qt::AlignTop);
    ui->scrollAreaContacts->setLayout(contactsLayout);
    ui->searchImage->installEventFilter(this);

    // QLabel *noContactsLabel = new QLabel("No contacts so far...");
    // noContactsLabel->setStyleSheet("QLabel{"
    //                                "font: Franklin Gothic Book;"
    //                              "font-size: 13pt;}");

    // contactsLayout->addWidget(noContactsLabel);
    // noContactsLabel->setGeometry(110,200,200,200);


    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveContactsToFile);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openContactsFromFile);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QWidget* MainWindow::createContactWidget(const Contact& newContact, const bool isToAdd)
{
    QWidget *contactWidget = new QWidget();
    contactWidget->setStyleSheet(""
                                 "QWidget { background-color: #f9f9f9; "
                                 "border-radius: 14px;"
                                 "font: Franklin Gothic Book;"
                                 "font-size: 11pt;"
                                 "border: 2px solid lightblue;"
                                 "margin: 5px;"
                                 "padding-left: 8px;}");

    QVBoxLayout *widgetLayout = new QVBoxLayout();
    contactWidget->setLayout(widgetLayout);

    QLabel *nameLabel = new QLabel(newContact.getContactName());
    nameLabel->setStyleSheet("QLabel{border: 0px; margin: 2px}");
    widgetLayout->addWidget(nameLabel);

    int width = 420, height = 70, amount = 1;

    for (const QString &phoneNumber : newContact.getPhoneNumbers()) {
        QLabel *phoneLabel = new QLabel(phoneNumber);
        phoneLabel->setStyleSheet("QLabel{border: 0px; margin: 2px}");
        widgetLayout->addWidget(phoneLabel);
        if (amount > 1) height += 40;
        amount++;
    }

    contactWidget->setFixedSize(width, height);
    contactWidget->installEventFilter(this);

    if(isToAdd)
        contactWidgetsMap[contactWidget] = newContact;

    return contactWidget;
}


bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{

    if(obj == ui->searchImage && event->type() == QEvent::MouseButtonPress){
        onSearchImageClicked();
        return true;
    }
    if (event->type() == QEvent::MouseButtonPress) {
        QWidget *clickedWidget = qobject_cast<QWidget*>(obj);
        if (clickedWidget) {
            onContactWidgetClicked(clickedWidget);
            return true;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}


void MainWindow::onAddButtonClicked()
{
    addContactDialog acd(this);
    acd.setModal(true);
    acd.exec();
}

void MainWindow::onContactWidgetClicked(QWidget *contactWidget)
{
    Contact contact = contactWidgetsMap[contactWidget];
    editContactDialog ecd(this);
    connect(&ecd, &editContactDialog::contactUpdated, this, [=](const Contact &updatedContact) {
        updateContact(updatedContact, contactWidget);
    });
    connect(&ecd, &editContactDialog::contactDeleted, this, [=](const Contact &deletedContact) {
        deleteContact(deletedContact, contactWidget);
    });
    ecd.setContact(contact);
    ecd.setModal(true);
    ecd.exec();
}

void MainWindow::onSearchImageClicked() {
    QString searchPrompt = ui->searchLine->text();
    QList<QWidget*> contactsMatched;

    for (QMap<QWidget*, Contact>::const_iterator it = contactWidgetsMap.constBegin(); it != contactWidgetsMap.constEnd(); ++it) {
        Contact contact = it.value();

        bool contactMatches = false;

        if (contact.getContactName().contains(searchPrompt, Qt::CaseInsensitive)) {
            contactMatches = true;
        } else {
            QVector<QString> contactNumbers = contact.getPhoneNumbers();
            for (const QString &number : contactNumbers) {
                if (number.startsWith(searchPrompt)) {
                    contactMatches = true;
                    break;
                }
            }
        }

        if (contactMatches) {
            contactsMatched.append(it.key());
        }
    }

    for (QMap<QWidget*, Contact>::const_iterator it = contactWidgetsMap.constBegin(); it != contactWidgetsMap.constEnd(); ++it) {
        QWidget *contactWidget = it.key();
        if (contactsMatched.contains(contactWidget)) {
            contactWidget->show();
        } else {
            contactWidget->hide();
        }
    }
}


void MainWindow::deleteContact(const Contact &deletedContact, QWidget *contactWidgetToDelete){

    contactWidgetsMap.remove(contactWidgetToDelete);
    contactsLayout->removeWidget(contactWidgetToDelete);
    contactWidgetToDelete->deleteLater();
}

void MainWindow::updateContact(const Contact &updatedContact, QWidget *contactWidget)
{
    QWidget *newContactWidget = createContactWidget(updatedContact, 0);

    contactWidgetsMap.remove(contactWidget);
    contactsLayout->replaceWidget(contactWidget, newContactWidget);
    contactWidgetsMap[newContactWidget] = updatedContact;
    contactWidget->deleteLater();
}


void MainWindow::saveContactsToFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Contacts"),
                                                    QDir::homePath(),
                                                    tr("JSON Files (*.json)"));

    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, tr("Error"), tr("Failed to save contacts."));
        return;
    }

    QJsonArray contactsArray;

    for (QMap<QWidget*, Contact>::const_iterator it = contactWidgetsMap.constBegin(); it != contactWidgetsMap.constEnd(); ++it) {
        const Contact &c = it.value();
        QJsonObject contactObject;
        contactObject["name"] = c.getContactName();
        QJsonArray phoneNumbersArray;

        const QVector<QString> phoneNumbers = c.getPhoneNumbers();
        for (QVector<QString>::const_iterator numIt = phoneNumbers.constBegin(); numIt != phoneNumbers.constEnd(); ++numIt) {
            const QString &phoneNumber = *numIt;
            phoneNumbersArray.append(phoneNumber);
        }

        contactObject["phoneNumbers"] = phoneNumbersArray;
        contactsArray.append(contactObject);
    }

    QJsonDocument jsonDoc(contactsArray);
    QTextStream out(&file);
    out << jsonDoc.toJson();
    file.close();
}

void MainWindow::openContactsFromFile() {

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Contacts"),
                                                    QDir::homePath(),
                                                    tr("JSON Files (*.json)"));

    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("Error"), tr("Failed to open contacts file."));
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull() || !jsonDoc.isArray()) {
        QMessageBox::warning(this, tr("Error"), tr("Invalid JSON format."));
        return;
    }

    contactWidgetsMap.clear();
    QList<QWidget*> widgetsList = ui->scrollAreaContacts->findChildren<QWidget*>();
    for (QList<QWidget*>::const_iterator widget = widgetsList.constBegin(); widget != widgetsList.constEnd(); ++widget) {
        (*widget)->deleteLater();
    }

    QJsonArray contactsArray = jsonDoc.array();

    for (const QJsonValue &contactValue : contactsArray) {
        if (!contactValue.isObject())
            continue;

        QJsonObject contactObject = contactValue.toObject();
        QString contactName = contactObject["name"].toString();
        QJsonValue phoneNumbersValue = contactObject["phoneNumbers"];

        if (!phoneNumbersValue.isArray())
            continue;

        QJsonArray phoneNumbersArray = phoneNumbersValue.toArray();
        QVector<QString> phoneNumbers;
        for (const QJsonValue &phoneNumberValue : phoneNumbersArray) {
            if (phoneNumberValue.isString()) {
                phoneNumbers.append(phoneNumberValue.toString());
            }
        }

        Contact contact(contactName, phoneNumbers);
        QWidget *contactWidget = createContactWidget(contact, 1);
        contactsLayout->addWidget(contactWidget);
    }
}

