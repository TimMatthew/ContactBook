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
}

MainWindow::~MainWindow()
{
    delete ui;
}

QWidget* MainWindow::createContactWidget(const Contact& newContact)
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
    QVBoxLayout *widgetLayout = new QVBoxLayout(contactWidget);

    QLabel *nameLabel = new QLabel(newContact.getContactName());
    nameLabel->setStyleSheet("QLabel{border: 0px; margin: 2px}");
    widgetLayout->addWidget(nameLabel);

    int width=420, height=70, amount=1;

    for (const QString &phoneNumber : newContact.getPhoneNumbers()) {

        QLabel *phoneLabel = new QLabel(phoneNumber);
        phoneLabel->setStyleSheet("QLabel{border: 0px; margin: 2px}");
        widgetLayout->addWidget(phoneLabel);
        if(amount>1) height+=40;
        amount++;
    }
    contactWidget->setFixedSize(width, height);
    contactWidget->installEventFilter(this);

    contactWidgetsMap[contactWidget] = newContact;

    ui->noContactsLabel->hide();
    return contactWidget;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{

    if(obj == ui->searchImage && event->type() == QEvent::MouseButtonPress){
        on_searchImage_clicked();
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


void MainWindow::on_addButton_clicked()
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

void MainWindow::on_searchImage_clicked() {
    QString searchPrompt = ui->searchLine->text();
    QList<QWidget*> contactsMatched;

    for (auto it = contactWidgetsMap.constBegin(); it != contactWidgetsMap.constEnd(); ++it) {
        Contact contact = it.value();

        bool contactMatches = false;

        if (contact.getContactName().contains(searchPrompt, Qt::CaseInsensitive)) {
            contactMatches = true;
        }
        else {
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

    // Show or hide contacts based on the search result
    for (auto it = contactWidgetsMap.constBegin(); it != contactWidgetsMap.constEnd(); ++it) {
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

    if(contactWidgetsMap.empty()) ui->noContactsLabel->show();
}

void MainWindow::updateContact(const Contact &updatedContact, QWidget *contactWidget)
{
    contactWidgetsMap[contactWidget] = updatedContact;
    QWidget *newContactWidget = createContactWidget(updatedContact);
    contactsLayout->replaceWidget(contactWidget, newContactWidget);
    contactWidget->deleteLater();
}
