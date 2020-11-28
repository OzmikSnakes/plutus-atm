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
    void on_transfer_pushButton_clicked();

private:
    Ui::Transfer *ui;
    Requester& requester_;
};
