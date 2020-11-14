#pragma once

#include <QObject>
#include <QBuffer>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include <functional>
#include <QVariantMap>

#include "rest_request.h"
#include "converter_handler.h"

class RequesterConfiguration
{
public:
    int port;
    std::string host;
    std::string apiPath;
    QSslConfiguration sslConfig;

    RequesterConfiguration operator=(const RequesterConfiguration&);
};

class Requester
{
public:
    explicit Requester(const RequesterConfiguration&);
    template <class R, class C>
    void sendRequest(const RestRequest<R, C>&);
private:
    QNetworkAccessManager* manager;
    RequesterConfiguration config;
    ConverterHandler converterHandler;

    template <class C>
    C parseReply(QNetworkReply*);
    bool onFinishRequest(QNetworkReply*);
    QNetworkReply* sendCustomRequest(const QNetworkRequest&, const QString&, const QByteArray&);
    QNetworkRequest createRequest(const std::string&);
};


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
