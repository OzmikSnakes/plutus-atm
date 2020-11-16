#pragma once
#include <QJsonObject>
#include "converter.h"

using std::string;

class TokenInfo : public FromJsonFillable
{
	void fill(const QJsonObject&) override;
public:
    std::string token;
};

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

