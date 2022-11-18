/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnAdminLogin;
    QPushButton *btnLogin;
    QPushButton *btnRegister;
    QPushButton *btnExit;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(1200, 900);
        verticalLayoutWidget = new QWidget(MainWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(340, 400, 461, 361));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnAdminLogin = new QPushButton(verticalLayoutWidget);
        btnAdminLogin->setObjectName(QString::fromUtf8("btnAdminLogin"));

        verticalLayout->addWidget(btnAdminLogin);

        btnLogin = new QPushButton(verticalLayoutWidget);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));

        verticalLayout->addWidget(btnLogin);

        btnRegister = new QPushButton(verticalLayoutWidget);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));

        verticalLayout->addWidget(btnRegister);

        btnExit = new QPushButton(verticalLayoutWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        verticalLayout->addWidget(btnExit);


        retranslateUi(MainWidget);
        QObject::connect(btnExit, SIGNAL(clicked()), MainWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "MainWidget", nullptr));
        btnAdminLogin->setText(QCoreApplication::translate("MainWidget", "AdminLogin", nullptr));
        btnLogin->setText(QCoreApplication::translate("MainWidget", "UserLogin", nullptr));
        btnRegister->setText(QCoreApplication::translate("MainWidget", "Register", nullptr));
        btnExit->setText(QCoreApplication::translate("MainWidget", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
