#include "charge_account.h"
#include "build/ui_charge_account.h"
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

void ChargeAccount::set_menu(Menu& menu) {
    menu_ = &menu;
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
    menu_->show();
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

    FunctionResponseHandler<TransferInfo>* success_ = new FunctionResponseHandler<TransferInfo>{
        [](const TransferInfo& transferInfo)
        {
            QMessageBox messageBox;
            messageBox.information(nullptr, "Information", "Operation successfull!");
        }
    };

    FunctionResponseHandler<ErrorInfo>* error_ = new FunctionResponseHandler<ErrorInfo>{
        [](const ErrorInfo& error_info)
        {
            QMessageBox messageBox;
            messageBox.warning(nullptr, error_info.error, error_info.message);
        }
    };
    // todo
    if (controller.putNominal((nominal),amount)==1)
    {
        ChangeBalanceRequest request = ChangeBalanceRequest();
        request.amount = amount * nominal;
        requester_.sendRequest(RestRequest<ChangeBalanceRequest, TransferInfo,ErrorInfo>{RequestMethod::POST, "secured/transfer/changeBalance", request, success_, error_});
    }

}
