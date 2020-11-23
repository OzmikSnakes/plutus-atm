#pragma once
#include <string>
#include <optional>

template <class T>
class AbstractSessionManager
{
	[[nodiscard]] virtual std::optional<T> get_current_session() const = 0;
	virtual void set_current_session(const T&) = 0;
public:
	[[nodiscard]] std::optional<T> current_session() const;
	void current_session(const T&);
	virtual ~AbstractSessionManager() = default;
};

template <class T>
std::optional<T> AbstractSessionManager<T>::current_session() const
{
	return get_current_session();
}

template <class T>
void AbstractSessionManager<T>::current_session(const T& session)
{
	return set_current_session(session);
}

struct Session
{
	std::string jwt_token;
	std::string csrf_token;
    std::string cardNumber;
	Session(std::string, std::string);
	Session(const Session&) = default;
};

class SessionManager : public AbstractSessionManager<Session>
{
public:
	static SessionManager& getInstance();
	SessionManager(const SessionManager&) = delete;
private:
	Session* cur_session_{nullptr};
	static SessionManager* INSTANCE_;

	void set_current_session(const Session&) override;
	[[nodiscard]] std::optional<Session> get_current_session() const override;
	SessionManager() = default;
};
