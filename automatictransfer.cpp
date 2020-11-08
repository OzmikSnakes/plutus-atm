#include "automatictransfer.h"
#include "ui_automatictransfer.h"

AutomaticTransfer::AutomaticTransfer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AutomaticTransfer)
{
    ui->setupUi(this);
}

AutomaticTransfer::~AutomaticTransfer()
{
    delete ui;
}

void AutomaticTransfer::on_pushButton_clicked()
{
    this->close();
}
