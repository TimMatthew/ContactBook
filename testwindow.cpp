#include "testwindow.h"
#include "ui_testwindow.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>

TestWindow::TestWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestWindow)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(ui->centralwidget); // Use centralWidget for layout

    // Create the scroll area
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet("QScrollArea { border: 1px solid #ccc; }");

    // Create a widget to hold the scroll area content
    QWidget *scrollContent = new QWidget();
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollContent);

    // Add several widgets each with 3 labels
    for (int i = 0; i < 10; ++i) {
        QWidget *widget = new QWidget();
        QVBoxLayout *widgetLayout = new QVBoxLayout(widget);
        widget->setStyleSheet("QWidget { background-color: #f9f9f9; border: 1px solid #ddd; border-radius: 5px; margin: 5px; padding: 10px; }");

        QLabel *label1 = new QLabel(QString("Label 1 in Widget %1").arg(i+1));
        QLabel *label2 = new QLabel(QString("Label 2 in Widget %1").arg(i+1));
        QLabel *label3 = new QLabel(QString("Label 3 in Widget %1").arg(i+1));

        widgetLayout->addWidget(label1);
        widgetLayout->addWidget(label2);
        widgetLayout->addWidget(label3);

        scrollLayout->addWidget(widget);
    }

    // Set the scroll content widget to the scroll area
    scrollArea->setWidget(scrollContent);

    // Add the scroll area to the main layout
    mainLayout->addWidget(scrollArea);
}

TestWindow::~TestWindow()
{
    delete ui;
}
