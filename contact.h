#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QVector>

class Contact
{
private:
    QString _contact_name;
    QVector<QString> _phone_numbers;

public:
    Contact() = default;
    Contact(const QString& name, const QVector<QString>& numbers);
    QString getContactName() const;
    QVector<QString> getPhoneNumbers() const;
    void setContactName(const QString& contact_name);
    void setPhoneNumbers(const QVector<QString>& phone_numbers);
};

#endif // CONTACT_H
