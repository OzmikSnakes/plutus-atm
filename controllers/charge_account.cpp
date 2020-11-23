#include "charge_account.h"
#include "ui_charge_account.h"
#include "dto/requests.h"
#include "dto/responses.h"

#include <QMessageBox>


ChargeAccount::ChargeAccount(Requester& requester, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChargeAccount),
    requester_(requester),
    controller(CashController::getInstance())
{
    ui->setupUi(this);

    QList<Nominal> noms=controller.nominalsAvailable();
    for(int i=0; i<noms.size(); i++){
    ui->comboBox->addItem(QString::number(noms[i].getValue()));
    }

  int amount = ui->spinBox->value();
  int nominal = ui->comboBox->currentText().toInt();
  ui->moneyPut_label->setText(QString::number(amount*nominal));
}



ChargeAccount::~ChargeAccount()
{
    delete ui;
}



void ChargeAccount::on_spinBox_valueChanged(int arg1)
{
    int nominal = ui->comboBox->currentText().toInt();
     ui->moneyPut_label->setText(QString::number(arg1*nominal));
}

void ChargeAccount::on_cancel_pushButton_clicked()
{
    hide();
}

void ChargeAccount::on_comboBox_currentIndexChanged(int index)
{
    int amount = ui->spinBox->value();
    int nominal = ui->comboBox->currentText().toInt();
    ui->moneyPut_label->setText(QString::number(nominal*amount));
}

void ChargeAccount::on_withdraw_pushButton_clicked()
{
    int amount = ui->spinBox->value();
    int nominal = ui->comboBox->currentText().toInt();

    if (controller.putNominal((nominal),amount)==1)
    {
        // todo: path
        ChangeBalanceRequest request = ChangeBalanceRequest();
        request.amount = amount;
        requester_.sendRequest(RestRequest<ChangeBalanceRequest, AccountInfo,
                               ErrorInfo>{RequestMethod::POST, "",
                                          request, success_, error_});
    }

}
