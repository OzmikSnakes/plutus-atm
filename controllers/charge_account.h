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

    FunctionResponseHandler<AccountInfo> success_{
        [](const AccountInfo& accountInfo)
        {
            QMessageBox messageBox;
            messageBox.information(nullptr, "Information", "Operation successfull! "
                                   + QString::number(accountInfo.moneyAmount) +
                                   " UAH is on your card.");
        }
    };

    FunctionResponseHandler<ErrorInfo> error_{
        [](const ErrorInfo& error_info)
        {
            QMessageBox messageBox;
            messageBox.warning(nullptr, error_info.error, error_info.message);
        }
    };
};
