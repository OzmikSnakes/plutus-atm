#ifndef SESSION_MANAGER_H
#define SESSION_MANAGER_H

#include "session.h"

class SessionManager
{
public:
    static SessionManager* getInstance();
    Session getCurrentSession() const;
private:
    Session session;
    static SessionManager* instance;
    SessionManager() {};
    SessionManager(SessionManager const&) {};
    SessionManager& operator=(SessionManager const&) {};
};

#endif // SESSION_MANAGER_H
