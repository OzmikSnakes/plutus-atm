#include <QApplication>
#include <QDebug>
#include <typeinfo>

#include "Requests.h"
#include "converter_handler.h"

int main(int argc, char* argv[])
{
	ConverterHandler converter_handler;
	ATMTokenRequest token_request;
	token_request.accountId = 1;
	token_request.pin = "123";
	const ToJsonConvertableConverter converter;
	converter_handler.addConverter(converter);

	const void* c = new int{ 1 };
	const int* x = static_cast<const int*>(c);

	qInfo() << converter_handler.toJson<const ToJsonConvertable&>(token_request);
}
