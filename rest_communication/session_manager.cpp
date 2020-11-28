#include "session_manager.h"

SessionManager* SessionManager::INSTANCE_ = nullptr;

Session::Session(std::string jwt_token_, std::string csrf_token_)
	: jwt_token(std::move(jwt_token_)),
	  csrf_token(std::move(csrf_token_))
{
}

SessionManager& SessionManager::getInstance()
{
	if (!INSTANCE_)
	{
		INSTANCE_ = new SessionManager();
	}
	return *INSTANCE_;
}

void SessionManager::set_current_session(const Session& session)
{
	delete cur_session_;
	cur_session_ = new Session{session};
}

std::optional<Session> SessionManager::get_current_session() const
{
	if (cur_session_)
	{
		return {*cur_session_};
	}
	return std::nullopt;
}

void SessionManager::clear_session(){
    delete cur_session_;
    cur_session_ = nullptr;
}
