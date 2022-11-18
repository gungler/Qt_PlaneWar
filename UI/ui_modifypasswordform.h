/********************************************************************************
** Form generated from reading UI file 'modifypasswordform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYPASSWORDFORM_H
#define UI_MODIFYPASSWORDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyPasswordForm
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *lbUsername;
    QLabel *lbPassword;
    QLabel *lbNewPassword;
    QLabel *lbConfirm;
    QLineEdit *leUsername;
    QLineEdit *lePassword;
    QLineEdit *leNewPassword;
    QLineEdit *leConfirm;
    QPushButton *btnSubmit;
    QPushButton *btnExit;

    void setupUi(QWidget *ModifyPasswordForm)
    {
        if (ModifyPasswordForm->objectName().isEmpty())
            ModifyPasswordForm->setObjectName(QString::fromUtf8("ModifyPasswordForm"));
        ModifyPasswordForm->resize(400, 300);
        gridLayoutWidget = new QWidget(ModifyPasswordForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 50, 311, 151));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lbUsername = new QLabel(gridLayoutWidget);
        lbUsername->setObjectName(QString::fromUtf8("lbUsername"));
        lbUsername->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbUsername, 0, 0, 1, 1);

        lbPassword = new QLabel(gridLayoutWidget);
        lbPassword->setObjectName(QString::fromUtf8("lbPassword"));
        lbPassword->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbPassword, 1, 0, 1, 1);

        lbNewPassword = new QLabel(gridLayoutWidget);
        lbNewPassword->setObjectName(QString::fromUtf8("lbNewPassword"));

        gridLayout->addWidget(lbNewPassword, 2, 0, 1, 1);

        lbConfirm = new QLabel(gridLayoutWidget);
        lbConfirm->setObjectName(QString::fromUtf8("lbConfirm"));
        lbConfirm->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbConfirm, 3, 0, 1, 1);

        leUsername = new QLineEdit(gridLayoutWidget);
        leUsername->setObjectName(QString::fromUtf8("leUsername"));

        gridLayout->addWidget(leUsername, 0, 1, 1, 1);

        lePassword = new QLineEdit(gridLayoutWidget);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lePassword, 1, 1, 1, 1);

        leNewPassword = new QLineEdit(gridLayoutWidget);
        leNewPassword->setObjectName(QString::fromUtf8("leNewPassword"));
        leNewPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(leNewPassword, 2, 1, 1, 1);

        leConfirm = new QLineEdit(gridLayoutWidget);
        leConfirm->setObjectName(QString::fromUtf8("leConfirm"));
        leConfirm->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(leConfirm, 3, 1, 1, 1);

        btnSubmit = new QPushButton(ModifyPasswordForm);
        btnSubmit->setObjectName(QString::fromUtf8("btnSubmit"));
        btnSubmit->setGeometry(QRect(70, 240, 112, 34));
        btnExit = new QPushButton(ModifyPasswordForm);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(230, 240, 112, 34));

        retranslateUi(ModifyPasswordForm);
        QObject::connect(btnExit, SIGNAL(clicked()), ModifyPasswordForm, SLOT(close()));

        QMetaObject::connectSlotsByName(ModifyPasswordForm);
    } // setupUi

    void retranslateUi(QWidget *ModifyPasswordForm)
    {
        ModifyPasswordForm->setWindowTitle(QCoreApplication::translate("ModifyPasswordForm", "Form", nullptr));
        lbUsername->setText(QCoreApplication::translate("ModifyPasswordForm", "username", nullptr));
        lbPassword->setText(QCoreApplication::translate("ModifyPasswordForm", "password", nullptr));
        lbNewPassword->setText(QCoreApplication::translate("ModifyPasswordForm", "new password", nullptr));
        lbConfirm->setText(QCoreApplication::translate("ModifyPasswordForm", "confirm", nullptr));
        btnSubmit->setText(QCoreApplication::translate("ModifyPasswordForm", "Submit", nullptr));
        btnExit->setText(QCoreApplication::translate("ModifyPasswordForm", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyPasswordForm: public Ui_ModifyPasswordForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYPASSWORDFORM_H
