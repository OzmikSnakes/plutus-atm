#include "Requests.h"
#include <QJsonDocument>

QByteArray ToJsonConvertableConverter::jsonRepresentation(const ToJsonConvertable& to_convert) const
{
	return QJsonDocument::fromVariant(to_convert.jsonSchema()).toJson();
}

void FromJsonFillable::fillFromJson(const QJsonObject& json)
{
	fill(json);
}
