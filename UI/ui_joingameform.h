/********************************************************************************
** Form generated from reading UI file 'joingameform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINGAMEFORM_H
#define UI_JOINGAMEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JoinGameForm
{
public:
    QPushButton *btnLogin;
    QPushButton *btnExit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *lbPassword;
    QLabel *lbUsername;
    QLineEdit *leUsername;
    QLineEdit *lePassword;

    void setupUi(QWidget *JoinGameForm)
    {
        if (JoinGameForm->objectName().isEmpty())
            JoinGameForm->setObjectName(QString::fromUtf8("JoinGameForm"));
        JoinGameForm->resize(400, 300);
        btnLogin = new QPushButton(JoinGameForm);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(90, 220, 81, 31));
        btnExit = new QPushButton(JoinGameForm);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(240, 220, 91, 31));
        gridLayoutWidget = new QWidget(JoinGameForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(80, 110, 261, 91));
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


        retranslateUi(JoinGameForm);
        QObject::connect(btnExit, SIGNAL(clicked()), JoinGameForm, SLOT(close()));

        QMetaObject::connectSlotsByName(JoinGameForm);
    } // setupUi

    void retranslateUi(QWidget *JoinGameForm)
    {
        JoinGameForm->setWindowTitle(QCoreApplication::translate("JoinGameForm", "Form", nullptr));
        btnLogin->setText(QCoreApplication::translate("JoinGameForm", "Login", nullptr));
        btnExit->setText(QCoreApplication::translate("JoinGameForm", "Exit", nullptr));
        lbPassword->setText(QCoreApplication::translate("JoinGameForm", "password", nullptr));
        lbUsername->setText(QCoreApplication::translate("JoinGameForm", "username", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JoinGameForm: public Ui_JoinGameForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINGAMEFORM_H
