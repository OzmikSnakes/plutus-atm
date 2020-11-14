#pragma once
#include "converter.h"

enum RequestType { GET, POST, PUT, DELETE, PATCH };

template <class T>
class ResponseHandler
{
  virtual void handle(const T& response) = 0;
public:
    void operator()(const T& response);
    virtual ~ResponseHandler() = default;
};

class ErrorInfo : public ToJsonConvertable
{
  QVariantMap toQVariantMap() const override;
public:
  QString message;
};

template <class R, class C>
class RestRequest
{
public:
    // todo do with builder pattern
    RestRequest(RequestType type, const std::string& path, const R& request_object, const ResponseHandler<C>& success_handler,
              const ResponseHandler<const ErrorInfo&>& error_handler)
    : type_(type),
      path_(path),
      request_object_(request_object),
      success_handler_(success_handler),
      error_handler_(error_handler)
    {}

  const RequestType& type() const;
  const std::string& path() const;
  const R& request_object() const;

  const ResponseHandler<C>& success_handler() const;
  const ResponseHandler<const ErrorInfo&>& error_handler() const;

private:
  RequestType type_;
  std::string path_;
  R request_object_;
  const ResponseHandler<C>& success_handler_;
  const ResponseHandler<const ErrorInfo&>& error_handler_;
};
