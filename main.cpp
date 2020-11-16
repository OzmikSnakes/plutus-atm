#include <QApplication>
#include <QDebug>
#include <typeinfo>

#include "requests.h"
#include "converter_handler.h"
#include "requester.h"
#include "responses.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	RequesterConfiguration config = RequesterConfiguration();
	config.apiPath = "api";
	config.host = "localhost";
	config.port = 8080;
	config.sslConfig = QSslConfiguration::defaultConfiguration();
	Requester requester{config};
	ATMTokenRequest request;
	request.accountNumber = "4532280486346619";
	request.pin = "1234";
	const FunctionResponseHandler<TokenInfo> successHandler{
		[](const TokenInfo& response)
		{
			qInfo() << "Successfully acquired token " << response.token;
		}
	};

	const FunctionResponseHandler<ErrorInfo> errorHandler{
		[](const ErrorInfo& response)
		{
			qInfo() << "Error occurred with message: " << response.message;
		}
	};


	RestRequest<ATMTokenRequest, TokenInfo, ErrorInfo> rest_request(RequestMethod::POST, "auth/atm/token", request, successHandler, errorHandler);
	requester.sendRequest(rest_request);
	return a.exec();
}
