#ifndef REQUESTS_H
#define REQUESTS_H

#include <QString>
#include "converter.h"

class MakeTransferRequest final : public JsonSchemaAware
{
	QVariantMap toQVariantMap() const override;
public:
    long toId;
	long fromId;
	double amount;
    std::string description;
};


class ATMTokenRequest final : public JsonSchemaAware
{
	QVariantMap toQVariantMap() const override;
public:
    std::string accountNumber;
    std::string pin;
};


class ChangeBalanceRequest final : public JsonSchemaAware
{
	QVariantMap toQVariantMap() const override;
public:
	long accountId;
	double amount;
};

class CreateAutomaticTransferRequest final : public JsonSchemaAware
{
	QVariantMap toQVariantMap() const override;
public:
    std::string name;
	long fromId;
	long toId;
	long period;
	long nextPaymentTime;
	double transferAmount;
	double toPayAmount;
    std::string description;
};

#endif
