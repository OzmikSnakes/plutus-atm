#include "responses.h"

void ErrorInfo::fill(const QJsonObject& json)
{
	message = json["message"].toString();
	status = json["status"].toInt();
	error = json["error"].toString();
	
}

void TokenInfo::fill(const QJsonObject& json)
{
	token = json["jwtToken"].toString();
}
