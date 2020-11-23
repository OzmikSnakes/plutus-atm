#include "responses.h"

void ErrorInfo::fill(const QJsonObject& json)
{
	message = json["message"].toString();
	status = static_cast<QNetworkReply::NetworkError>(json["status"].toInt());
	error = json["error"].toString();
}

void TokenInfo::fill(const QJsonObject& json)
{
	token = json["jwtToken"].toString();
}

void AccountInfo::fill(const QJsonObject& json)
{
	id = json["id"].toInt();
	number = json["number"].toString();
	moneyAmount = json["moneyAmount"].toDouble();
	// todo
	// long creditTariffId;
	clientId = json["clientId"].toInt();
}

void TransferInfo::fill(const QJsonObject& json)
{
    id = json["id"].toInt();
    fromId = json["fromId"].toDouble();
    toId = json["toId"].toDouble();
    transferStatus = json["transferStatus"].toString();
    amount = json["amount"].toDouble();
    createdWhen = json["createdWhen"].toDouble();
    description = json["description"].toString();
}
