#include "rest_request.h"

template <class T>
void ResponseHandler<T>::operator()(const T& response)
{
  handle(response);
}

template <class R, class C>
const RequestType& RestRequest<R, C>::type() const
{
  return type_;
}

template <class R, class C>
const std::string& RestRequest<R, C>::path() const
{
  return path_;
}

template <class R, class C>
const R& RestRequest<R, C>::request_object() const
{
  return request_object_;
}

template <class R, class C>
const ResponseHandler<C>& RestRequest<R, C>::success_handler() const
{
  return success_handler_;
}

template <class R, class C>
const ResponseHandler<const ErrorInfo&>& RestRequest<R, C>::error_handler() const
{
  return error_handler_;
}

QVariantMap ErrorInfo::toQVariantMap() const
{
  QVariantMap map;
  map["message"] = message;
  return map;
}
