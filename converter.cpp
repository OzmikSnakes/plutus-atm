#include "Requests.h"
#include <QJsonDocument>

QByteArray JsonConvertableConverter::jsonRepresentation(const JsonSchemaAware& to_convert) const
{
	return QJsonDocument::fromVariant(to_convert.jsonSchema()).toJson();
}
