#include "Requests.h"
#include <QJsonDocument>

void FromJsonConvertable::fillFromSchema(QVariantMap map) const
{
	fillFromQVariantMap(map);
}

QByteArray ToJsonConvertableConverter::jsonRepresentation(const ToJsonConvertable& to_convert) const
{
	return QJsonDocument::fromVariant(to_convert.jsonSchema()).toJson();
}
