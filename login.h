#ifndef ATM_H
#define ATM_H

#include <QDialog>

namespace Ui {
class ATM;
}

class ATM : public QDialog
{
    Q_OBJECT

public:
    explicit ATM(QWidget *parent = nullptr);
    ~ATM();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ATM *ui;
};

#endif // ATM_H
