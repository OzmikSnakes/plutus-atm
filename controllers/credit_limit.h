#pragma once
#include <QDialog>
#include "rest_communication/requester.h"

namespace Ui {
class CreditLimit;
}

class CreditLimit : public QDialog
{
    Q_OBJECT

public:
    explicit CreditLimit(Requester& requester, QWidget *parent = nullptr);
    ~CreditLimit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton2_clicked();

private:
    Requester& requester_;
    Ui::CreditLimit *ui;
};
