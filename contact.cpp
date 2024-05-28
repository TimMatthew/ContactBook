#include "contact.h"

Contact::Contact(const QString& name, const QVector<QString>& numbers):
    _contact_name(name), _phone_numbers(numbers)
{

}
QString Contact::getContactName() const
{
    return _contact_name;
}

QVector<QString> Contact::getPhoneNumbers() const
{
    return _phone_numbers;
}

void Contact::setContactName(const QString& contact_name)
{
    _contact_name = contact_name;
}

void Contact::setPhoneNumbers(const QVector<QString>& phone_numbers)
{
    _phone_numbers = phone_numbers;
}
