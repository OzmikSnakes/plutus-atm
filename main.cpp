#include "Requests.h"
#include "ConverterHandler.h"

#include <QApplication>
#include <QDebug>
#include <typeinfo>

int main(int argc, char *argv[])
{
    ConverterHandler converterHandler = ConverterHandler();
    ATMTokenRequest request = ATMTokenRequest();
    request.setPin("1").setAccountId("1").setAtmKey("1");
    // qInfo() << typeid(request).name();
    converterHandler.addConverter<ATMTokenRequest>(new ATMTokenRequestToJsonConverter());
//    QByteArray json = converterHandler.toJson(request);
//    qInfo() << json.toStdString().c_str();
}
