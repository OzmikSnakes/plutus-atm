#include <QApplication>
#include <QDebug>
#include <thread>
#include <typeinfo>

#include "requests.h"
#include "converter_handler.h"
#include "requester.h"
#include "responses.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	// Deployed: https://plutus-system.herokuapp.com/
	RestConfiguration config{false, "localhost:8080", "api", QSslConfiguration::defaultConfiguration()};
	Requester* requester{new Requester{config, SessionManager::getInstance()}};

	const FunctionResponseHandler<ErrorInfo> errorHandler{
		[](const ErrorInfo& response)
		{
			qInfo() << "Error occurred with status field: " << response.status;
			qInfo() << "Error occurred with error field: " << response.error;
			qInfo() << "Error occurred with message field: " << response.message;
		}
	};

	const FunctionResponseHandler<AccountInfo> accountGetSuccess{
				[](const AccountInfo& response)
				{
					qInfo() << "Account info:";
					qInfo() << "id: " << response.id;
					qInfo() << "number: " << response.number;
					qInfo() << "money: " << response.moneyAmount;
				}
	};

	const AuthorizationResponseHandler successHandler{
		SessionManager::getInstance(),
		[requester, accountGetSuccess,errorHandler](const TokenInfo& _)
		{
			qInfo() << "Auahtorized successfully";
			RestRequest<EmptyRequest, AccountInfo, ErrorInfo> rest_request(RequestMethod::POST, "secured/account/", EmptyRequest{}, accountGetSuccess, errorHandler);
			requester->sendRequest(rest_request);
		}
	};

	ATMTokenRequest request;
	request.accountNumber = "4532280486346619";
	request.pin = "1234";
	RestRequest<ATMTokenRequest, TokenInfo, ErrorInfo>
		rest_request(RequestMethod::POST, "auth/atm/token", request, successHandler, errorHandler);
	requester->sendRequest(rest_request);
	return a.exec();
}
