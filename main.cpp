#include <QApplication>
#include <QDebug>
#include <typeinfo>

#include "requests.h"
#include "converter_handler.h"
#include "requester.h"

int main(int argc, char* argv[])
{
    RequesterConfiguration config = RequesterConfiguration();
    config.apiPath = "api";
    config.host = "local";
    config.port = 8080;
    config.sslConfig = QSslConfiguration::defaultConfiguration();
    // Requester requester = Requester(config);
    /*ConverterHandler converter_handler;
	ATMTokenRequest token_request;
    token_request.accountId = 1;
	token_request.pin = "123";
	const ToJsonConvertableConverter converter;
	converter_handler.addConverter(converter);

	const void* c = new int{ 1 };
	const int* x = static_cast<const int*>(c);

    qInfo() << converter_handler.toJson<const ToJsonConvertable&>(token_request);*/
}
