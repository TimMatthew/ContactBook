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
    //connect(this, &MainWindow::contactWidgetClicked, this, &MainWindow::onContactWidgetClicked);
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
                                 "font-size: 10pt;"
                                 "border: 2px solid lightblue;"
                                 "margin: 5px}");
    QVBoxLayout *widgetLayout = new QVBoxLayout(contactWidget);

    QLabel *nameLabel = new QLabel(newContact.getContactName());
    nameLabel->setStyleSheet("QLabel{border: 0px; margin: 2px}");
    widgetLayout->addWidget(nameLabel);

    int width=410, height=60, amount=1;

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

    return contactWidget;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
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
    connect(&ecd, &editContactDialog::contactUpdated, this, &MainWindow::onUpdateContact);
    ecd.setContact(contact);
    ecd.setModal(true);
    ecd.exec();
}

void MainWindow::onUpdateContact(const Contact &updatedContact)
{
    // Find the contact widget associated with the updated contact
    for (auto it = contactWidgetsMap.begin(); it != contactWidgetsMap.end(); ++it) {
        if (it.value().getContactName() == updatedContact.getContactName()) {
            // Update the contact in the map
            it.value().setPhoneNumbers(updatedContact.getPhoneNumbers());

            // Update the contact widget
            ContactWidget *contactWidget = qobject_cast<ContactWidget*>(it.key());
            if (contactWidget) {
                contactWidget->deleteLater();
                QWidget *newContactWidget = createContactWidget(updatedContact);
                contactsLayout->replaceWidget(contactWidget, newContactWidget);
                contactWidget->hide();
            }
            break;
        }
    }
}
