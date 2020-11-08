#include "chargeaccount.h"
#include "ui_chargeaccount.h"


ChargeAccount::ChargeAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChargeAccount),
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
    this->close();
}
