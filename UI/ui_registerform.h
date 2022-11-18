/********************************************************************************
** Form generated from reading UI file 'registerform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERFORM_H
#define UI_REGISTERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterForm
{
public:
    QPushButton *btnSubmit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lePassword;
    QLabel *lbPhone;
    QLabel *lbEmail;
    QLabel *lbUsername;
    QLabel *lbPassword;
    QLineEdit *leUsername;
    QLineEdit *leEmail;
    QLineEdit *lePhone;
    QPushButton *btnExit;

    void setupUi(QWidget *RegisterForm)
    {
        if (RegisterForm->objectName().isEmpty())
            RegisterForm->setObjectName(QString::fromUtf8("RegisterForm"));
        RegisterForm->resize(1200, 900);
        btnSubmit = new QPushButton(RegisterForm);
        btnSubmit->setObjectName(QString::fromUtf8("btnSubmit"));
        btnSubmit->setGeometry(QRect(830, 500, 112, 34));
        gridLayoutWidget = new QWidget(RegisterForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(250, 330, 521, 271));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lePassword = new QLineEdit(gridLayoutWidget);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lePassword, 1, 1, 1, 1);

        lbPhone = new QLabel(gridLayoutWidget);
        lbPhone->setObjectName(QString::fromUtf8("lbPhone"));

        gridLayout->addWidget(lbPhone, 3, 0, 1, 1);

        lbEmail = new QLabel(gridLayoutWidget);
        lbEmail->setObjectName(QString::fromUtf8("lbEmail"));

        gridLayout->addWidget(lbEmail, 2, 0, 1, 1);

        lbUsername = new QLabel(gridLayoutWidget);
        lbUsername->setObjectName(QString::fromUtf8("lbUsername"));

        gridLayout->addWidget(lbUsername, 0, 0, 1, 1);

        lbPassword = new QLabel(gridLayoutWidget);
        lbPassword->setObjectName(QString::fromUtf8("lbPassword"));

        gridLayout->addWidget(lbPassword, 1, 0, 1, 1);

        leUsername = new QLineEdit(gridLayoutWidget);
        leUsername->setObjectName(QString::fromUtf8("leUsername"));

        gridLayout->addWidget(leUsername, 0, 1, 1, 1);

        leEmail = new QLineEdit(gridLayoutWidget);
        leEmail->setObjectName(QString::fromUtf8("leEmail"));

        gridLayout->addWidget(leEmail, 2, 1, 1, 1);

        lePhone = new QLineEdit(gridLayoutWidget);
        lePhone->setObjectName(QString::fromUtf8("lePhone"));

        gridLayout->addWidget(lePhone, 3, 1, 1, 1);

        btnExit = new QPushButton(RegisterForm);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(830, 570, 112, 34));

        retranslateUi(RegisterForm);
        QObject::connect(btnExit, SIGNAL(clicked()), RegisterForm, SLOT(close()));

        QMetaObject::connectSlotsByName(RegisterForm);
    } // setupUi

    void retranslateUi(QWidget *RegisterForm)
    {
        RegisterForm->setWindowTitle(QCoreApplication::translate("RegisterForm", "Form", nullptr));
        btnSubmit->setText(QCoreApplication::translate("RegisterForm", "Submit", nullptr));
        lbPhone->setText(QCoreApplication::translate("RegisterForm", "phone", nullptr));
        lbEmail->setText(QCoreApplication::translate("RegisterForm", "email", nullptr));
        lbUsername->setText(QCoreApplication::translate("RegisterForm", "username", nullptr));
        lbPassword->setText(QCoreApplication::translate("RegisterForm", "password", nullptr));
        btnExit->setText(QCoreApplication::translate("RegisterForm", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterForm: public Ui_RegisterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERFORM_H
