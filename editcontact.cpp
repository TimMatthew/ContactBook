#include "editcontact.h"
#include "ui_editcontact.h"

editContact::editContact(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editContact)
{
    ui->setupUi(this);
}

editContact::~editContact()
{
    delete ui;
}
