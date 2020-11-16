#include "responses.h"

void TokenInfo::fill(const QJsonObject& json)
{
	token = json["jwtToken"].toString().toStdString();
}
