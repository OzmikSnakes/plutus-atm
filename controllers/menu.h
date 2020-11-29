#pragma once
#include "rest_communication/requester.h"
#include <QDialog>

namespace Ui {
	class Menu;
}

class Login;
class CashWithdrawal;
class ChargeAccount;
class Transfer;

class Menu : public QDialog
{
Q_OBJECT

public:
    explicit Menu(Requester& requester, Login& login, CashWithdrawal& cash_withdrawal, ChargeAccount& charge_account, Transfer& transfer, QWidget* parent = nullptr);
	~Menu();

private slots:
    void on_cashWithdrawal_toolButton_clicked();
    void on_chargeAccount_toolButton_clicked();
    void on_transfer_toolButton_clicked();
	void on_toolButton_clicked();
	void on_automatic_transfer_clicked();
	void on_creditLimit_toolButton_clicked();
    void on_check_Balance_toolButton_clicked();
private:
	Requester& requester_;
	Login& login_;
	CashWithdrawal& cash_withdrawal_;
	ChargeAccount& charge_account_;
	Transfer& transfer_;
	Ui::Menu* ui_;
};
