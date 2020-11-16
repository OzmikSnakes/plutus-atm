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
	template <class R, class C>
	void sendRequest(const RestRequest<R, C>&);
private:
	QNetworkAccessManager manager{this};
	RequesterConfiguration config;
	ConverterHandler converterHandler;

	void fillResponseObjectFromReply(QNetworkReply*, FromJsonFillable&);
	bool onFinishRequest(QNetworkReply*);
	QNetworkReply* sendCustomRequest(const QNetworkRequest&, const QString&, const QByteArray&);
	QNetworkRequest createRequest(const std::string&);
};

template <class R, class C>
void Requester::sendRequest(const RestRequest<R, C>& restRequest)
{
	QByteArray dataByteArray = converterHandler.toJson<const ToJsonConvertable&>(restRequest.request_object());
	QNetworkRequest request = createRequest(restRequest.path());
	QNetworkReply* reply;
	switch (restRequest.type())
	{
	case RequestType::POST:
		{
			reply = manager.post(request, dataByteArray);
			break;
		}
	case RequestType::PUT:
		{
			reply = manager.put(request, dataByteArray);
			break;
		}
	case RequestType::GET:
		{
			reply = manager.get(request);
			break;
		}
	case RequestType::DELETE:
		{
			if (dataByteArray == nullptr)
				reply = manager.deleteResource(request);
			else
				reply = sendCustomRequest(request, "DELETE", dataByteArray);
			break;
		}
	case RequestType::PATCH:
		{
			reply = sendCustomRequest(request, "PATCH", dataByteArray);
			break;
		}
	default:
		reply = nullptr;
		Q_ASSERT(false);
	}

	connect(reply, &QNetworkReply::finished, this,
	        [this, reply, restRequest]()
	        {
				C responseObject;
		        if (onFinishRequest(reply))
		        {
					fillResponseObjectFromReply(reply, responseObject);
					restRequest.success_handler()(responseObject);
		        }
		        else
		        {
		        	//todo error handling
		        }
		        reply->close();
		        reply->deleteLater();
	        });
}

/*class Requester : public QObject
{
Q_OBJECT
public:

	bool onFinishRequest(QNetworkReply* reply);

	void handleQtNetworkErrors(QNetworkReply* reply, QJsonObject& obj);
	QNetworkAccessManager* manager;

signals:
	void networkError();


public slots:
};*/
