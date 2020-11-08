#include "login.h"
#include "ui_login.h"
#include "menu.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_pushButton_clicked()
{
    QRegExp re("\\d{16}");

    QString card_number = ui->card_lineField->text().replace(" ","");
    if(!re.exactMatch(card_number)){
        QMessageBox messageBox;
        messageBox.warning(0,"Error","Card number is not right!");
        messageBox.setFixedSize(500,200);
    }
    else{

    ui->stackedWidget->setCurrentIndex(1);}
}

void Login::on_cancel_pushButton_clicked()
{

    ui->card_lineField->clear();
    ui->stackedWidget->setCurrentIndex(0);

}

void Login::on_login2_pushButton_clicked()
{
    QString pin = ui->password_lineEdit->text().replace(" ","");
    QRegExp re("\\d{4}");
    if(re.exactMatch(pin)&&true){
    hide();
    Menu m ;
    m.setModal(true);
    m.exec();
    }
    else   {
    QMessageBox messageBox;
    messageBox.warning(0,"Error","No such user in our database!");
}
}
