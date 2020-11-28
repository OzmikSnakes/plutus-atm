/********************************************************************************
** Form generated from reading UI file 'transfer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFER_H
#define UI_TRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Transfer
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *money_doubleSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *transfer_pushButton;

    void setupUi(QDialog *Transfer)
    {
        if (Transfer->objectName().isEmpty())
            Transfer->setObjectName(QString::fromUtf8("Transfer"));
        Transfer->resize(400, 300);
        verticalLayout_3 = new QVBoxLayout(Transfer);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Transfer);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(Transfer);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(Transfer);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(Transfer);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        money_doubleSpinBox = new QDoubleSpinBox(Transfer);
        money_doubleSpinBox->setObjectName(QString::fromUtf8("money_doubleSpinBox"));
        money_doubleSpinBox->setMaximum(9999.000000000000000);
        money_doubleSpinBox->setSingleStep(100.000000000000000);
        money_doubleSpinBox->setValue(100.000000000000000);

        horizontalLayout_2->addWidget(money_doubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton = new QPushButton(Transfer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        transfer_pushButton = new QPushButton(Transfer);
        transfer_pushButton->setObjectName(QString::fromUtf8("transfer_pushButton"));

        horizontalLayout_3->addWidget(transfer_pushButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(Transfer);

        QMetaObject::connectSlotsByName(Transfer);
    } // setupUi

    void retranslateUi(QDialog *Transfer)
    {
        Transfer->setWindowTitle(QCoreApplication::translate("Transfer", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Transfer", "Transfer", nullptr));
        label_2->setText(QCoreApplication::translate("Transfer", "Transfer to account:", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Transfer", "**** **** **** ****", nullptr));
        label_3->setText(QCoreApplication::translate("Transfer", "Money to transfer:", nullptr));
        pushButton->setText(QCoreApplication::translate("Transfer", "Cancel", nullptr));
        transfer_pushButton->setText(QCoreApplication::translate("Transfer", "Transfer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transfer: public Ui_Transfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFER_H
