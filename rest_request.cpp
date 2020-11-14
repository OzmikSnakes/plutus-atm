#include "rest_request.h"

QVariantMap ErrorInfo::toQVariantMap() const
{
  QVariantMap map;
  map["message"] = message;
  return map;
}
