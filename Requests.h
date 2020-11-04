#ifndef REQUESTS_H
#define REQUESTS_H

#include <QString>

// TODO: think about structures

class MakeTransferRequest
{
public:
    long getToId() const;
    MakeTransferRequest& setToId(long value);

    long getFromId() const;
    MakeTransferRequest& setFromId(long value);

    double getAmount() const;
    MakeTransferRequest& setAmount(double value);

    QString getDescription() const;
    MakeTransferRequest& setDescription(const QString &value);

private:
    long toId;
    long fromId;
    double amount;
    QString description;
};



class ATMTokenRequest
{
public:
    QString getAtmKey() const;
    ATMTokenRequest& setAtmKey(const QString &value);

    QString getAccountId() const;
    ATMTokenRequest& setAccountId(const QString &value);

    QString getPin() const;
    ATMTokenRequest& setPin(const QString &value);

private:
    QString atmKey;
    QString accountId;
    QString pin;
};



class CreateAccountRequest
{
public:
    long getUserId() const;
    CreateAccountRequest& setUserId(long value);

    QString getPin() const;
    CreateAccountRequest& setPin(const QString &value);

    long getTarrifId() const;
    CreateAccountRequest& setTarrifId(long value);

private:
    long userId;
    QString pin;
    long tarrifId;
};



class ChangeBalanceRequest
{
public:
    long getAccountId() const;
    ChangeBalanceRequest& setAccountId(long value);

    double getAmount() const;
    ChangeBalanceRequest& setAmount(double value);

private:
    long accountId;
    double amount;
};



class AssignCreditTariffToAccountRequest
{
public:
    long getAccountId() const;
    AssignCreditTariffToAccountRequest& setAccountId(long value);

    long getTariffId() const;
    AssignCreditTariffToAccountRequest& setTariffId(long value);

private:
    long accountId;
    long tariffId;

};



class CreateClientRequest
{
public:
    QString getName() const;
    CreateClientRequest& setName(const QString &value);

    QString getSurname() const;
    CreateClientRequest& setSurname(const QString &value);

private:
    QString name;
    QString surname;
};



class ModifyOrCreateCreditTariffRequest
{
public:
    long getId() const;
    ModifyOrCreateCreditTariffRequest& setId(long value);

    QString getName() const;
    ModifyOrCreateCreditTariffRequest& setName(const QString &value);

    double getPercent() const;
    ModifyOrCreateCreditTariffRequest& setPercent(double value);

    double getLimit() const;
    ModifyOrCreateCreditTariffRequest& setLimit(double value);

private:
    long id;
    QString name;
    double percent;
    double limit;
};



class CreateAutomaticTransferRequest
{
public:
    QString getName() const;
    CreateAutomaticTransferRequest& setName(const QString &value);

    long getFromId() const;
    CreateAutomaticTransferRequest& setFromId(long value);

    long getToId() const;
    CreateAutomaticTransferRequest& setToId(long value);

    long getPeriod() const;
    CreateAutomaticTransferRequest& setPeriod(long value);

    long getNextPaymentTime() const;
    CreateAutomaticTransferRequest& setNextPaymentTime(long value);

    double getTransferAmount() const;
    CreateAutomaticTransferRequest& setTransferAmount(double value);

    double getToPayAmount() const;
    CreateAutomaticTransferRequest& setToPayAmount(double value);

    QString getDescription() const;
    CreateAutomaticTransferRequest& setDescription(const QString &value);

private:
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
