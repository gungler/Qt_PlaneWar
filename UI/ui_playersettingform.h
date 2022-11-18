/********************************************************************************
** Form generated from reading UI file 'playersettingform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERSETTINGFORM_H
#define UI_PLAYERSETTINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerSettingForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnPlayerExit;
    QPushButton *btnModifyPass;
    QPushButton *btnDelete;
    QPushButton *btnExit;

    void setupUi(QWidget *PlayerSettingForm)
    {
        if (PlayerSettingForm->objectName().isEmpty())
            PlayerSettingForm->setObjectName(QString::fromUtf8("PlayerSettingForm"));
        PlayerSettingForm->resize(1200, 900);
        verticalLayoutWidget = new QWidget(PlayerSettingForm);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(300, 420, 541, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnPlayerExit = new QPushButton(verticalLayoutWidget);
        btnPlayerExit->setObjectName(QString::fromUtf8("btnPlayerExit"));

        verticalLayout->addWidget(btnPlayerExit);

        btnModifyPass = new QPushButton(verticalLayoutWidget);
        btnModifyPass->setObjectName(QString::fromUtf8("btnModifyPass"));

        verticalLayout->addWidget(btnModifyPass);

        btnDelete = new QPushButton(verticalLayoutWidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

        verticalLayout->addWidget(btnDelete);

        btnExit = new QPushButton(verticalLayoutWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        verticalLayout->addWidget(btnExit);


        retranslateUi(PlayerSettingForm);
        QObject::connect(btnExit, SIGNAL(clicked()), PlayerSettingForm, SLOT(close()));

        QMetaObject::connectSlotsByName(PlayerSettingForm);
    } // setupUi

    void retranslateUi(QWidget *PlayerSettingForm)
    {
        PlayerSettingForm->setWindowTitle(QCoreApplication::translate("PlayerSettingForm", "Form", nullptr));
        btnPlayerExit->setText(QCoreApplication::translate("PlayerSettingForm", "Player Exit", nullptr));
        btnModifyPass->setText(QCoreApplication::translate("PlayerSettingForm", "ChangePassword", nullptr));
        btnDelete->setText(QCoreApplication::translate("PlayerSettingForm", "Logout", nullptr));
        btnExit->setText(QCoreApplication::translate("PlayerSettingForm", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerSettingForm: public Ui_PlayerSettingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERSETTINGFORM_H
