#pragma once
#include <QVariantMap>

template <class T>
class ToJsonConverter
{
public:
	virtual QByteArray jsonRepresentation(T) const = 0;
	virtual ~ToJsonConverter() = default;
};

class JsonSchemaAware
{
	virtual QVariantMap toQVariantMap() const = 0;
public:
	QVariantMap jsonSchema() const;
	virtual ~JsonSchemaAware() = default;
};

class JsonSchemaAwareConverter final : public ToJsonConverter<const JsonSchemaAware&>
{
public:
	QByteArray jsonRepresentation(const JsonSchemaAware&) const override;
};

class FromJsonFillable
{
	virtual void fill(const QJsonObject&) = 0;
public:
	FromJsonFillable() = default;
	void fillFromJson(const QJsonObject&);
	virtual ~FromJsonFillable() = default;
};
