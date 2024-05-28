#ifndef ADDCONTACTWINDOW_H
#define ADDCONTACTWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QEvent>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QGraphicsColorizeEffect>

class addContactWindow : public QMainWindow
{
public:
    addContactWindow(QWidget *parent = nullptr);
};

#endif // ADDCONTACTWINDOW_H
