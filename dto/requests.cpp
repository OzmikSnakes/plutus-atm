#include <QJsonDocument>
#include "requests.h"

// todo: think if public fields are cool
// TODO: think about setter exceptions
QVariantMap JsonSchemaAware::jsonSchema() const
{
	return toQVariantMap();
}

QVariantMap EmptyRequest::toQVariantMap() const
{
	return QVariantMap{};
}

QVariantMap MakeTransferRequest::toQVariantMap() const
{
	QVariantMap map;
    map["toId"] = QString::fromStdString(toId);
    if(fromId.has_value()){
        map["fromId"] = QString::number(fromId.value());
    }
	map["amount"] = amount;
    if(description.has_value()){
        map["description"] = QString::fromStdString(description.value());
    }
	return map;
}

QVariantMap ATMTokenRequest::toQVariantMap() const
{
	QVariantMap map;
	map["accountNumber"] = QString::fromStdString(accountNumber);
	map["pin"] = QString::fromStdString(pin);
	return map;
}

QVariantMap ChangeBalanceRequest::toQVariantMap() const
{
	QVariantMap map;
	map["accountNumber"] = QString::number(accountId);
	map["amount"] = amount;
	return map;
}

QVariantMap CreateAutomaticTransferRequest::toQVariantMap() const
{
	QVariantMap map;
	map["toId"] = QString::number(toId);
	map["fromId"] = QString::number(fromId);
	map["name"] = QString::fromStdString(name);
	map["description"] = QString::fromStdString(description);
	map["nextPaymentTime"] = QString::number(nextPaymentTime);
	map["period"] = QString::number(period);
	map["transferAmount"] = transferAmount;
	map["toPayAmount"] = toPayAmount;
	return map;
}
