#ifndef EDITCONTACTDIALOG_H
#define EDITCONTACTDIALOG_H

#include <QDialog>
#include "contact.h"
#include <QLabel>

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
    void on_addNumberButton_clicked();
    void on_deleteButton_clicked();

signals:
    void contactUpdated(const Contact &contact, QWidget *contactWidget);
    void contactDeleted(const Contact &contact, QWidget *contactWidget);

private:
    Ui::editContactDialog *ui;
    void loadNumbers();
    Contact contactToEdit;
    QLabel *emptyName;
    QLabel *emptyNumber;
    QLabel *wrongNumber;
};

#endif // EDITCONTACTDIALOG_H
