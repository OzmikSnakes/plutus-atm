#include "controllers/login.h"
#include "ui_login.h"
#include "controllers/menu.h"
#include <QMessageBox>
#include "rest_communication/requester.h"
#include "dto/requests.h"
#include "rest_communication/response_handler.h"

Login::Login(Requester& requester, Menu& menu, QWidget* parent) :
	QDialog(parent),
    requester_(requester),
    menu_(menu),
    ui_(new Ui::Login) // new?
{
    ui_->setupUi(this);
    ui_->stackedWidget->setCurrentIndex(0);
}

Login::~Login()
{
    delete ui_;
}

void Login::on_login_pushButton_clicked()
{
	QRegExp re("\\d{16}");

    card_number_ = ui_->card_lineField->text().replace(" ", "");
    if (!re.exactMatch(card_number_))
	{
		QMessageBox messageBox;
        messageBox.warning(0, "Error", "Card number is incorrect!");
		messageBox.setFixedSize(500, 200);
    } else
	{
        ui_->stackedWidget->setCurrentIndex(1);
	}
}

void Login::on_cancel_pushButton_clicked()
{
    ui_->card_lineField->clear();
    ui_->stackedWidget->setCurrentIndex(0);
}

void Login::on_login2_pushButton_clicked()
{
    QString pin = ui_->password_lineEdit->text().replace(" ", "");
	QRegExp re("\\d{4}");
	if (re.exactMatch(pin))
    {
        ATMTokenRequest login_request;
        login_request.accountNumber = card_number_.toStdString();
        login_request.pin = pin.toStdString();
        requester_.sendRequest(RestRequest<ATMTokenRequest, TokenInfo,
                               ErrorInfo>{RequestMethod::POST, "auth/atm/token",
                                          login_request, success_, error_});
    } else
	{
		QMessageBox messageBox;
		messageBox.warning(0, "Error", "No such user in our database!");
	}
}
