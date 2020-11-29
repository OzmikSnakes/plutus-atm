#pragma once
#include "converter.h"
#include "response_handler.h"

enum RequestMethod { GET, POST, PUT, DELETE };

// todo do with builder pattern
template <class RequestType, class ResponseType, class ErrorType>
class RestRequest
{
public:
    RestRequest(RequestMethod method, const std::string& path, const RequestType& request_object, AbstractResponseHandler<ResponseType>* success_handler,
                 AbstractResponseHandler<ErrorType>* error_handler)
		: method_(method),
		  path_(path),
		  request_object_(request_object),
          success_handler_(success_handler),
		  error_handler_(error_handler)
	{
	}

    [[nodiscard]] const RequestMethod& method() const;
    [[nodiscard]] const std::string& path() const;
	const RequestType& request_object() const;

	const AbstractResponseHandler<ResponseType>& success_handler() const;
    const AbstractResponseHandler<ErrorType>& error_handler() const;

private:
	RequestMethod method_;
	std::string path_;
	RequestType request_object_;
    AbstractResponseHandler<ResponseType>* success_handler_;
    AbstractResponseHandler<ErrorType>* error_handler_;
};

template <class RequestType, class ResponseType, class ErrorType>
const RequestType& RestRequest<RequestType, ResponseType, ErrorType>::request_object() const
{
	return request_object_;
}

template <class RequestType, class ResponseType, class ErrorType>
const RequestMethod& RestRequest<RequestType, ResponseType, ErrorType>::method() const
{
	return method_;
}

template <class RequestType, class ResponseType, class ErrorType>
const std::string& RestRequest<RequestType, ResponseType, ErrorType>::path() const
{
	return path_;
}

template <class RequestType, class ResponseType, class ErrorType>
const AbstractResponseHandler<ResponseType>& RestRequest<RequestType, ResponseType, ErrorType>::success_handler() const
{
    return *success_handler_;
}

template <class RequestType, class ResponseType, class ErrorType>
const AbstractResponseHandler<ErrorType>& RestRequest<RequestType, ResponseType, ErrorType>::error_handler() const
{
    return *error_handler_;
}
