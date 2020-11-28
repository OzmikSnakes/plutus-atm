#pragma once
#include "cashcontroller.h"
#include "rest_communication/requester.h"
#include "dto/requests.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class CashWithdrawal;
}

class CashWithdrawal : public QDialog
{
    Q_OBJECT

public:
    explicit CashWithdrawal(Requester& requester, QWidget *parent = nullptr);
    ~CashWithdrawal();

private slots:
    void on_cancel_pushButton_clicked();

    void on_withdraw_pushButton_clicked();

private:
    Requester& requester_;
    Ui::CashWithdrawal *ui;
    CashController controller;
};
