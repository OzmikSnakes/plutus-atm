#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include "RestRequest.h"

#include <QtNetwork/QNetworkAccessManager>

class RequestHandler
{
private:
    template<class T> QNetworkReply sendCustomRequest(QNetworkAccessManager, QNetworkRequest, QString, T);
public:
    template<class R, class C> void sendRequest(RestRequest<R, C>);
};

#endif // REQUESTHANDLER_H
