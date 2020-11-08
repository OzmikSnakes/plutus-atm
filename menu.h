#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_cashWithdrawal_toolButton_clicked();

    void on_chargeAccount_toolButton_clicked();

    void on_transfer_toolButton_clicked();

    void on_toolButton_clicked();

    void on_automaticTransfer_toolButton_clicked();

    void on_checkBallance_toolButton_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
