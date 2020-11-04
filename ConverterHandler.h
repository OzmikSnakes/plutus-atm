#ifndef CONVERTERHANDLER_H
#define CONVERTERHANDLER_H

#include "ToJsonConverter.h"

#include <QByteArray>
#include <map>

using std::map;
using std::type_info;

// TODO: virtual template

class ConverterHandler
{
private:
    map<type_info, ToJsonConverter<void*>*> map;
public:
    template<class T> void addConverter(ToJsonConverter<T>*);
    template<class T> QByteArray toJson(T);
    template<class T> T fromJson(QByteArray);
};

#endif // CONVERTERHANDLER_H
