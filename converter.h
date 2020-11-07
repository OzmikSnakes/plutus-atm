#pragma once
#include <QVariantMap>

template <class T>
class ToJsonConverter
{
public:
	virtual QByteArray jsonRepresentation(T) const = 0;
	virtual ~ToJsonConverter() = default;
};

template <class T>
class FromJsonConverter
{
public:
	virtual T fromJson(QByteArray) = 0;
	virtual ~FromJsonConverter() = default;
};


class ToJsonConvertable
{
	virtual QVariantMap toQVariantMap() const = 0;
public:
	QVariantMap jsonSchema() const;
	virtual ~ToJsonConvertable() = default;
};

class ToJsonConvertableConverter final : public ToJsonConverter<const ToJsonConvertable&>
{
public:
	QByteArray jsonRepresentation(const ToJsonConvertable&) const override;
};
