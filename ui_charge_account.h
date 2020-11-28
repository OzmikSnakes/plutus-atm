/********************************************************************************
** Form generated from reading UI file 'charge_account.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGE_ACCOUNT_H
#define UI_CHARGE_ACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChargeAccount
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLabel *label_4;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *moneyPut_label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancel_pushButton;
    QPushButton *withdraw_pushButton;

    void setupUi(QDialog *ChargeAccount)
    {
        if (ChargeAccount->objectName().isEmpty())
            ChargeAccount->setObjectName(QString::fromUtf8("ChargeAccount"));
        ChargeAccount->resize(400, 300);
        horizontalLayout_4 = new QHBoxLayout(ChargeAccount);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ChargeAccount);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setTextFormat(Qt::MarkdownText);

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ChargeAccount);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_5 = new QLabel(ChargeAccount);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        label_4 = new QLabel(ChargeAccount);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_4);

        comboBox = new QComboBox(ChargeAccount);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(1, QFormLayout::LabelRole, comboBox);

        spinBox = new QSpinBox(ChargeAccount);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setValue(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox);


        verticalLayout->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(ChargeAccount);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        moneyPut_label = new QLabel(ChargeAccount);
        moneyPut_label->setObjectName(QString::fromUtf8("moneyPut_label"));

        horizontalLayout_3->addWidget(moneyPut_label);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancel_pushButton = new QPushButton(ChargeAccount);
        cancel_pushButton->setObjectName(QString::fromUtf8("cancel_pushButton"));

        horizontalLayout->addWidget(cancel_pushButton);

        withdraw_pushButton = new QPushButton(ChargeAccount);
        withdraw_pushButton->setObjectName(QString::fromUtf8("withdraw_pushButton"));

        horizontalLayout->addWidget(withdraw_pushButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(ChargeAccount);

        QMetaObject::connectSlotsByName(ChargeAccount);
    } // setupUi

    void retranslateUi(QDialog *ChargeAccount)
    {
        ChargeAccount->setWindowTitle(QCoreApplication::translate("ChargeAccount", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ChargeAccount", "Charge Account", nullptr));
        label_2->setText(QCoreApplication::translate("ChargeAccount", "Put money to the bancomat:", nullptr));
        label_5->setText(QCoreApplication::translate("ChargeAccount", "Nominal", nullptr));
        label_4->setText(QCoreApplication::translate("ChargeAccount", "Amount", nullptr));
        label_3->setText(QCoreApplication::translate("ChargeAccount", "Money to charge:", nullptr));
        moneyPut_label->setText(QCoreApplication::translate("ChargeAccount", "...", nullptr));
        cancel_pushButton->setText(QCoreApplication::translate("ChargeAccount", "Cancel", nullptr));
        withdraw_pushButton->setText(QCoreApplication::translate("ChargeAccount", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChargeAccount: public Ui_ChargeAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGE_ACCOUNT_H
