#pragma once
#include "cashcontroller.h"
#include "rest_communication/requester.h"
#include "dto/requests.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
	class CashWithdrawal;
}

class Menu;

class CashWithdrawal : public QDialog
{
Q_OBJECT

public:
	explicit CashWithdrawal(Requester& requester, QWidget* parent = nullptr);
	void set_menu(Menu&);
	~CashWithdrawal();

private slots:
	void on_cancel_pushButton_clicked();

	void on_withdraw_pushButton_clicked();

private:
	Menu* menu_;
	Requester& requester_;
	Ui::CashWithdrawal* ui;
	CashController controller;
};
