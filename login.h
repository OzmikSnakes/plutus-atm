#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>

#include "menu.h"
#include "response_handler.h"
#include "session_manager.h"


#include "requester.h"

namespace Ui
{
	class Login;
}

class Login : public QDialog
{
Q_OBJECT

public:
	explicit Login(QWidget* parent = nullptr);
	~Login();

private slots:
	void on_login_pushButton_clicked();

	void on_cancel_pushButton_clicked();

	void on_login2_pushButton_clicked();

private:
	Requester requester{
		RestConfiguration{false, "localhost:8080", "api", QSslConfiguration::defaultConfiguration()}, SessionManager::getInstance()
	};
	AuthorizationResponseHandler success{
		SessionManager::getInstance(), [](const TokenInfo& _)
		{
			Menu m;
			m.setModal(true);
			m.exec();
		}
	};

	FunctionResponseHandler<ErrorInfo> error{
		[](const ErrorInfo& error_info)
		{
			QMessageBox messageBox;
			messageBox.warning(nullptr, error_info.error, error_info.message);
		}

	};
	QString card_number;
	Ui::Login* ui;
};

#endif // LOGIN_H
