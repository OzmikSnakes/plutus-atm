#pragma once
#include <QDialog>
#include <QMessageBox>
#include "rest_communication/requester.h"

namespace Ui {
class Transfer;
}

class Transfer : public QDialog
{
    Q_OBJECT

public:
    explicit Transfer(Requester& requester, QWidget *parent = nullptr);
    ~Transfer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton2_clicked();

private:
    Ui::Transfer *ui;
    Requester& requester_;

    FunctionResponseHandler<TransferInfo> success_{
        [](const TransferInfo& transferInfo)
        {
            QMessageBox messageBox;
            messageBox.information(nullptr, "Information", "Operation successfull! "
                                   + QString::number(transferInfo.amount) +
                                   " UAH was sent to " + transferInfo.toId + ".");
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
