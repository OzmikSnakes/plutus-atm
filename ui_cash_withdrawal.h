/********************************************************************************
** Form generated from reading UI file 'cash_withdrawal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASH_WITHDRAWAL_H
#define UI_CASH_WITHDRAWAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CashWithdrawal
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *nominas;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancel_pushButton;
    QPushButton *withdraw_pushButton;

    void setupUi(QDialog *CashWithdrawal)
    {
        if (CashWithdrawal->objectName().isEmpty())
            CashWithdrawal->setObjectName(QString::fromUtf8("CashWithdrawal"));
        CashWithdrawal->resize(400, 300);
        layoutWidget = new QWidget(CashWithdrawal);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 20, 251, 221));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setTextFormat(Qt::MarkdownText);

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        nominas = new QLabel(layoutWidget);
        nominas->setObjectName(QString::fromUtf8("nominas"));

        horizontalLayout_2->addWidget(nominas);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(3000);

        horizontalLayout_3->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancel_pushButton = new QPushButton(layoutWidget);
        cancel_pushButton->setObjectName(QString::fromUtf8("cancel_pushButton"));

        horizontalLayout->addWidget(cancel_pushButton);

        withdraw_pushButton = new QPushButton(layoutWidget);
        withdraw_pushButton->setObjectName(QString::fromUtf8("withdraw_pushButton"));

        horizontalLayout->addWidget(withdraw_pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CashWithdrawal);

        QMetaObject::connectSlotsByName(CashWithdrawal);
    } // setupUi

    void retranslateUi(QDialog *CashWithdrawal)
    {
        CashWithdrawal->setWindowTitle(QCoreApplication::translate("CashWithdrawal", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CashWithdrawal", "Cash Withdrawal", nullptr));
        label_2->setText(QCoreApplication::translate("CashWithdrawal", "Nominals available:", nullptr));
        nominas->setText(QCoreApplication::translate("CashWithdrawal", "...", nullptr));
        label_3->setText(QCoreApplication::translate("CashWithdrawal", "I want to withdraw", nullptr));
        cancel_pushButton->setText(QCoreApplication::translate("CashWithdrawal", "Cancel", nullptr));
        withdraw_pushButton->setText(QCoreApplication::translate("CashWithdrawal", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CashWithdrawal: public Ui_CashWithdrawal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASH_WITHDRAWAL_H
