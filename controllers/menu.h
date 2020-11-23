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
	void on_cash_withdrawal_clicked();
	void on_charge_account_clicked();
	void on_transfer_clicked();
	void on_toolButton_clicked();
	void on_automatic_transfer_clicked();
	void on_creditLimit_toolButton_clicked();
    void on_check_Balance_toolButton_clicked();

private:
	FunctionResponseHandler<AccountInfo> check_balance_success_handler{
		[this](const AccountInfo& account_info) {
			QMessageBox::information(this, "Balance", QString{"Your balance is: %1"}.arg(account_info.moneyAmount));
		}
	};

	FunctionResponseHandler<ErrorInfo> check_balance_error_handler{
		[this](const ErrorInfo& error_info) {
			QMessageBox::warning(this, "Error", "Unexpected error occurred! Please try again later.");
		}
	};

	Requester& requester_;
	CashWithdrawal& cash_withdrawal_;
	ChargeAccount& charge_account_;
	CreditLimit& credit_limit_;
	Transfer& transfer_;
	Ui::Menu* ui_;
};
