/********************************************************************************
** Form generated from reading UI file 'credit_limit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_LIMIT_H
#define UI_CREDIT_LIMIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CreditLimit
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBox;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *CreditLimit)
    {
        if (CreditLimit->objectName().isEmpty())
            CreditLimit->setObjectName(QString::fromUtf8("CreditLimit"));
        CreditLimit->resize(400, 300);
        formLayout = new QFormLayout(CreditLimit);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(CreditLimit);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(32);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        horizontalSpacer = new QSpacerItem(286, 92, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(2, QFormLayout::LabelRole, horizontalSpacer);

        spinBox = new QSpinBox(CreditLimit);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(6000);
        spinBox->setSingleStep(100);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox);

        label_2 = new QLabel(CreditLimit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        pushButton = new QPushButton(CreditLimit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(7, QFormLayout::LabelRole, pushButton);

        pushButton_2 = new QPushButton(CreditLimit);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        formLayout->setWidget(7, QFormLayout::FieldRole, pushButton_2);


        retranslateUi(CreditLimit);

        QMetaObject::connectSlotsByName(CreditLimit);
    } // setupUi

    void retranslateUi(QDialog *CreditLimit)
    {
        CreditLimit->setWindowTitle(QCoreApplication::translate("CreditLimit", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CreditLimit", "Credit Limit", nullptr));
        label_2->setText(QCoreApplication::translate("CreditLimit", "Set credit limit to:", nullptr));
        pushButton->setText(QCoreApplication::translate("CreditLimit", "Cancel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CreditLimit", "Accept", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreditLimit: public Ui_CreditLimit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_LIMIT_H
