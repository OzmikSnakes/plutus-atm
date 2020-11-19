#pragma once
#include <QJsonObject>
#include <QNetworkReply>

#include "rest_communication/converter.h"

using std::string;

class ErrorInfo : public FromJsonFillable
{
    void fill(const QJsonObject&) override;
public:
	// todo make normal http status
    QNetworkReply::NetworkError status;
    QString error;
    QString message;
};

class TokenInfo : public FromJsonFillable
{
	void fill(const QJsonObject&) override;
public:
    QString token;
};

class AccountInfo : public FromJsonFillable
{
    void fill(const QJsonObject&) override;
public:
    long id;
    QString number;
	//todo decimal
    double moneyAmount;
    long creditTariffId;
    long clientId;
	
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

