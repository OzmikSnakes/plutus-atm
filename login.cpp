#include "login.h"
#include "ui_login.h"
#include "mainmenu.h"

ATM::ATM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ATM)
{
    ui->setupUi(this);
}

ATM::~ATM()
{
    delete ui;
}

void ATM::on_pushButton_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
}

void ATM::on_pushButton_2_clicked()
{
    hide();
    MainMenu w ;

    w.show();
}
