#include "requester.h"
#include "session_manager.h"

RequesterConfiguration RequesterConfiguration::operator=(const RequesterConfiguration& config)
{
    host = config.host;
    port = config.port;
    apiPath = config.apiPath;
    //sslConfig = QSslConfiguration::defaultConfiguration();//config.sslConfig;
    return *this;
}

Requester::Requester(const RequesterConfiguration &config)
{
    this->config = config;
    manager = new QNetworkAccessManager();
    const ToJsonConvertableConverter converter;
    converterHandler.addConverter(converter);
}

QNetworkRequest Requester::createRequest(const std::string &path)
{
    QNetworkRequest request;
    QString requestUrl = QString::fromStdString("https://%1:%2/%3/%4")
            .arg(QString::fromStdString(config.host))
            .arg(QString(config.port))
            .arg(QString::fromStdString(config.apiPath))
            .arg(QString::fromStdString(path));
    request.setUrl(QUrl(requestUrl));
    request.setRawHeader("Content-Type", "application/json");
    QString token = QString::fromStdString(SessionManager::getInstance()->getCurrentSession().getToken());
    request.setRawHeader("Authorization", QString("Bearer %1").arg(token).toUtf8());
    request.setSslConfiguration(config.sslConfig);
    return request;
}

template <class R, class C>
void Requester::sendRequest(const RestRequest<R, C>& restRequest)
{
    QByteArray dataByteArray;
    if (restRequest.request_object() != nullptr)
        dataByteArray = converterHandler.toJson(restRequest.request_object());
    QNetworkRequest request = createRequest(restRequest.path);
    QNetworkReply *reply;
    switch (restRequest.type) {
    case RequestType::POST: {
        reply = manager->post(request, dataByteArray);
        break;
    } case RequestType::PUT: {
        reply = manager->put(request, dataByteArray);
        break;
    } case RequestType::GET: {
        reply = manager->get(request);
        break;
    } case RequestType::DELETE: {
        if (dataByteArray == nullptr)
            reply = manager->deleteResource(request);
        else
            reply = sendCustomRequest(request, "DELETE", dataByteArray);
        break;
    } case RequestType::PATCH: {
        reply = sendCustomRequest(request, "PATCH", dataByteArray);
        break;
    } default:
        reply = nullptr;
        Q_ASSERT(false);
    }

    connect(reply, &QNetworkReply::finished, this, [this, restRequest, reply]() {
        C responseObject = parseReply<C>(reply);
        if (onFinishRequest(reply))
            restRequest.success_handler().handle(responseObject);
        else
            responseObject.error_handler().handle(responseObject);
        reply->close();
        reply->deleteLater();
    });
}


// todo make converter
template <class C>
C Requester::parseReply(QNetworkReply *reply)
{
     C responseObject;
     QJsonDocument jsonDoc;
     QJsonParseError parseError;
     QByteArray replyDataByteArray = reply->readAll();
     jsonDoc = QJsonDocument::fromJson(replyDataByteArray, &parseError);

     // from json converter

     /*if (parseError.error != QJsonParseError::NoError) {
         qDebug() << replyDataByteArray;
         qWarning() << "Json parse error: " << parseError.errorString();
     } else {
         if (jsonDoc.isObject())
             jsonObj = jsonDoc.object();
         else if (jsonDoc.isArray())
             jsonObj["non_field_errors"] = jsonDoc.array();
     }*/
     return responseObject;
}

bool Requester::onFinishRequest(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();
    if (replyError == QNetworkReply::NoError) {
        int errorCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if ((errorCode >=200) && (errorCode < 300))
            return true;
    }
    return false;
}

QNetworkReply* Requester::sendCustomRequest(const QNetworkRequest &request, const QString& type, const QByteArray &dataByteArray)
{
    // request.setRawHeader("HTTP", type);
    QBuffer *buff = new QBuffer;
    buff->setData(dataByteArray);
    // maybe ReadWrite
    buff->open((QBuffer::ReadOnly));
    QNetworkReply* reply;
    reply = manager->sendCustomRequest(request, type.toUtf8(), buff);
    buff->setParent(reply);
    return reply;
}

