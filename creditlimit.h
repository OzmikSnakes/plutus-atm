#ifndef CREDITLIMIT_H
#define CREDITLIMIT_H

#include <QDialog>

namespace Ui {
class CreditLimit;
}

class CreditLimit : public QDialog
{
    Q_OBJECT

public:
    explicit CreditLimit(QWidget *parent = nullptr);
    ~CreditLimit();

private:
    Ui::CreditLimit *ui;
};

#endif // CREDITLIMIT_H
