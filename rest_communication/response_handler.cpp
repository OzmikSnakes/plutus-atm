#include "response_handler.h"

AuthorizationResponseHandler::AuthorizationResponseHandler(AbstractSessionManager<Session>& session_manager,
                                                           const std::function<void(const TokenInfo&)>& function)
	: FunctionResponseHandler<TokenInfo>{function}, session_manager_(session_manager)
{
}


void AuthorizationResponseHandler::handle(const TokenInfo& response) const
{
	const auto maybeSession{session_manager_.current_session()};
	if (maybeSession.has_value())
	{
		Session session{maybeSession.value()};
		session.jwt_token = response.token.toStdString();
		session_manager_.current_session(session);
	}
	else
	{
		const Session session{response.token.toStdString(), ""};
		session_manager_.current_session(session);
	}
	FunctionResponseHandler<TokenInfo>::handle(response);
}
