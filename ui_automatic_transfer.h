/********************************************************************************
** Form generated from reading UI file 'automatic_transfer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOMATIC_TRANSFER_H
#define UI_AUTOMATIC_TRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_AutomaticTransfer
{
public:
    QGridLayout *gridLayout;
    QSpinBox *spinBox;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QLabel *label_5;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QDialog *AutomaticTransfer)
    {
        if (AutomaticTransfer->objectName().isEmpty())
            AutomaticTransfer->setObjectName(QString::fromUtf8("AutomaticTransfer"));
        AutomaticTransfer->resize(400, 300);
        gridLayout = new QGridLayout(AutomaticTransfer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spinBox = new QSpinBox(AutomaticTransfer);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(5000);
        spinBox->setSingleStep(100);
        spinBox->setValue(100);

        gridLayout->addWidget(spinBox, 2, 2, 1, 1);

        label_4 = new QLabel(AutomaticTransfer);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_2 = new QLabel(AutomaticTransfer);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setScaledContents(false);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(AutomaticTransfer);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dateEdit = new QDateEdit(AutomaticTransfer);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit);

        timeEdit = new QTimeEdit(AutomaticTransfer);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));

        horizontalLayout->addWidget(timeEdit);


        gridLayout->addLayout(horizontalLayout, 4, 2, 1, 1);

        lineEdit = new QLineEdit(AutomaticTransfer);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 2, 1, 1);

        comboBox = new QComboBox(AutomaticTransfer);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 3, 2, 1, 1);

        label_5 = new QLabel(AutomaticTransfer);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        pushButton = new QPushButton(AutomaticTransfer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 5, 0, 1, 1);

        label = new QLabel(AutomaticTransfer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLineWidth(5);
        label->setTextFormat(Qt::MarkdownText);
        label->setMargin(0);

        gridLayout->addWidget(label, 0, 0, 1, 3);

        pushButton_2 = new QPushButton(AutomaticTransfer);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 5, 2, 1, 1);


        retranslateUi(AutomaticTransfer);

        QMetaObject::connectSlotsByName(AutomaticTransfer);
    } // setupUi

    void retranslateUi(QDialog *AutomaticTransfer)
    {
        AutomaticTransfer->setWindowTitle(QCoreApplication::translate("AutomaticTransfer", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("AutomaticTransfer", "Type:", nullptr));
        label_2->setText(QCoreApplication::translate("AutomaticTransfer", "Card to transfer:", nullptr));
        label_3->setText(QCoreApplication::translate("AutomaticTransfer", "Amount:", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("AutomaticTransfer", "**** **** **** ****", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AutomaticTransfer", "One time", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("AutomaticTransfer", "Daily", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("AutomaticTransfer", "Weekly", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("AutomaticTransfer", "Monthly", nullptr));

        label_5->setText(QCoreApplication::translate("AutomaticTransfer", "First transfer date", nullptr));
        pushButton->setText(QCoreApplication::translate("AutomaticTransfer", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("AutomaticTransfer", "Automatic transfers", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AutomaticTransfer", "Accept", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AutomaticTransfer: public Ui_AutomaticTransfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOMATIC_TRANSFER_H
