#include "responses.h"

QVariantMap TokenInfo::toQVariantMap() const
{
	QVariantMap schema;
	schema["token"] = QString::fromStdString(token);
	return schema;
}
