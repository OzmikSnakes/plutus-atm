#include "controllers/login.h"
#include "ui_login.h"
#include "controllers/menu.h"
#include <QMessageBox>
#include "rest_communication/requester.h"
#include "dto/requests.h"
#include "rest_communication/response_handler.h"

Login::Login(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::Login)
{
	ui->setupUi(this);
	ui->stackedWidget->setCurrentIndex(0);
}

Login::~Login()
{
	delete ui;
}

void Login::on_login_pushButton_clicked()
{
	QRegExp re("\\d{16}");

	card_number = ui->card_lineField->text().replace(" ", "");
	if (!re.exactMatch(card_number))
	{
		QMessageBox messageBox;
		messageBox.warning(0, "Error", "Card number is not right!");
		messageBox.setFixedSize(500, 200);
	}
	else
	{
		ui->stackedWidget->setCurrentIndex(1);
	}
}

void Login::on_cancel_pushButton_clicked()
{
	ui->card_lineField->clear();
	ui->stackedWidget->setCurrentIndex(0);
}

void Login::on_login2_pushButton_clicked()
{
	QString pin = ui->password_lineEdit->text().replace(" ", "");
	QRegExp re("\\d{4}");
	if (re.exactMatch(pin))
	{
		hide();
		ATMTokenRequest login_request;
		login_request.accountNumber = card_number.toStdString();
		login_request.pin = pin.toStdString();
		requester.sendRequest(RestRequest<ATMTokenRequest, TokenInfo, ErrorInfo>{RequestMethod::POST, "auth/atm/token", login_request, success, error});
	}
	else
	{
		QMessageBox messageBox;
		messageBox.warning(0, "Error", "No such user in our database!");
	}
}
