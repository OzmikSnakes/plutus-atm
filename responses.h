#pragma once
#include <QJsonObject>
#include "converter.h"

using std::string;

class ErrorInfo : public FromJsonFillable
{
    void fill(const QJsonObject&) override;
public:
	// todo make normal http status
    size_t status;
    QString error;
    QString message;
};

class TokenInfo : public FromJsonFillable
{
	void fill(const QJsonObject&) override;
public:
    QString token;
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

