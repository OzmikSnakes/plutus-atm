#pragma once
#include "controllers/cash_withdrawal.h"
#include "controllers/charge_account.h"
#include "controllers/credit_limit.h"
#include "controllers/transfer.h"
#include <QDialog>

namespace Ui {
	class Menu;
}

class Menu : public QDialog
{
Q_OBJECT

public:
	explicit Menu(Requester& requester, CashWithdrawal& cash_withdrawal, ChargeAccount& charge_account,
	              CreditLimit& credit_limit, Transfer& transfer, QWidget* parent = nullptr);
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
	CashWithdrawal& cash_withdrawal_;
	ChargeAccount& charge_account_;
	CreditLimit& credit_limit_;
	Transfer& transfer_;
	Ui::Menu* ui_;
};
