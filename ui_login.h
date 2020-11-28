/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *welcome_label;
    QLabel *label_2;
    QLineEdit *card_lineField;
    QPushButton *login_pushButton;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *password_lineEdit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancel_pushButton;
    QPushButton *login2_pushButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(400, 300);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(Login);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout = new QHBoxLayout(page);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        welcome_label = new QLabel(page);
        welcome_label->setObjectName(QString::fromUtf8("welcome_label"));
        QFont font;
        font.setPointSize(31);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setKerning(true);
        welcome_label->setFont(font);
        welcome_label->setScaledContents(true);
        welcome_label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(welcome_label);

        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(12);
        font1.setItalic(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        card_lineField = new QLineEdit(page);
        card_lineField->setObjectName(QString::fromUtf8("card_lineField"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(card_lineField->sizePolicy().hasHeightForWidth());
        card_lineField->setSizePolicy(sizePolicy);
        card_lineField->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(card_lineField);

        login_pushButton = new QPushButton(page);
        login_pushButton->setObjectName(QString::fromUtf8("login_pushButton"));

        verticalLayout_2->addWidget(login_pushButton);


        horizontalLayout->addLayout(verticalLayout_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        password_lineEdit = new QLineEdit(page_2);
        password_lineEdit->setObjectName(QString::fromUtf8("password_lineEdit"));
        sizePolicy.setHeightForWidth(password_lineEdit->sizePolicy().hasHeightForWidth());
        password_lineEdit->setSizePolicy(sizePolicy);
        password_lineEdit->setMaxLength(4);
        password_lineEdit->setEchoMode(QLineEdit::Password);
        password_lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(password_lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cancel_pushButton = new QPushButton(page_2);
        cancel_pushButton->setObjectName(QString::fromUtf8("cancel_pushButton"));

        horizontalLayout_2->addWidget(cancel_pushButton);

        login2_pushButton = new QPushButton(page_2);
        login2_pushButton->setObjectName(QString::fromUtf8("login2_pushButton"));
        login2_pushButton->setAutoFillBackground(true);

        horizontalLayout_2->addWidget(login2_pushButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(Login);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        welcome_label->setText(QCoreApplication::translate("Login", "Welcome!", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Please enter card number:", nullptr));
        card_lineField->setText(QCoreApplication::translate("Login", "4532280486346619", nullptr));
        card_lineField->setPlaceholderText(QCoreApplication::translate("Login", "**** **** **** ****", nullptr));
        login_pushButton->setText(QCoreApplication::translate("Login", "Press", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "Please enter pin:", nullptr));
        password_lineEdit->setText(QCoreApplication::translate("Login", "1234", nullptr));
        password_lineEdit->setPlaceholderText(QCoreApplication::translate("Login", "* * * * ", nullptr));
        cancel_pushButton->setText(QCoreApplication::translate("Login", "Cancel", nullptr));
        login2_pushButton->setText(QCoreApplication::translate("Login", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
