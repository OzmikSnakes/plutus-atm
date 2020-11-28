#pragma once
#include <QDialog>
#include "cashcontroller.h"
#include "rest_communication/requester.h"
#include "dto/requests.h"
#include <QMessageBox>

namespace Ui {
class ChargeAccount;
}

class ChargeAccount : public QDialog
{
    Q_OBJECT

public:
    explicit ChargeAccount(Requester& requester, QWidget *parent = nullptr);
    ~ChargeAccount();

private slots:

    void on_spinBox_valueChanged(int arg1);

    void on_cancel_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_withdraw_pushButton_clicked();

private:
    Ui::ChargeAccount *ui;
    Requester& requester_;
    CashController controller;
};
