#ifndef CREDITLIMIT_H
#define CREDITLIMIT_H

#include <QWidget>

namespace Ui {
class CreditLimit;
}

class CreditLimit : public QWidget
{
    Q_OBJECT

public:
    explicit CreditLimit(QWidget *parent = nullptr);
    ~CreditLimit();

private:
    Ui::CreditLimit *ui;
};

#endif // CREDITLIMIT_H
