#pragma once
#include "converter.h"

class ErrorInfo : public Convert

template<class R, class C> class RestRequest
{
private:
    std::string path;
    R requestObject;
};

