#pragma once
#include <QVariantMap>

template <class T>
class ToJsonConverter
{
public:
	virtual QByteArray jsonRepresentation(T) const = 0;
	virtual ~ToJsonConverter() = default;
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

class FromJsonFillable
{
	virtual void fill(const QJsonObject&) = 0;
public:
	FromJsonFillable() = default;
	void fillFromJson(const QJsonObject&);
	virtual ~FromJsonFillable() = default;
};
