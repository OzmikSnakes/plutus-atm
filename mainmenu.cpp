#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "transfers.h"
#include "creditlimit.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_transfer_toolButton_clicked()
{
    Transfers* tr = new Transfers();
    tr->show();
}

void MainMenu::on_creditLimit_toolButton_clicked()
{
    CreditLimit* cl = new CreditLimit();
    cl->show();
}
