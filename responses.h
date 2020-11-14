#pragma once

#include <QString>

#include "converter.h"

using std::string;

class TokenInfo : public ToJsonConvertable
{
	QVariantMap toQVariantMap() const override;
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

