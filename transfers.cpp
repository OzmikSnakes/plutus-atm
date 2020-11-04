#include "transfers.h"
#include "ui_transfers.h"

Transfers::Transfers(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Transfers)
{
    ui->setupUi(this);
}

Transfers::~Transfers()
{
    delete ui;
}
