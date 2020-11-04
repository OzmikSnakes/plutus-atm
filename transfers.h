#ifndef TRANSFERS_H
#define TRANSFERS_H

#include <QDialog>

namespace Ui {
class Transfers;
}

class Transfers : public QDialog
{
    Q_OBJECT

public:
    explicit Transfers(QDialog *parent = nullptr);
    ~Transfers();

private:
    Ui::Transfers *ui;
};

#endif // TRANSFERS_H
