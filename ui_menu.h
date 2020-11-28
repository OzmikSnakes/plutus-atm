/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *menu_label;
    QLabel *choose_label;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QToolButton *chargeAccount_toolButton;
    QToolButton *overCredit_toolButton;
    QToolButton *creditLimit_toolButton;
    QToolButton *transfer_toolButton;
    QToolButton *check_Balance_toolButton;
    QToolButton *cashWithdrawal_toolButton;
    QToolButton *exess_toolButton;
    QToolButton *automaticTransfer_toolButton;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton;

    void setupUi(QDialog *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Menu);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        menu_label = new QLabel(Menu);
        menu_label->setObjectName(QString::fromUtf8("menu_label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menu_label->sizePolicy().hasHeightForWidth());
        menu_label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(22);
        menu_label->setFont(font);
        menu_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(menu_label);

        choose_label = new QLabel(Menu);
        choose_label->setObjectName(QString::fromUtf8("choose_label"));
        QFont font1;
        font1.setPointSize(12);
        choose_label->setFont(font1);
        choose_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(choose_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        chargeAccount_toolButton = new QToolButton(Menu);
        chargeAccount_toolButton->setObjectName(QString::fromUtf8("chargeAccount_toolButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(chargeAccount_toolButton->sizePolicy().hasHeightForWidth());
        chargeAccount_toolButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(chargeAccount_toolButton, 3, 0, 1, 1);

        overCredit_toolButton = new QToolButton(Menu);
        overCredit_toolButton->setObjectName(QString::fromUtf8("overCredit_toolButton"));
        overCredit_toolButton->setEnabled(false);
        sizePolicy1.setHeightForWidth(overCredit_toolButton->sizePolicy().hasHeightForWidth());
        overCredit_toolButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(overCredit_toolButton, 3, 1, 1, 1);

        creditLimit_toolButton = new QToolButton(Menu);
        creditLimit_toolButton->setObjectName(QString::fromUtf8("creditLimit_toolButton"));
        sizePolicy1.setHeightForWidth(creditLimit_toolButton->sizePolicy().hasHeightForWidth());
        creditLimit_toolButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(creditLimit_toolButton, 4, 0, 1, 1);

        transfer_toolButton = new QToolButton(Menu);
        transfer_toolButton->setObjectName(QString::fromUtf8("transfer_toolButton"));
        transfer_toolButton->setEnabled(true);
        sizePolicy1.setHeightForWidth(transfer_toolButton->sizePolicy().hasHeightForWidth());
        transfer_toolButton->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setStyleStrategy(QFont::PreferAntialias);
        transfer_toolButton->setFont(font2);

        gridLayout->addWidget(transfer_toolButton, 1, 1, 1, 1);

        check_Balance_toolButton = new QToolButton(Menu);
        check_Balance_toolButton->setObjectName(QString::fromUtf8("check_Balance_toolButton"));
        sizePolicy1.setHeightForWidth(check_Balance_toolButton->sizePolicy().hasHeightForWidth());
        check_Balance_toolButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(check_Balance_toolButton, 2, 0, 1, 1);

        cashWithdrawal_toolButton = new QToolButton(Menu);
        cashWithdrawal_toolButton->setObjectName(QString::fromUtf8("cashWithdrawal_toolButton"));
        sizePolicy1.setHeightForWidth(cashWithdrawal_toolButton->sizePolicy().hasHeightForWidth());
        cashWithdrawal_toolButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(cashWithdrawal_toolButton, 1, 0, 1, 1);

        exess_toolButton = new QToolButton(Menu);
        exess_toolButton->setObjectName(QString::fromUtf8("exess_toolButton"));
        exess_toolButton->setEnabled(false);
        sizePolicy1.setHeightForWidth(exess_toolButton->sizePolicy().hasHeightForWidth());
        exess_toolButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(exess_toolButton, 4, 1, 1, 1);

        automaticTransfer_toolButton = new QToolButton(Menu);
        automaticTransfer_toolButton->setObjectName(QString::fromUtf8("automaticTransfer_toolButton"));
        sizePolicy1.setHeightForWidth(automaticTransfer_toolButton->sizePolicy().hasHeightForWidth());
        automaticTransfer_toolButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(automaticTransfer_toolButton, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        toolButton = new QToolButton(Menu);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(toolButton);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QDialog *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Dialog", nullptr));
        menu_label->setText(QCoreApplication::translate("Menu", "Main menu", nullptr));
        choose_label->setText(QCoreApplication::translate("Menu", "Choose an option:", nullptr));
        chargeAccount_toolButton->setText(QCoreApplication::translate("Menu", "Charge account", nullptr));
        overCredit_toolButton->setText(QCoreApplication::translate("Menu", "Over-credit protection", nullptr));
        creditLimit_toolButton->setText(QCoreApplication::translate("Menu", "Credit limit", nullptr));
        transfer_toolButton->setText(QCoreApplication::translate("Menu", "Transfer money", nullptr));
        check_Balance_toolButton->setText(QCoreApplication::translate("Menu", "Check ballance", nullptr));
        cashWithdrawal_toolButton->setText(QCoreApplication::translate("Menu", "Cash withdrawal", nullptr));
        exess_toolButton->setText(QCoreApplication::translate("Menu", "Exess", nullptr));
        automaticTransfer_toolButton->setText(QCoreApplication::translate("Menu", "Automatic transfers", nullptr));
        toolButton->setText(QCoreApplication::translate("Menu", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
