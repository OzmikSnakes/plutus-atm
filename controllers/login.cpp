#include "controllers/login.h"
#include "build/ui_login.h"
#include "controllers/menu.h"
#include <QMessageBox>
#include "rest_communication/requester.h"
#include "dto/requests.h"
#include "rest_communication/response_handler.h"

const QRegExp Login::CARD_REGEX{"\\d{16}"};
const QRegExp Login::PIN_REGEX{"\\d{4}"};

Login::Login(Requester& requester, Menu& menu, QWidget* parent) :
	QDialog(parent),
	requester_(requester),
	menu_(menu),
	ui_(new Ui::Login) // new?
{
	ui_->setupUi(this);
	ui_->stackedWidget->setCurrentIndex(0);
}

Login::~Login() {
	delete ui_;
}

void Login::on_login_pushButton_clicked() {
	card_number_ = ui_->card_lineField->text().trimmed();
	if (!CARD_REGEX.exactMatch(card_number_)) {
		QMessageBox::warning(nullptr, "Error", "Card number is incorrect!");
	}
	else {
		ui_->stackedWidget->setCurrentIndex(1);
	}
}

void Login::on_cancel_pushButton_clicked() const {
	ui_->card_lineField->clear();
	ui_->stackedWidget->setCurrentIndex(0);
}

void Login::on_login2_pushButton_clicked() const {
    AuthorizationResponseHandler* successful_authentication_handler_ = new AuthorizationResponseHandler{
        SessionManager::getInstance(), [this](const TokenInfo&) {
            menu_.show();
        }
    };

    FunctionResponseHandler<ErrorInfo>* authentication_error_handler_ = new FunctionResponseHandler<ErrorInfo>{
        [](const ErrorInfo& error_info) {
            QMessageBox::warning(nullptr, error_info.error, error_info.message);
        }

    };

	QString pin = ui_->password_lineEdit->text().trimmed();
	if (PIN_REGEX.exactMatch(pin)) {
		ATMTokenRequest login_request;
		login_request.accountNumber = card_number_.toStdString();
		login_request.pin = pin.toStdString();
		requester_.sendRequest(RestRequest<ATMTokenRequest, TokenInfo, ErrorInfo>{
			RequestMethod::POST, "auth/atm/token", login_request, successful_authentication_handler_, authentication_error_handler_
		});
	}
	else {
		QMessageBox::warning(nullptr, "Error", "Invalid pin code format!");
	}
}
