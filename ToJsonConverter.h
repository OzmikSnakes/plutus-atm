#ifndef TOQJSONCONVERTER_H
#define TOQJSONCONVERTER_H

#include <QByteArray>
#include <QVariantMap>
#include<Requests.h>

template <class T> class ToJsonConverter
{
private:
    QVariantMap toQVariantMap(const T&);
public:
    virtual QByteArray toJson(const T&) = 0;
};

class MakeTransferRequestToJsonConverter : ToJsonConverter<MakeTransferRequest>
{
private:
    QVariantMap toQVariantMap(const MakeTransferRequest&);
public:
    QByteArray toJson(const MakeTransferRequest&);
};

class ATMTokenRequestToJsonConverter : public ToJsonConverter<ATMTokenRequest>
{
private:
    QVariantMap toQVariantMap(const ATMTokenRequest&);
public:
    QByteArray toJson(const ATMTokenRequest& value);
};

class CreateAccountRequestToJsonConverter : ToJsonConverter<CreateAccountRequest>
{
private:
    QVariantMap toQVariantMap(const CreateAccountRequest&);
public:
    QByteArray toJson(const CreateAccountRequest& value);
};

class ChangeBalanceRequestToJsonConverter : ToJsonConverter<ChangeBalanceRequest>
{
private:
    QVariantMap toQVariantMap(const ChangeBalanceRequest&);
public:
    QByteArray toJson(const ChangeBalanceRequest& value);
};

class AssignCreditTariffToAccountRequestToJsonConverter : ToJsonConverter<AssignCreditTariffToAccountRequest>
{
private:
    QVariantMap toQVariantMap(const AssignCreditTariffToAccountRequest&);
public:
    QByteArray toJson(const AssignCreditTariffToAccountRequest& value);
};

class CreateClientRequestToJsonConverter : ToJsonConverter<CreateClientRequest>
{
private:
    QVariantMap toQVariantMap(const CreateClientRequest&);
public:
    QByteArray toJson(const CreateClientRequest& value);
};

class ModifyOrCreateCreditTariffRequestToJsonConverter : ToJsonConverter<ModifyOrCreateCreditTariffRequest>
{
private:
    QVariantMap toQVariantMap(const ModifyOrCreateCreditTariffRequest&);
public:
    QByteArray toJson(const ModifyOrCreateCreditTariffRequest& value);
};

class CreateAutomaticTransferRequestToJsonConverter : ToJsonConverter<CreateAutomaticTransferRequest>
{
private:
    QVariantMap toQVariantMap(const CreateAutomaticTransferRequest&);
public:
    QByteArray toJson(const CreateAutomaticTransferRequest& value);
};

#endif // TOQJSONCONVERTER_H
