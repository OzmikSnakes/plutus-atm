#pragma once

#include <QString>

using std::string;

class CreditTariffInfo
{
public:
    long id;
    double percent;
    double limit;
    long createdWhen;
};



class ClientInfo
{
public:
    long id;
    QString name;
    QString surname;
    long createdWhen;
};

