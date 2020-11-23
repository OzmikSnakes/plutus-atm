#include "menu.h"
#include "ui_menu.h"
#include "cash_withdrawal.h"
#include "charge_account.h"
#include "controllers/transfer.h"
#include "login.h"
#include "automatic_transfer.h"

#include <QMessageBox>

Menu::Menu(CashWithdrawal& cash_withdrawal, ChargeAccount& charge_account,
           CreditLimit& credit_limit, Transfer& transfer, QWidget *parent) :
    QDialog(parent),
    cash_withdrawal_(cash_withdrawal),
    charge_account_(charge_account),
    credit_limit_(credit_limit),
    transfer_(transfer),
    ui(new Ui::Menu)
{

    ui->setupUi(this);
    //this->setAttribute(Qt::WA_DeleteOnClose);
}


Menu::~Menu()
{
    delete ui;
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

void Menu::on_transfer_toolButton_clicked()
{
    transfer_.setModal(true);
    transfer_.exec();
}

void Menu::on_toolButton_clicked()
{
    hide();
}

void Menu::on_automaticTransfer_toolButton_clicked()
{

}

void Menu::on_checkBallance_toolButton_clicked()
{
    QMessageBox qm;
    qm.information(0,"Ballance"," Your ballance is: \n Your credit money:");
}

void Menu::on_creditLimit_toolButton_clicked()
{
    credit_limit_.setModal(true);
    credit_limit_.exec();
}
