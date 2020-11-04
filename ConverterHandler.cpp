#include "ConverterHandler.h"
#include "Requests.h"

template<class T> void ConverterHandler::addConverter(ToJsonConverter<T> *converter)
{
    map[typeid (T)] = converter;
}

template<class T> QByteArray ConverterHandler::toJson(T value)
{
    return QByteArray();//map[typeid (T)]->toJson(value);
}


