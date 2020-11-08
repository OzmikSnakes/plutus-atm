#include "cashwithdrawal.h"
#include "ui_cashwithdrawal.h"
#include "menu.h"
#include "cashcontroller.h"

#include <QMessageBox>






CashWithdrawal::CashWithdrawal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CashWithdrawal),
    controller(CashController::getInstance())
{
    ui->setupUi(this); 
    ui->nominas->setText(controller.nominalsAvailableString());

}

CashWithdrawal::~CashWithdrawal()
{
    delete ui;

}

void CashWithdrawal::on_cancel_pushButton_clicked()
{
  this->close();
}

void CashWithdrawal::on_withdraw_pushButton_clicked()
{
    QMessageBox messageBox;
    int amount = ui->spinBox->value();
    if(controller.canWithdraw(amount)){
    messageBox.information(0,"Congrats","All good!");
    }
    else
     messageBox.warning(0,"Error", "Can not be withdrawn!");
}
