#include "credit_limit.h"
#include "ui_credit_limit.h"
#include "dto/requests.h"
#include "dto/responses.h"

CreditLimit::CreditLimit(Requester& requester, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditLimit),
    requester_(requester)
{
    ui->setupUi(this);
}

CreditLimit::~CreditLimit()
{
    delete ui;
}

void CreditLimit::on_pushButton_clicked()
{
    hide();
}

void CreditLimit::on_pushButton2_clicked()
{
    int amount = ui->spinBox->value();
    if (amount >= 0)
    {
       // todo: make request
    }
}
