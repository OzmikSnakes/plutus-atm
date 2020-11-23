#include "controllers/transfer.h"
#include "ui_transfer.h"
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

void Transfer::on_pushButton2_clicked()
{
    long toId = ui->lineEdit->text().toLong();
    long fromId = 0;
    double amount = ui->money_doubleSpinBox->value();
    if (amount > 0)
    {
        // todo: path
        MakeTransferRequest request = MakeTransferRequest();
        request.amount = amount;
        request.toId = toId;
        request.description = "Send " + std::to_string(amount) + " UAH to " + std::to_string(toId) + ".";
        requester_.sendRequest(RestRequest<MakeTransferRequest, TransferInfo,
                               ErrorInfo>{RequestMethod::POST, "",
                                          request, success_, error_});
    }
}


