#include "cash_withdrawal.h"
#include "build/ui_cash_withdrawal.h"
#include "menu.h"
#include "cashcontroller.h"
#include "dto/requests.h"
#include "dto/responses.h"
#include "rest_communication/rest_request.h"

#include <QMessageBox>

CashWithdrawal::CashWithdrawal(Requester& requester, QWidget *parent) :
    QDialog(parent),
    requester_(requester),
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
    hide();
}

void CashWithdrawal::on_withdraw_pushButton_clicked()
{
    FunctionResponseHandler<TransferInfo>* success_ = new FunctionResponseHandler<TransferInfo>{
        [this](const TransferInfo& transferInfo)
        {
            QString message{"Operation successfull!"};
            QMessageBox::information(this, "Information", message);
        }
    };

    FunctionResponseHandler<ErrorInfo>* error_ = new FunctionResponseHandler<ErrorInfo>{
        [](const ErrorInfo& error_info)
        {
            QMessageBox messageBox;
            messageBox.warning(nullptr, error_info.error, error_info.message);
        }
    };

    QMessageBox messageBox;
    int amount = ui->spinBox->value();
    QMap<Nominal, int> withdrawnMoney = controller.withdrawCash(amount);
    if (!withdrawnMoney.empty())
    {
        ChangeBalanceRequest request = ChangeBalanceRequest();
        request.amount = -amount;
        requester_.sendRequest(RestRequest<ChangeBalanceRequest, TransferInfo, ErrorInfo>{
                                   RequestMethod::POST, "secured/transfer/changeBalance",request, success_, error_});

    } else
    {
        messageBox.warning(0,"Error", "Can`t be withdrawn!");
    }
}
