#include "Responses.h"

long CreditTariffInfo::getId() const { return id; }

CreditTariffInfo& CreditTariffInfo::setId(long value)
{
    id = value;
    return *this;
}

double CreditTariffInfo::getPercent() const { return percent; }

CreditTariffInfo& CreditTariffInfo::setPercent(double value)
{
    percent = value;
    return *this;
}

double CreditTariffInfo::getLimit() const { return limit; }

CreditTariffInfo& CreditTariffInfo::setLimit(double value)
{
    limit = value;
    return *this;
}

long CreditTariffInfo::getCreatedWhen() const { return createdWhen; }

CreditTariffInfo& CreditTariffInfo::setCreatedWhen(long value)
{
    createdWhen = value;
    return *this;
}

long ClientInfo::getId() const { return id; }

ClientInfo& ClientInfo::setId(long value)
{
    id = value;
    return *this;
}

QString ClientInfo::getName() const { return name; }

ClientInfo& ClientInfo::setName(const QString &value)
{
    name = value;
    return *this;
}

QString ClientInfo::getSurname() const { return surname; }

ClientInfo& ClientInfo::setSurname(const QString &value)
{
    surname = value;
    return *this;
}

long ClientInfo::getCreatedWhen() const { return createdWhen; }

ClientInfo& ClientInfo::setCreatedWhen(long value)
{
    createdWhen = value;
    return *this;
}
