#include <QApplication>
#include <QDebug>
#include <typeinfo>

#include "requests.h"
#include "converter_handler.h"
#include "requester.h"
#include "responses.h"

class CustomResponseHandler : public ResponseHandler<TokenInfo>
{
	void handle(const TokenInfo& response) override
	{
		qDebug() << "Received token response with token: " << QString::fromStdString(response.token);
	}
};

int main(int argc, char* argv[])
{
	RequesterConfiguration config = RequesterConfiguration();
	config.apiPath = "api";
	config.host = "localhost";
	config.port = 8080;
	// http://localhost:8080/api/
	config.sslConfig = QSslConfiguration::defaultConfiguration();
	Requester requester = Requester(config);
	ATMTokenRequest request;
	request.accountNumber = "1234123412341234";
	request.pin = "1234";
	// RestRequest<ATMTokenRequest, TokenInfo> rest_request(RequestType::POST, "auth/atm/token", request, CustomResponseHandler());
}
