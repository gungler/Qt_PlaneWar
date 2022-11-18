/********************************************************************************
** Form generated from reading UI file 'adminloginform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGINFORM_H
#define UI_ADMINLOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminLoginForm
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *lbPassword;
    QLabel *lbUsername;
    QLineEdit *leUsername;
    QLineEdit *lePassword;
    QPushButton *btnExit;
    QPushButton *btnLogin;

    void setupUi(QWidget *AdminLoginForm)
    {
        if (AdminLoginForm->objectName().isEmpty())
            AdminLoginForm->setObjectName(QString::fromUtf8("AdminLoginForm"));
        AdminLoginForm->resize(400, 300);
        gridLayoutWidget = new QWidget(AdminLoginForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(80, 100, 261, 91));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lbPassword = new QLabel(gridLayoutWidget);
        lbPassword->setObjectName(QString::fromUtf8("lbPassword"));

        gridLayout->addWidget(lbPassword, 1, 0, 1, 1);

        lbUsername = new QLabel(gridLayoutWidget);
        lbUsername->setObjectName(QString::fromUtf8("lbUsername"));

        gridLayout->addWidget(lbUsername, 0, 0, 1, 1);

        leUsername = new QLineEdit(gridLayoutWidget);
        leUsername->setObjectName(QString::fromUtf8("leUsername"));

        gridLayout->addWidget(leUsername, 0, 1, 1, 1);

        lePassword = new QLineEdit(gridLayoutWidget);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lePassword, 1, 1, 1, 1);

        btnExit = new QPushButton(AdminLoginForm);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(240, 210, 91, 31));
        btnLogin = new QPushButton(AdminLoginForm);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(90, 210, 81, 31));

        retranslateUi(AdminLoginForm);
        QObject::connect(btnExit, SIGNAL(clicked()), AdminLoginForm, SLOT(close()));

        QMetaObject::connectSlotsByName(AdminLoginForm);
    } // setupUi

    void retranslateUi(QWidget *AdminLoginForm)
    {
        AdminLoginForm->setWindowTitle(QCoreApplication::translate("AdminLoginForm", "Form", nullptr));
        lbPassword->setText(QCoreApplication::translate("AdminLoginForm", "password", nullptr));
        lbUsername->setText(QCoreApplication::translate("AdminLoginForm", "username", nullptr));
        btnExit->setText(QCoreApplication::translate("AdminLoginForm", "Exit", nullptr));
        btnLogin->setText(QCoreApplication::translate("AdminLoginForm", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminLoginForm: public Ui_AdminLoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGINFORM_H
