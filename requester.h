#pragma once

#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include <functional>
#include <QVariantMap>

#include "rest_request.h"
#include "converter_handler.h"
#include "converter.h"

class RequesterConfiguration
{
public:
	int port;
	std::string host;
	std::string apiPath;
	QSslConfiguration sslConfig;

	RequesterConfiguration& operator=(const RequesterConfiguration&);
};

class Requester : public QObject
{
Q_OBJECT
public:
	explicit Requester(const RequesterConfiguration&);
	template <class RequestType, class ResponseType, class ErrorType>
	void sendRequest(const RestRequest<RequestType, ResponseType, ErrorType>&);
	const QNetworkAccessManager& network_access_manager() const;
private:
	QNetworkAccessManager manager{this};
	RequesterConfiguration endpoint_configuration;
	ConverterHandler converter_handler;

	QNetworkRequest createRequest(const std::string&);
	static void fillResponseObjectFromReply(QNetworkReply&, FromJsonFillable&);
	static bool isErrorReply(const QNetworkReply&);
};

template <class RequestType, class ResponseType, class ErrorType>
void Requester::sendRequest(const RestRequest<RequestType, ResponseType, ErrorType>& restRequest)
{
	QByteArray dataByteArray = converter_handler.toJson<const ToJsonConvertable&>(restRequest.request_object());
	QNetworkRequest request = createRequest(restRequest.path());
	QNetworkReply* reply;
	switch (restRequest.method())
	{
	case RequestMethod::POST:
		reply = manager.post(request, dataByteArray);
		break;

	case RequestMethod::PUT:
		reply = manager.put(request, dataByteArray);
		break;

	case RequestMethod::GET:
		reply = manager.get(request);
		break;

	case RequestMethod::DELETE:
		if (dataByteArray == nullptr)
		{
			reply = manager.deleteResource(request);
		}
		else
		{
			// todo throw exception
		}

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
			        fillResponseObjectFromReply(*reply, responseObject);
			        restRequest.success_handler()(responseObject);
		        }
		        else
		        {
			        ErrorType error_object;
			        fillResponseObjectFromReply(*reply, error_object);
			        restRequest.error_handler()(error_object);
		        }
		        reply->close();
		        reply->deleteLater();
				delete reply;
	        });
}