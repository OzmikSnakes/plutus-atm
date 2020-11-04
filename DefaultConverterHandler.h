#ifndef DEFAULTCONVERTERHANDLER_H
#define DEFAULTCONVERTERHANDLER_H

#import "ConverterHandler.h"

class DefaultConverterHandler : ConverterHandler
{
public:
    template<class T> QByteArray toJson(T);
    template<class T> T fromJson(QByteArray);
};

#endif // DEFAULTCONVERTERHANDLER_H
