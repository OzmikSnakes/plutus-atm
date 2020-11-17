#include "requester.h"
#include "session_manager.h"

#include <QObject>
#include <QBuffer>

RestConfiguration::RestConfiguration(const bool secured_,
                                     const int port_,
                                     std::string host_,
                                     std::string api_path_,
                                     const QSslConfiguration& ssl_config_)
	: secured{secured_},
	  port{port_},
	  host{std::move(host_)},
	  api_path{std::move(api_path_)},
	  ssl_config{ssl_config_}
{
}

QUrl RestConfiguration::root_url() const
{
	QString requestUrl = QString::fromStdString("%1://%2:%3/%4/")
	                     .arg(QString::fromStdString(secured ? "https" : "http"))
	                     .arg(QString::fromStdString(host))
	                     .arg(QString::fromStdString(std::to_string(port)))
	                     .arg(QString::fromStdString(api_path));
	return requestUrl;
}

const char* const Requester::AUTHORIZATION_HEADER_NAME{"Authorization"};
const char* const Requester::CSRF_HEADER_NAME{"X-XSRF-TOKEN"};

Requester::Requester(const RestConfiguration& to_copy, AbstractSessionManager<Session>& session_manager)
	: rest_configuration_{to_copy}, session_manager_{session_manager}
{
	converter_handler_.addConverter<const JsonSchemaAware&>(*new JsonSchemaAwareConverter());
}

const QNetworkAccessManager& Requester::network_access_manager() const
{
	return network_manager_;
}

QNetworkRequest Requester::createRequest(const std::string& path)
{
	QNetworkRequest request;
	QUrl request_url{rest_configuration_.root_url()};
	request_url.setPath(request_url.path() + QString::fromStdString(path));
	request.setUrl(request_url);
	auto x = request_url.toDisplayString();
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	const auto maybe_session = session_manager_.current_session();
	if (maybe_session.has_value())
	{
		const Session& session = maybe_session.value();
		request.setRawHeader(AUTHORIZATION_HEADER_NAME, QString("Bearer %1").arg(QString::fromStdString(session.jwt_token)).toUtf8());
		request.setRawHeader(CSRF_HEADER_NAME, session.csrf_token.c_str());
	}
	request.setSslConfiguration(rest_configuration_.ssl_config);
	return request;
}

bool Requester::isErrorReply(const QNetworkReply& reply)
{
	QNetworkReply::NetworkError replyError = reply.error();
	if (replyError == QNetworkReply::NoError)
	{
		const int errorCode = reply.attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
		if ((errorCode >= 200) && (errorCode < 300))
			return true;
	}
	return false;
}

// todo make converter
void Requester::processReply(QNetworkReply& reply, FromJsonFillable& to_fill)
{
	QJsonParseError* parseError{nullptr};
	const QByteArray replyDataByteArray{reply.readAll()};
	const QJsonDocument jsonDoc{QJsonDocument::fromJson(replyDataByteArray, parseError)};
	if (parseError && parseError->error != QJsonParseError::NoError)
	{
		//todo throw exception
		qDebug() << replyDataByteArray;
		qWarning() << "Json parse error: " << parseError->errorString();
	}
	else
	{
		to_fill.fillFromJson(jsonDoc.object());
	}
	delete parseError;
}
