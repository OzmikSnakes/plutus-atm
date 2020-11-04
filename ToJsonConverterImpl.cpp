#include "ToJsonConverter.h"
#include "Requests.h"
#include <QString>
#include <QObject>
#include <QVariant>
#include <QJsonDocument> 

QVariantMap MakeTransferRequestToJsonConverter::toQVariantMap(const MakeTransferRequest& value)
{
    QVariantMap map = QVariantMap();
    map["toId"] = QVariant((qlonglong) value.getToId());
    map["fromId"] = QVariant((qlonglong) value.getFromId());
    map["amount"] = QVariant(value.getAmount());
    map["description"] = QVariant(value.getDescription());
    return map;
}

QByteArray MakeTransferRequestToJsonConverter::toJson(const MakeTransferRequest& value)
{

    return QJsonDocument::fromVariant(toQVariantMap(value)).toJson();
}

QVariantMap ATMTokenRequestToJsonConverter::toQVariantMap(const ATMTokenRequest& value)
{
    QVariantMap map = QVariantMap();
    map["atmKey"] = QVariant(value.getAtmKey());
    map["accountId"] = QVariant(value.getAccountId());
    map["pin"] = QVariant(value.getPin());
    return map;
}

QByteArray ATMTokenRequestToJsonConverter::toJson(const ATMTokenRequest& value)
{

    return QJsonDocument::fromVariant(toQVariantMap(value)).toJson();
}

QVariantMap CreateAccountRequestToJsonConverter::toQVariantMap(const CreateAccountRequest& value)
{
    QVariantMap map = QVariantMap();
    map["userId"] = QVariant((qlonglong) value.getUserId());
    map["tariffId"] = QVariant((qlonglong) value.getTarrifId());
    map["pin"] = QVariant(value.getPin());
    return map;
}

QByteArray CreateAccountRequestToJsonConverter::toJson(const CreateAccountRequest& value)
{
    return QJsonDocument::fromVariant(toQVariantMap(value)).toJson();
}

QVariantMap ChangeBalanceRequestToJsonConverter::toQVariantMap(const ChangeBalanceRequest& value)
{
    QVariantMap map = QVariantMap();
    map["accountId"] = QVariant((qlonglong) value.getAccountId());
    map["amount"] = QVariant(value.getAmount());
    return map;
}

QByteArray ChangeBalanceRequestToJsonConverter::toJson(const ChangeBalanceRequest& value)
{
    return QJsonDocument::fromVariant(toQVariantMap(value)).toJson();
}

QVariantMap AssignCreditTariffToAccountRequestToJsonConverter::toQVariantMap(const AssignCreditTariffToAccountRequest& value)
{
    QVariantMap map = QVariantMap();
    map["accountId"] = QVariant((qlonglong) value.getAccountId());
    map["tariffId"] = QVariant((qlonglong) value.getTariffId());
    return map;
}

QByteArray AssignCreditTariffToAccountRequestToJsonConverter::toJson(const AssignCreditTariffToAccountRequest& value)
{
    return QJsonDocument::fromVariant(toQVariantMap(value)).toJson();
}

QVariantMap CreateClientRequestToJsonConverter::toQVariantMap(const CreateClientRequest& value)
{
    QVariantMap map = QVariantMap();
    map["name"] = QVariant(value.getName());
    map["surname"] = QVariant(value.getSurname());
    return map;
}

QByteArray CreateClientRequestToJsonConverter::toJson(const CreateClientRequest& value)
{
    return QJsonDocument::fromVariant(toQVariantMap(value)).toJson();
}

QVariantMap ModifyOrCreateCreditTariffRequestToJsonConverter::toQVariantMap(const ModifyOrCreateCreditTariffRequest& value)
{
    QVariantMap map = QVariantMap();
    map["tariffId"] = QVariant((qlonglong) value.getId());
    map["limit"] = QVariant(value.getLimit());
    map["name"] = QVariant(value.getName());
    map["percent"] = QVariant(value.getPercent());
    return map;
}

QByteArray ModifyOrCreateCreditTariffRequestToJsonConverter::toJson(const ModifyOrCreateCreditTariffRequest& value)
{
    return QJsonDocument::fromVariant(toQVariantMap(value)).toJson();
}

QVariantMap CreateAutomaticTransferRequestToJsonConverter::toQVariantMap(const CreateAutomaticTransferRequest& value)
{
    QVariantMap map = QVariantMap();
    map["toId"] = QVariant((qlonglong) value.getToId());
    map["fromId"] = QVariant((qlonglong) value.getFromId());
    map["name"] = QVariant(value.getName());
    map["description"] = QVariant(value.getDescription());
    map["nextPaymentTime"] = QVariant((qlonglong) value.getNextPaymentTime());
    map["period"] = QVariant((qlonglong) value.getPeriod());
    map["transferAmount"] = QVariant(value.getTransferAmount());
    map["toPayAmount"] = QVariant(value.getToPayAmount());
    return map;
}

QByteArray CreateAutomaticTransferRequestToJsonConverter::toJson(const CreateAutomaticTransferRequest& value)
{
    return QJsonDocument::fromVariant(toQVariantMap(value)).toJson();
}
