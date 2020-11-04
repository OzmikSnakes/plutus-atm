#ifndef RESPONSES_H
#define RESPONSES_H

#include <QString>

using std::string;

class CreditTariffInfo
{
public:
    long getId() const;
    CreditTariffInfo& setId(long value);

    double getPercent() const;
    CreditTariffInfo& setPercent(double value);

    double getLimit() const;
    CreditTariffInfo& setLimit(double value);

    long getCreatedWhen() const;
    CreditTariffInfo& setCreatedWhen(long value);

private:
    long id;
    double percent;
    double limit;
    long createdWhen;
};



class ClientInfo
{
public:
    long getId() const;
    ClientInfo& setId(long value);

    QString getName() const;
    ClientInfo& setName(const QString &value);

    QString getSurname() const;
    ClientInfo& setSurname(const QString &value);

    long getCreatedWhen() const;
    ClientInfo& setCreatedWhen(long value);

private:
    long id;
    QString name;
    QString surname;
    long createdWhen;
};

#endif // RESPONSES_H
