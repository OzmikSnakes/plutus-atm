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
	// SessionManager::getInstance().current_session({"kek", "kek"});
	// const auto maybeSession = SessionManager::getInstance().current_session();
	// AbstractSessionManager<Session>& s = SessionManager::getInstance();
	// if (maybeSession.has_value())
	// {
	// 	qInfo() << "Token:" << QString::fromStdString(maybeSession.value().jwt_token);
	// }
	
	RestConfiguration config{false, 8080, "localhost", "api", QSslConfiguration::defaultConfiguration()};
	Requester requester{config, SessionManager::getInstance()};
	
	ATMTokenRequest request;
	request.accountNumber = "4532280486346619";
	request.pin = "1234";
	
	const AuthorizationResponseHandler successHandler{
		SessionManager::getInstance(),
		[](const TokenInfo& response)
		{
			qInfo() << "Successfully acquired jwt_token_ " << response.token;
		}
	};
	
	const FunctionResponseHandler<ErrorInfo> errorHandler{
		[](const ErrorInfo& response)
		{
			qInfo() << "Error occurred with message: " << response.message;
		}
	};
	
	
	RestRequest<ATMTokenRequest, TokenInfo, ErrorInfo>
		rest_request(RequestMethod::POST, "auth/atm/token", request, successHandler, errorHandler);
	requester.sendRequest(rest_request);
	return a.exec();
}
