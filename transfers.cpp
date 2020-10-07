#include "transfers.h"
#include "ui_transfers.h"

Transfers::Transfers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transfers)
{
    ui->setupUi(this);
}

Transfers::~Transfers()
{
    delete ui;
}
