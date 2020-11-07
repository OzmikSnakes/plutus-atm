#include <QJsonDocument>

#include "Requests.h"

// todo: think if public fields are cool
// TODO: think about setter exceptions
QVariantMap ToJsonConvertable::jsonSchema() const
{
    return toQVariantMap();
}

QVariantMap MakeTransferRequest::toQVariantMap() const
{
    QVariantMap map = QVariantMap();
    map["toId"] = toId;
    map["fromId"] = fromId;
    map["amount"] = amount;
    map["description"] = description;
    return map;
}

QVariantMap ATMTokenRequest::toQVariantMap() const
{
    QVariantMap map = QVariantMap();
    map["accountId"] = accountId;
    map["pin"] = pin;
    return map;
}

QVariantMap ChangeBalanceRequest::toQVariantMap() const
{
    QVariantMap map = QVariantMap();
    map["accountId"] = accountId;
    map["amount"] = amount;
    return map;
}

QVariantMap CreateAutomaticTransferRequest::toQVariantMap() const
{
    QVariantMap map = QVariantMap();
    map["toId"] = toId;
    map["fromId"] = fromId;
    map["name"] = name;
    map["description"] = description;
    map["nextPaymentTime"] = nextPaymentTime;
    map["period"] = period;
    map["transferAmount"] = transferAmount;
    map["toPayAmount"] = toPayAmount;
    return map;
}

