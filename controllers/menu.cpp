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

void Menu::on_cashWithdrawal_toolButton_clicked()
{
    cash_withdrawal_.setModal(true);
    cash_withdrawal_.exec();
}

void Menu::on_chargeAccount_toolButton_clicked()
{
    charge_account_.setModal(true);
    charge_account_.exec();
}

void Menu::on_transfer_toolButton_clicked() {
	transfer_.setModal(true);
	transfer_.exec();
}

void Menu::on_toolButton_clicked() {
    requester_.session_manager().clear_current_session();
	hide();
}

void Menu::on_automatic_transfer_clicked() {}

void Menu::on_creditLimit_toolButton_clicked() {
    FunctionResponseHandler<CreditTariffInfo>* check_credit_tariff_success_handler = new FunctionResponseHandler<CreditTariffInfo>{
        [this](const CreditTariffInfo& credit_tariff_info) {
            QMessageBox::information(this, "Credit Tariff", QString{"Your credit limit is: %1"}.arg(credit_tariff_info.limit));
        }
    };

    FunctionResponseHandler<ErrorInfo>* check_balance_error_handler = new FunctionResponseHandler<ErrorInfo>{
        [this](const ErrorInfo& error_info) {
            QMessageBox::warning(this, "Error", "Unexpected error occurred! Please try again later.");
        }
    };

    RestRequest<EmptyRequest, CreditTariffInfo, ErrorInfo> request{
        RequestMethod::GET, "secured/creditTariff/", EmptyRequest{}, check_credit_tariff_success_handler, check_balance_error_handler
    };
    requester_.sendRequest(request);
}

void Menu::on_check_Balance_toolButton_clicked()
{
    FunctionResponseHandler<AccountInfo>* check_balance_success_handler = new FunctionResponseHandler<AccountInfo>{
        [this](const AccountInfo& account_info) {
            QMessageBox::information(this, "Balance", QString{"Your balance is: %1"}.arg(account_info.moneyAmount));
        }
    };

    FunctionResponseHandler<ErrorInfo>* check_balance_error_handler = new FunctionResponseHandler<ErrorInfo>{
        [this](const ErrorInfo& error_info) {
            QMessageBox::warning(this, "Error", "Unexpected error occurred! Please try again later.");
        }
    };

    RestRequest<EmptyRequest, AccountInfo, ErrorInfo> request{
        RequestMethod::GET, "secured/account/", EmptyRequest{}, check_balance_success_handler, check_balance_error_handler
    };
    requester_.sendRequest(request);
}
