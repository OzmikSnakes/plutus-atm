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


class JsonSchemaAware
{
	virtual QVariantMap toQVariantMap() const = 0;
public:
	QVariantMap jsonSchema() const;
    virtual ~JsonSchemaAware() = default;
};

class JsonConvertableConverter final : public ToJsonConverter<const JsonSchemaAware&>
{
public:
    QByteArray jsonRepresentation(const JsonSchemaAware&) const override;
};
