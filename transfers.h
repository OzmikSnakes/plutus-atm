#ifndef TRANSFERS_H
#define TRANSFERS_H

#include <QWidget>

namespace Ui {
class Transfers;
}

class Transfers : public QWidget
{
    Q_OBJECT

public:
    explicit Transfers(QWidget *parent = nullptr);
    ~Transfers();

private:
    Ui::Transfers *ui;
};

#endif // TRANSFERS_H
