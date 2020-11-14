#pragma once


#include <QtNetwork/QNetworkAccessManager>

#include "rest_request.h"

class RequestHandler
{
private:
	template <class T>
	QNetworkReply sendCustomRequest(QNetworkAccessManager, QNetworkRequest, QString, T);
public:
	template <class R, class C>
	void sendRequest(RestRequest<R, C>);
};
