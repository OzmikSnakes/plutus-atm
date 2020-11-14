#include "session_manager.h"

SessionManager* SessionManager::instance = nullptr;

SessionManager* SessionManager::getInstance()
{
    if (!instance)
          instance = new SessionManager;
       return instance;
}

Session SessionManager::getCurrentSession() const { return session; }
