#pragma once

#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>

#include "rest_request.h"
#include "converter_handler.h"
#include "converter.h"
#include "session_manager.h"

struct RestConfiguration
{
	bool secured;
	int port;
	std::string host;
	std::string api_path;
	QSslConfiguration ssl_config;

	RestConfiguration(bool secured_, int port_, std::string host_, std::string api_path_, const QSslConfiguration& ssl_config_);
	QUrl root_url() const;
};

#ifdef Q_OBJECT
class Requester : public QObject
{
Q_OBJECT
public:
	explicit Requester(const RestConfiguration&, AbstractSessionManager<Session>&);
	template <class RequestType, class ResponseType, class ErrorType>
	void sendRequest(const RestRequest<RequestType, ResponseType, ErrorType>&);
	[[nodiscard]] const QNetworkAccessManager& network_access_manager() const;
private:
	QNetworkAccessManager network_manager_{this};
	RestConfiguration rest_configuration_;
	ConverterHandler converter_handler_;
	// todo make requester templated
	AbstractSessionManager<Session>& session_manager_;

	//methods
	QNetworkRequest createRequest(const std::string&);
	static void processReply(QNetworkReply&, FromJsonFillable&);
	static bool isErrorReply(const QNetworkReply&);

	static const char* const AUTHORIZATION_HEADER_NAME;
	static const char* const CSRF_HEADER_NAME;
};

template <class RequestType, class ResponseType, class ErrorType>
void Requester::sendRequest(const RestRequest<RequestType, ResponseType, ErrorType>& restRequest)
{
	const QByteArray dataByteArray{converter_handler_.toJson<const JsonSchemaAware&>(restRequest.request_object())};
	const QNetworkRequest request{createRequest(restRequest.path())};
	QNetworkReply* reply{nullptr};
	//todo optimize desision making
	switch (restRequest.method())
	{
	case RequestMethod::POST:
		reply = network_manager_.post(request, dataByteArray);
		break;

	case RequestMethod::PUT:
		reply = network_manager_.put(request, dataByteArray);
		break;

	case RequestMethod::GET:
		reply = network_manager_.get(request);
		break;

	case RequestMethod::DELETE:
		if (dataByteArray == nullptr)
		{
			reply = network_manager_.deleteResource(request);
		}
		else
		{
			// todo throw exception
		}
		break;

	default:
		// todo throw exception
		reply = nullptr;
		Q_ASSERT(false);
	}

	connect(reply, &QNetworkReply::finished, this,
	        [this, reply, restRequest]()
	        {
		        if (isErrorReply(*reply))
		        {
			        ResponseType responseObject;
			        processReply(*reply, responseObject);
			        restRequest.success_handler()(responseObject);
		        }
		        else
		        {
			        ErrorType error_object;
			        processReply(*reply, error_object);
			        restRequest.error_handler()(error_object);
		        }
		        reply->close();
		        reply->deleteLater();
		        delete reply;
	        });
}
#endif
