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
    void onOKButtonClicked();
    void onAddNumberButtonClicked();

private:
    Ui::addContactDialog *ui;
    void addNumberWidget(int number);
    bool isNumbersUnique(const QList<QWidget*> numbersToAdd);
    MainWindow *mainWindowRef;
    QLabel *emptyName;
    QLabel *emptyNumber;
    QLabel *wrongNumber;
};

#endif // ADDCONTACTDIALOG_H