/*const QString Requester::httpTemplate = "http://%1:%2/api/%3";
const QString Requester::httpsTemplate = "https://%1:%2/api/%3";
const QString Requester::KEY_QNETWORK_REPLY_ERROR = "QNetworkReplyError";
const QString Requester::KEY_CONTENT_NOT_FOUND = "ContentNotFoundError";

Requester::Requester(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}

void Requester::initRequester(const QString &host, int port, QSslConfiguration *value)
{
    this->host = host;
    this->port = port;
    sslConfig = value;
    if (sslConfig != nullptr)
        pathTemplate = httpsTemplate;
    else
        pathTemplate = httpTemplate;
}

void Requester::sendRequest(const QString &apiStr,
                            const handleFunc &funcSuccess,
                            const handleFunc &funcError,
                            Requester::Type type,
                            const QVariantMap &data)
{
    QNetworkRequest request = createRequest(apiStr);

    QNetworkReply *reply;
    switch (type) {
    case Type::POST: {
        QByteArray postDataByteArray = variantMapToJson(data);
        reply = manager->post(request, postDataByteArray);
        break;
    } case Type::GET: {
        reply = manager->get(request);
        break;
    } case Type::DELETE: {
        if (data.isEmpty())
            reply = manager->deleteResource(request);
        else
            reply = sendCustomRequest(manager, request, "DELETE", data);
        break;
    } case Type::PATCH: {
        reply = sendCustomRequest(manager, request, "PATCH", data);
        break;
    } default:
        reply = nullptr;
        Q_ASSERT(false);
    }

    connect(reply, &QNetworkReply::finished, this,
            [this, funcSuccess, funcError, reply]() {
        QJsonObject obj = parseReply(reply);

        if (onFinishRequest(reply)) {
            if (funcSuccess != nullptr)
                funcSuccess(obj);
        } else {
            if (funcError != nullptr) {
                handleQtNetworkErrors(reply, obj);
                funcError(obj);
            }
        }
        reply->close();
        reply->deleteLater();
    } );

}

QNetworkRequest Requester::createRequest(const QString &apiStr)
{
    QNetworkRequest request;
    QString url = pathTemplate.arg(host).arg(port).arg(apiStr);
    request.setUrl(QUrl(url));
    request.setRawHeader("Content-Type","application/json");
    if(!token.isEmpty())
        request.setRawHeader("Authorization",QString("token %1").arg(token).toUtf8());
    if (sslConfig != nullptr)
        request.setSslConfiguration(*sslConfig);

    return request;
}

QNetworkReply* Requester::sendCustomRequest(QNetworkAccessManager* manager,
                                            QNetworkRequest &request,
                                            const QString &type,
                                            const QVariantMap &data)
{
	// todo doesn't compile
    // request.setRawHeader("HTTP", type.toUtf8());
    // QByteArray postDataByteArray = variantMapToJson(data);
    // QByteBuffer *buff = new QByteBuffer;
    // buff->setData(postDataByteArray);
    // buff->open(QIODevice::ReadOnly);
    // QNetworkReply* reply =  manager->sendCustomRequest(request, type.toUtf8(), buff);
    // buff->setParent(reply);
    // return reply;
}

QJsonObject Requester::parseReply(QNetworkReply *reply)
{
	// todo doesn't compile
    // QJsonObject jsonObj;
    // QJsonDocument jsonDoc;
    // QJsonParseError parseError;
    // auto replyText = reply->readAll();
    // jsonDoc = QJsonDocument::fromJson(replyText, &parseError);
    // if(parseError.error != QJsonParseError::NoError){
    //     qDebug() << replyText;
    //     qWarning() << "Json parse error: " << parseError.errorString();
    // }else{
    //     if(jsonDoc.isObject())
    //         jsonObj  = jsonDoc.object();
    //     else if (jsonDoc.isArray())
    //         jsonObj["non_field_errors"] = jsonDoc.array();
    // }
    // return jsonObj;
}

bool Requester::onFinishRequest(QNetworkReply *reply)
{
    auto replyError = reply->error();
    if (replyError == QNetworkReply::NoError ) {
        int code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if ((code >=200) && (code < 300)) {
            return true;
        }
    }
    return false;
}

void Requester::handleQtNetworkErrors(QNetworkReply *reply, QJsonObject &obj)
{
    auto replyError = reply->error();
    if (!(replyError == QNetworkReply::NoError ||
          replyError == QNetworkReply::ContentNotFoundError ||
          replyError == QNetworkReply::ContentAccessDenied ||
          replyError == QNetworkReply::ProtocolInvalidOperationError
          ) ) {
        qDebug() << reply->error();
        obj[KEY_QNETWORK_REPLY_ERROR] = reply->errorString();
    } else if (replyError == QNetworkReply::ContentNotFoundError)
        obj[KEY_CONTENT_NOT_FOUND] = reply->errorString();
}*/
