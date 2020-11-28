#include "controllers/transfer.h"
#include "build/ui_transfer.h"
#include "dto/requests.h"
#include "dto/responses.h"

Transfer::Transfer(Requester& requester, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transfer),
    requester_(requester)
{
    ui->setupUi(this);
}

Transfer::~Transfer()
{
    delete ui;
}

void Transfer::on_pushButton_clicked()
{
    hide();
}

void Transfer::on_transfer_pushButton_clicked()
{
    FunctionResponseHandler<TransferInfo>* success_ = new FunctionResponseHandler<TransferInfo>{
        [](const TransferInfo& transferInfo)
        {
            QMessageBox messageBox;
            messageBox.information(nullptr, "Information", "Operation successfull! "
                                   + QString::number(transferInfo.amount) +
                                   " UAH was sent to " + transferInfo.toId + ".");
        }
    };

    FunctionResponseHandler<ErrorInfo>* error_ = new FunctionResponseHandler<ErrorInfo>{
        [](const ErrorInfo& error_info)
        {
            QMessageBox messageBox;
            messageBox.warning(nullptr, error_info.error, error_info.message);
        }
    };

    std::string toId = ui->lineEdit->text().toStdString();
    double amount = ui->money_doubleSpinBox->value();
    if (amount > 0)
    {
        MakeTransferRequest request = MakeTransferRequest();
        request.amount = amount;
        request.toId = toId;
        requester_.sendRequest(RestRequest<MakeTransferRequest, TransferInfo,
                               ErrorInfo>{RequestMethod::POST, "secured/transfer/makeTransfer",request, success_, error_});
    }
}
