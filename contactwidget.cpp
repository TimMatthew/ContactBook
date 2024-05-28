#include "contactwidget.h"

ContactWidget::ContactWidget(const QString &contactName, const QVector<QString> &phoneNumbers, QWidget *parent)
    : QWidget()
{

    setStyleSheet(
        "QWidget { background-color: white; "
        "border-radius: 14px; "
        "font: Franklin Gothic Book; "
        "font-size: 10pt; "
        "border: 2px solid lightblue; "
        "margin: 5px; }"
        );

    // Create layout
    layout = new QVBoxLayout(this);

    // Create and add the contact name label
    nameLabel = new QLabel(contactName, this);
    nameLabel->setStyleSheet("QLabel{border: 0px; margin: 2px;}");
    layout->addWidget(nameLabel);

    // Create and add phone number labels
    for (const QString &phoneNumber : phoneNumbers) {
        QLabel *phoneLabel = new QLabel(phoneNumber, this);
        phoneLabel->setStyleSheet("QLabel{border: 0px; margin: 2px;}");
        layout->addWidget(phoneLabel);
        phoneNumberLabels.append(phoneLabel);
    }

    setLayout(layout);
}
