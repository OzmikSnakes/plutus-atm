#pragma once
#include <QJsonObject>
#include <QNetworkReply>

#include "rest_communication/converter.h"

using std::string;

class ErrorInfo : public FromJsonFillable
{
    void fill(const QJsonObject&) override;
public:
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

class CreditTariffInfo : public FromJsonFillable
{
    void fill(const QJsonObject&) override;
public:
    long id;
    double percent;
    double limit;
};

class ClientInfo
{
public:
    long id;
    QString name;
    QString surname;
    long createdWhen;
};

class TransferInfo : public FromJsonFillable
{
    void fill(const QJsonObject&) override;
public:
    long id;
    long fromId;
    long toId;
    QString transferStatus;
    double amount;
    long createdWhen;
    QString description;
};

