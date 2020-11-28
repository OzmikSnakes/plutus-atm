#pragma once
#include <QString>
#include <optional>
#include "rest_communication/converter.h"

class EmptyRequest final : public JsonSchemaAware {
	QVariantMap toQVariantMap() const override;
};

class MakeTransferRequest final : public JsonSchemaAware
{
	QVariantMap toQVariantMap() const override;
public:
    std::string toId;
    std::optional<long> fromId;
	double amount;
    std::optional<std::string> description;
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
