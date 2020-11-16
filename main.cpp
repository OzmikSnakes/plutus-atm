#include <QApplication>
#include <QDebug>
#include <typeinfo>

#include "requests.h"
#include "converter_handler.h"
#include "requester.h"
#include "responses.h"

class CustomResponseHandler : public ResponseHandler<TokenInfo>
{
	void handle(const TokenInfo& response) const override
	{
		qDebug() << "Received token response with token: " << QString::fromStdString(response.token);
	}
};

class ErrorResponseHandler : public ResponseHandler<ErrorInfo>
{
	void handle(const ErrorInfo& response) const override
	{
		qDebug() << "Error received with message " << response.message;
	}
};

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
	RestRequest<ATMTokenRequest, TokenInfo> rest_request(RequestType::POST, "auth/atm/token", request, CustomResponseHandler(),
	                                                     ErrorResponseHandler());
	requester.sendRequest(rest_request);
	return a.exec();
}
