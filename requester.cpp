#include "requester.h"
#include "session_manager.h"

#include <QObject>
#include <QBuffer>

RequesterConfiguration& RequesterConfiguration::operator=(const RequesterConfiguration& config)
{
	host = config.host;
	port = config.port;
	apiPath = config.apiPath;
	//sslConfig = QSslConfiguration::defaultConfiguration();//config.sslConfig;
	return *this;
}

Requester::Requester(const RequesterConfiguration& to_copy)
{
	config = to_copy;
	converterHandler.addConverter<const ToJsonConvertable&>(*new ToJsonConvertableConverter());
}

QNetworkRequest Requester::createRequest(const std::string& path)
{
	QNetworkRequest request;
	// todo move to configuration
	QString requestUrl = QString::fromStdString("http://%1:%2/%3/%4")
	                     .arg(QString::fromStdString(config.host))
	                     .arg(QString::fromStdString(std::to_string(config.port)))
	                     .arg(QString::fromStdString(config.apiPath))
	                     .arg(QString::fromStdString(path));
	request.setUrl(QUrl(requestUrl));
	request.setRawHeader("Content-Type", "application/json");
	QString token = QString::fromStdString(SessionManager::getInstance()->getCurrentSession().getToken());
	request.setRawHeader("Authorization", QString("Bearer %1").arg(token).toUtf8());
	request.setSslConfiguration(config.sslConfig);
	return request;
}

bool Requester::onFinishRequest(QNetworkReply* reply)
{
	QNetworkReply::NetworkError replyError = reply->error();
	if (replyError == QNetworkReply::NoError)
	{
		int errorCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
		if ((errorCode >= 200) && (errorCode < 300))
			return true;
	}
	return false;
}

QNetworkReply* Requester::sendCustomRequest(const QNetworkRequest& request, const QString& type, const QByteArray& dataByteArray)
{
	// request.setRawHeader("HTTP", type);
	QBuffer* buff = new QBuffer;
	buff->setData(dataByteArray);
	// maybe ReadWrite
	buff->open((QBuffer::ReadOnly));
	QNetworkReply* reply;
	reply = manager.sendCustomRequest(request, type.toUtf8(), buff);
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
