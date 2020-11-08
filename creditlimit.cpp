#include "creditlimit.h"
#include "ui_creditlimit.h"

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
