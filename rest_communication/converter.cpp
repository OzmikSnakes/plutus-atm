#include "dto/requests.h"
#include <QJsonDocument>

QByteArray JsonSchemaAwareConverter::jsonRepresentation(const JsonSchemaAware& to_convert) const
{
	return QJsonDocument::fromVariant(to_convert.jsonSchema()).toJson();
}

void FromJsonFillable::fillFromJson(const QJsonObject& json)
{
	fill(json);
}
