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
