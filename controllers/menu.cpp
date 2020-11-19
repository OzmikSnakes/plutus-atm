#include "menu.h"
#include "ui_menu.h"
#include "cash_withdrawal.h"
#include "charge_account.h"
#include "controllers/transfer.h"
#include "login.h"
#include "automatic_transfer.h"

#include <QMessageBox>

Menu::Menu(QWidget *parent) :
    QDialog(parent),
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
    CashWithdrawal w;
    w.setModal(true);
    w.exec();
}

void Menu::on_chargeAccount_toolButton_clicked()
{
    ChargeAccount w;
    w.setModal(true);
    w.exec();
}

void Menu::on_transfer_toolButton_clicked()
{
    Transfer w;
    w.setModal(true);
    w.exec();
}

void Menu::on_toolButton_clicked()
{
    hide();
    Login w;
    w.setModal(true);
    w.exec();
    this->close();
}

void Menu::on_automaticTransfer_toolButton_clicked()
{
    AutomaticTransfer w;
    w.setModal(true);
    w.exec();
}

void Menu::on_checkBallance_toolButton_clicked()
{
    QMessageBox qm;
    qm.information(0,"Ballance"," Your ballance is: \n Your credit money:");
}
