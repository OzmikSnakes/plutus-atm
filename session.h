#pragma once

#ifndef SESSION_H
#define SESSION_H

#include <QString>

class Session {
private:
    std::string token;
public:
    std::string getToken() const;
};

#endif // SESSION_H
