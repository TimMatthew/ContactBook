#ifndef CONTACTWIDGET_H
#define CONTACTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class ContactWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ContactWidget(const QString &contactName, const QVector<QString> &phoneNumbers, QWidget *parent = nullptr);

private:
    QLabel *nameLabel;
    QVector<QLabel*> phoneNumberLabels;
    QVBoxLayout *layout;
};

#endif // CONTACTWIDGET_H
