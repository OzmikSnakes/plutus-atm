#include "ToJsonConverter.h"
#include "Requests.h"
#include <QObject>
#include <QJsonDocument> 

QByteArray ToJsonConvertableConverter::toJson(const ToJsonConvertable& to_convert)
{
	return QJsonDocument::fromVariant(to_convert.jsonSchema()).toJson();
}