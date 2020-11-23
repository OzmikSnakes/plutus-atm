#pragma once

#include "rest_communication/requester.h"

#include <QDialog>

namespace Ui {
class AutomaticTransfer;
}

class AutomaticTransfer : public QDialog
{
    Q_OBJECT

public:
    explicit AutomaticTransfer(QWidget *parent = nullptr);
    ~AutomaticTransfer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AutomaticTransfer *ui;
};
