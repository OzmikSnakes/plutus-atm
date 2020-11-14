#ifndef REQUESTS_H
#define REQUESTS_H

#include <QString>
#include "converter.h"

class MakeTransferRequest final : public ToJsonConvertable
{
	QVariantMap toQVariantMap() const override;
public:
    long toId;
	long fromId;
	double amount;
    std::string description;
};


class ATMTokenRequest final : public ToJsonConvertable
{
	QVariantMap toQVariantMap() const override;
public:
    std::string accountId;
    std::string pin;
};


class ChangeBalanceRequest final : public ToJsonConvertable
{
	QVariantMap toQVariantMap() const override;
public:
	long accountId;
	double amount;
};

class CreateAutomaticTransferRequest final : public ToJsonConvertable
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
