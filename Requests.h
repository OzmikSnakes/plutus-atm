#ifndef REQUESTS_H
#define REQUESTS_H

#include <QString>

// TODO: think about structures

class ToJsonConvertable
{
	virtual QVariantMap toQVariantMap() const = 0;
	virtual ~ToJsonConvertable() = default;
public:
	QVariantMap jsonSchema() const;
};

class MakeTransferRequest final : public ToJsonConvertable
{
	QVariantMap toQVariantMap() const override;
public:
	long toId;
	long fromId;
	double amount;
	QString description;
};


class ATMTokenRequest final : public ToJsonConvertable
{
	QVariantMap toQVariantMap() const override;
public:
	QString atmKey;
	QString accountId;
	QString pin;
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
	QString name;
	long fromId;
	long toId;
	long period;
	long nextPaymentTime;
	double transferAmount;
	double toPayAmount;
	QString description;
};

#endif
