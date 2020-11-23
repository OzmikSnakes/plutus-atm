#pragma once
#include <QDialog>
#include <QMessageBox>

#include "controllers/menu.h"
#include "rest_communication/response_handler.h"
#include "rest_communication/session_manager.h"
#include "rest_communication/requester.h"

namespace Ui
{
	class Login;
}

class Login : public QDialog
{
Q_OBJECT

public:
    explicit Login(Requester& requester, Menu& menu, QWidget* parent = nullptr);
	~Login();

private slots:
	void on_login_pushButton_clicked();

	void on_cancel_pushButton_clicked();

	void on_login2_pushButton_clicked();

private:
    Requester& requester_;
    Menu& menu_;
    QString card_number_;
    Ui::Login* ui_;

    AuthorizationResponseHandler success_{
        SessionManager::getInstance(), [this](const TokenInfo&)
        {
            menu_.show();
		}
	};

    FunctionResponseHandler<ErrorInfo> error_{
		[](const ErrorInfo& error_info)
		{
			QMessageBox messageBox;
			messageBox.warning(nullptr, error_info.error, error_info.message);
		}

	};
};
