#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_transfer_toolButton_clicked();

    void on_creditLimit_toolButton_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
