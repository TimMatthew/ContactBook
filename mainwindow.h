#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMap>
#include <QLabel>
#include<QLineEdit>
#include <QDebug>
#include <QMouseEvent>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
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
    QWidget* createContactWidget(const Contact& newContact, const bool isToAdd);
    ~MainWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *e) override;

private slots:
    void onAddButtonClicked();
    void onContactWidgetClicked(QWidget *contactWidget);
    void updateContact(const Contact &updatedContact, QWidget *contactWidget);
    void deleteContact(const Contact &updatedContact, QWidget *contactWidget);
    void onSearchImageClicked();
    void saveContactsToFile();
    void openContactsFromFile();

private:
    QLabel *noContactsLabel;
    QLineEdit *searchField;
    Ui::MainWindow *ui;
    QMap<QWidget*, Contact> contactWidgetsMap;
};

#endif // MAINWINDOW_H
