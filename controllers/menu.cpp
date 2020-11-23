#include "menu.h"
#include "build/ui_menu.h"
#include "cash_withdrawal.h"
#include "charge_account.h"
#include "controllers/transfer.h"
#include "login.h"
#include "automatic_transfer.h"

#include <QMessageBox>

Menu::Menu(Requester& requester, CashWithdrawal& cash_withdrawal, ChargeAccount& charge_account,
           CreditLimit& credit_limit, Transfer& transfer, QWidget* parent)
	: QDialog(parent), requester_(requester), cash_withdrawal_(cash_withdrawal), charge_account_(charge_account),
	  credit_limit_(credit_limit), transfer_(transfer), ui_(new Ui::Menu) {
	ui_->setupUi(this);
}


Menu::~Menu() {
	delete ui_;
}

void Menu::on_cash_withdrawal_clicked() {
	cash_withdrawal_.setModal(true);
	cash_withdrawal_.exec();
}

void Menu::on_charge_account_clicked() {

	charge_account_.setModal(true);
	charge_account_.exec();
}

void Menu::on_transfer_clicked() {
	transfer_.setModal(true);
	transfer_.exec();
}

void Menu::on_toolButton_clicked() {
	hide();
}

void Menu::on_automatic_transfer_clicked() {}

void Menu::on_creditLimit_toolButton_clicked() {
	credit_limit_.setModal(true);
	credit_limit_.exec();
}

void Menu::on_check_Balance_toolButton_clicked()
{
    RestRequest<EmptyRequest, AccountInfo, ErrorInfo> request{
        RequestMethod::GET, "secured/account/", EmptyRequest{}, check_balance_success_handler, check_balance_error_handler
    };
    requester_.sendRequest(request);
}
