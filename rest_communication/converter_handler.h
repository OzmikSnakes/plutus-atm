#pragma once
#include <map>
#include "converter.h"

class ConverterHandler
{
private:
    std::map<size_t, const void*> converters;
public:
    template <class T>
    void addConverter(const ToJsonConverter<T>&) ;
    template <class T>
    QByteArray toJson(const T&);
};

template <class T>
void ConverterHandler::addConverter(const ToJsonConverter<T>& converter)
{
    converters[typeid(T).hash_code()] = &converter;
}

// todo solve problem with implicit templating
template <class T>
QByteArray ConverterHandler::toJson(const T& toConvert)
{
    return static_cast<const ToJsonConverter<T>*>(converters[typeid(T).hash_code()])->jsonRepresentation(toConvert);
}
