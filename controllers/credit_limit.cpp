#include "credit_limit.h"
#include "ui_credit_limit.h"

CreditLimit::CreditLimit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditLimit)
{
    ui->setupUi(this);
}

CreditLimit::~CreditLimit()
{
    delete ui;
}
