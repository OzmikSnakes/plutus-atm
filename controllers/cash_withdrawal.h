#pragma once
#include "cashcontroller.h"
#include <QDialog>

namespace Ui {
class CashWithdrawal;
}

class CashWithdrawal : public QDialog
{
    Q_OBJECT

public:
    explicit CashWithdrawal(QWidget *parent = nullptr);
    ~CashWithdrawal();

private slots:
    void on_cancel_pushButton_clicked();

    void on_withdraw_pushButton_clicked();

private:
    Ui::CashWithdrawal *ui;
    CashController controller;
};
