#pragma once
#include <QVariantMap>
#include<Requests.h>
#include "converter.h"

class ToJsonConvertableConverter final : ToJsonConverter<const ToJsonConvertable&>
{
public:
	QByteArray toJson(const ToJsonConvertable&) override;
};