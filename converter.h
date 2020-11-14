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

class FromJsonConvertable
{
	virtual void fillFromQVariantMap(QVariantMap) const = 0;
public:
	void fillFromSchema(QVariantMap) const;
	virtual ~FromJsonConvertable() = default;
};

class ToJsonConvertableConverter final : public ToJsonConverter<const ToJsonConvertable&>
{
public:
    QByteArray jsonRepresentation(const ToJsonConvertable&) const override;
};
//
// class FromJsonConvertableConverter final : public FromJsonConverter<FromJsonConvertable>
// {
// public:
// 	virtual FromJsonConvertable fromJson(QByteArray) override;
// };
