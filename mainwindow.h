#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMap>
#include <QLabel>
#include<QLineEdit>
#include "contact.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QVBoxLayout *contactsLayout;
    MainWindow(QWidget *parent = nullptr);
    QWidget* createContactWidget(const Contact& newContact);
    ~MainWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_addButton_clicked();
    void onContactWidgetClicked(QWidget *contactWidget);
    void updateContact(const Contact &updatedContact, QWidget *contactWidget);
    void deleteContact(const Contact &updatedContact, QWidget *contactWidget);

private:
    QLabel *noContactsLabel;
    QLineEdit *searchField;
    Ui::MainWindow *ui;
    QMap<QWidget*, Contact> contactWidgetsMap;
};

#endif // MAINWINDOW_H
