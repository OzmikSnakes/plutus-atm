#include "Requests.h"
#include <QObject>
#include <QJsonDocument> 

QByteArray ToJsonConvertableConverter::jsonRepresentation(const ToJsonConvertable& to_convert) const
{
	return QJsonDocument::fromVariant(to_convert.jsonSchema()).toJson();
}