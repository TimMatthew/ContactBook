#ifndef ADDCONTACTDIALOG_H
#define ADDCONTACTDIALOG_H
#include "mainwindow.h"

#include <QDialog>

namespace Ui {
class addContactDialog;
}

class addContactDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addContactDialog(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~addContactDialog();

private slots:
    void on_OKButton_clicked();
    void on_addNumberButton_clicked();

private:
    Ui::addContactDialog *ui;
    void addNumberWidget(int number);
    MainWindow *mainWindowRef;
    QLabel *emptyName;
    QLabel *emptyNumber;
    QLabel *wrongNumber;
};

#endif // ADDCONTACTDIALOG_H
