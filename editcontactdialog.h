#ifndef EDITCONTACTDIALOG_H
#define EDITCONTACTDIALOG_H

#include <QDialog>
#include "contact.h"

namespace Ui {
class editContactDialog;
}

class editContactDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editContactDialog(QWidget *parent = nullptr);
    ~editContactDialog();
    void setContact (const Contact& contact);

private slots:
    void on_OKButon_clicked();

signals:
    void contactUpdated(const Contact &contact);
private:
    Ui::editContactDialog *ui;
    void loadNumbers();
    Contact contactToEdit;
};

#endif // EDITCONTACTDIALOG_H
