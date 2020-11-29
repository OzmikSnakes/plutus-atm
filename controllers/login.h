#pragma once
#include <QDialog>
#include <QMessageBox>

#include "controllers/menu.h"
#include "rest_communication/response_handler.h"
#include "rest_communication/session_manager.h"
#include "rest_communication/requester.h"

namespace Ui {
	class Login;
}

class Menu;

class Login : public QDialog
{
Q_OBJECT

public:
	explicit Login(Requester& requester, QWidget* parent = nullptr);
	void set_menu(Menu& menu);
	~Login();

private slots:
	void on_login_pushButton_clicked();

	void on_cancel_pushButton_clicked();

	void on_login2_pushButton_clicked();


private:
	static const QRegExp CARD_REGEX;
	static const QRegExp PIN_REGEX;

	Requester& requester_;
	Menu* menu_{nullptr};
	QString card_number_;
	Ui::Login* ui_;
};
