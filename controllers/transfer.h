#pragma once
#include <QDialog>
#include <QMessageBox>
#include "rest_communication/requester.h"
#include <controllers/menu.h>

namespace Ui {
class Transfer;
}

class Menu;

class Transfer : public QDialog
{
    Q_OBJECT

public:
    explicit Transfer(Requester& requester, QWidget *parent = nullptr);
    void set_menu(Menu&);
    ~Transfer();

private slots:
    void on_pushButton_clicked();
    void on_transfer_pushButton_clicked();

private:
    Menu* menu_;
    Ui::Transfer *ui;
    Requester& requester_;
};
