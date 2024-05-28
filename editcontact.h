#ifndef EDITCONTACT_H
#define EDITCONTACT_H

#include <QDialog>

namespace Ui {
class editContact;
}

class editContact : public QDialog
{
    Q_OBJECT

public:
    explicit editContact(QWidget *parent = nullptr);
    ~editContact();

private:
    Ui::editContact *ui;
};

#endif // EDITCONTACT_H
