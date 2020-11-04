#include "Requests.h"

// TODO: think about setter exceptions

// MakeTransferRequest Implementation

long MakeTransferRequest::getToId() const { return toId; }

MakeTransferRequest& MakeTransferRequest::setToId(long value)
{
    toId = value;
    return *this;
}

long MakeTransferRequest::getFromId() const { return fromId; }

MakeTransferRequest& MakeTransferRequest::setFromId(long value)
{
    fromId = value;
    return *this;
}

double MakeTransferRequest::getAmount() const { return amount; }

MakeTransferRequest& MakeTransferRequest::setAmount(double value)
{
    amount = value;
    return *this;
}

QString MakeTransferRequest::getDescription() const { return description; }

MakeTransferRequest& MakeTransferRequest::setDescription(const QString &value)
{
    description = value;
    return *this;
}

// ATMTokenRequest Implementation

QString ATMTokenRequest::getAtmKey() const { return atmKey; }

ATMTokenRequest& ATMTokenRequest::setAtmKey(const QString &value)
{
    atmKey =value;
    return *this;
}

QString ATMTokenRequest::getAccountId() const { return accountId; }

ATMTokenRequest& ATMTokenRequest::setAccountId(const QString &value)
{
    accountId = value;
    return *this;
}

QString ATMTokenRequest::getPin() const {return accountId; }

ATMTokenRequest& ATMTokenRequest::setPin(const QString &value)
{
    pin = value;
    return *this;
}

// CreateAccountRequest Implementation

long CreateAccountRequest::getUserId() const { return userId; }

CreateAccountRequest& CreateAccountRequest::setUserId(long value)
{
    userId = value;
    return *this;
}

QString CreateAccountRequest::getPin() const { return pin; }

CreateAccountRequest& CreateAccountRequest::setPin(const QString &value)
{
    pin = value;
    return *this;
}

long CreateAccountRequest::getTarrifId() const { return tarrifId; }

CreateAccountRequest& CreateAccountRequest::setTarrifId(long value)
{
    tarrifId = value;
    return *this;
}

// ChangeBalanceRequest Implementation

long ChangeBalanceRequest::getAccountId() const {return accountId; }

ChangeBalanceRequest& ChangeBalanceRequest::setAccountId(long value)
{
    accountId = value;
    return *this;
}

double ChangeBalanceRequest::getAmount() const { return amount; }

ChangeBalanceRequest& ChangeBalanceRequest::setAmount(double value)
{
    amount = value;
    return *this;
}

// AssignCreditTariffToAccountRequest Implementation

long AssignCreditTariffToAccountRequest::getAccountId() const { return accountId;}

AssignCreditTariffToAccountRequest& AssignCreditTariffToAccountRequest::setAccountId(long value)
{
    accountId = value;
    return *this;
}

long AssignCreditTariffToAccountRequest::getTariffId() const { return tariffId; }

AssignCreditTariffToAccountRequest& AssignCreditTariffToAccountRequest::setTariffId(long value)
{
    tariffId = value;
    return *this;
}

// CreateClientRequest Implementation

QString CreateClientRequest::getName() const { return name; }

CreateClientRequest& CreateClientRequest::setName(const QString &value)
{
    name = value;
    return *this;
}

QString CreateClientRequest::getSurname() const { return surname; }

CreateClientRequest& CreateClientRequest::setSurname(const QString &value)
{
    surname = value;
    return *this;
}

// ModifyOrCreateCreditTariffRequest Implementation

long ModifyOrCreateCreditTariffRequest::getId() const { return id; }

ModifyOrCreateCreditTariffRequest& ModifyOrCreateCreditTariffRequest::setId(long value)
{
    id = value;
    return *this;
}

QString ModifyOrCreateCreditTariffRequest::getName() const { return name; }

ModifyOrCreateCreditTariffRequest& ModifyOrCreateCreditTariffRequest::setName(const QString &value)
{
    name = value;
    return *this;
}

double ModifyOrCreateCreditTariffRequest::getPercent() const { return percent; }

ModifyOrCreateCreditTariffRequest& ModifyOrCreateCreditTariffRequest::setPercent(double value)
{
    percent = value;
    return *this;
}

double ModifyOrCreateCreditTariffRequest::getLimit() const { return limit; }

ModifyOrCreateCreditTariffRequest& ModifyOrCreateCreditTariffRequest::setLimit(double value)
{
    limit = value;
    return *this;
}

// CreateAutomaticTransferRequest Implementation

QString CreateAutomaticTransferRequest::getName() const { return name; }

CreateAutomaticTransferRequest& CreateAutomaticTransferRequest::setName(const QString &value)
{
    name = value;
    return *this;
}

long CreateAutomaticTransferRequest::getFromId() const { return fromId; }

CreateAutomaticTransferRequest& CreateAutomaticTransferRequest::setFromId(long value)
{
    fromId = value;
    return *this;
}

long CreateAutomaticTransferRequest::getToId() const { return toId; }

CreateAutomaticTransferRequest& CreateAutomaticTransferRequest::setToId(long value)
{
    toId = value;
    return *this;
}

long CreateAutomaticTransferRequest::getPeriod() const { return period; }

CreateAutomaticTransferRequest& CreateAutomaticTransferRequest::setPeriod(long value)
{
    period = value;
    return *this;
}

long CreateAutomaticTransferRequest::getNextPaymentTime() const { return nextPaymentTime; }

CreateAutomaticTransferRequest& CreateAutomaticTransferRequest::setNextPaymentTime(long value)
{
    nextPaymentTime = value;
    return *this;
}

double CreateAutomaticTransferRequest::getTransferAmount() const { return transferAmount; }

CreateAutomaticTransferRequest& CreateAutomaticTransferRequest::setTransferAmount(double value)
{
    transferAmount = value;
    return *this;
}

double CreateAutomaticTransferRequest::getToPayAmount() const { return toPayAmount; }

CreateAutomaticTransferRequest& CreateAutomaticTransferRequest::setToPayAmount(double value)
{
    toPayAmount = value;
    return *this;
}

QString CreateAutomaticTransferRequest::getDescription() const { return description; }

CreateAutomaticTransferRequest& CreateAutomaticTransferRequest::setDescription(const QString &value)
{
    description = value;
    return *this;
}
