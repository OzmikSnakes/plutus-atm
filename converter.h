#pragma once
template <class T>
class ToJsonConverter
{
public:
	virtual QByteArray toJson(const T&) = 0;
	virtual ~ToJsonConverter() = default;
};
