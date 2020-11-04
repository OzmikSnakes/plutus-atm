#ifndef RESTREQUEST_H
#define RESTREQUEST_H

#include <QString>

template<class R, class C> class RestRequest
{
private:
    QString path;
    R requestObject;
};

#endif // RESTREQUEST_H
