#include <QApplication>
#include <QDebug>
#include <typeinfo>

#include "Requests.h"
#include "ConverterHandler.h"


int main(int argc, char* argv[])
{
	ConverterHandler converterHandler = ConverterHandler();
	ATMTokenRequest request = ATMTokenRequest();
	request.setPin("1").setAccountId("1").setAtmKey("1");
	qInfo() << typeid(request).name();
	const ToJsonConverter<ATMTokenRequest>& converter = ATMTokenRequestToJsonConverter();
	converterHandler.addConverter(converter);
	// //    QByteArray json = converterHandler.toJson(request);
	// //    qInfo() << json.toStdString().c_str();
}
