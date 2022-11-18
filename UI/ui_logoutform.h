/********************************************************************************
** Form generated from reading UI file 'logoutform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGOUTFORM_H
#define UI_LOGOUTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogoutForm
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *leUsername;
    QLabel *lbUsername;
    QLineEdit *lePassword;
    QLabel *lbOldPassword;
    QPushButton *btnSubmit;
    QPushButton *btnExit;

    void setupUi(QWidget *LogoutForm)
    {
        if (LogoutForm->objectName().isEmpty())
            LogoutForm->setObjectName(QString::fromUtf8("LogoutForm"));
        LogoutForm->resize(400, 300);
        gridLayoutWidget = new QWidget(LogoutForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(80, 100, 281, 111));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        leUsername = new QLineEdit(gridLayoutWidget);
        leUsername->setObjectName(QString::fromUtf8("leUsername"));

        gridLayout->addWidget(leUsername, 0, 1, 1, 1);

        lbUsername = new QLabel(gridLayoutWidget);
        lbUsername->setObjectName(QString::fromUtf8("lbUsername"));

        gridLayout->addWidget(lbUsername, 0, 0, 1, 1);

        lePassword = new QLineEdit(gridLayoutWidget);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lePassword, 1, 1, 1, 1);

        lbOldPassword = new QLabel(gridLayoutWidget);
        lbOldPassword->setObjectName(QString::fromUtf8("lbOldPassword"));

        gridLayout->addWidget(lbOldPassword, 1, 0, 1, 1);

        btnSubmit = new QPushButton(LogoutForm);
        btnSubmit->setObjectName(QString::fromUtf8("btnSubmit"));
        btnSubmit->setGeometry(QRect(80, 230, 112, 34));
        btnExit = new QPushButton(LogoutForm);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(230, 230, 112, 34));

        retranslateUi(LogoutForm);
        QObject::connect(btnExit, SIGNAL(clicked()), LogoutForm, SLOT(close()));

        QMetaObject::connectSlotsByName(LogoutForm);
    } // setupUi

    void retranslateUi(QWidget *LogoutForm)
    {
        LogoutForm->setWindowTitle(QCoreApplication::translate("LogoutForm", "Form", nullptr));
        lbUsername->setText(QCoreApplication::translate("LogoutForm", "username", nullptr));
        lbOldPassword->setText(QCoreApplication::translate("LogoutForm", "password", nullptr));
        btnSubmit->setText(QCoreApplication::translate("LogoutForm", "OK", nullptr));
        btnExit->setText(QCoreApplication::translate("LogoutForm", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogoutForm: public Ui_LogoutForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGOUTFORM_H
