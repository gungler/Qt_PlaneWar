/********************************************************************************
** Form generated from reading UI file 'adminoperationform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINOPERATIONFORM_H
#define UI_ADMINOPERATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminOperationForm
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnModifyLogin;
    QPushButton *btnModifyTotalRec;
    QPushButton *btnModifyUser;
    QPushButton *btnExit;

    void setupUi(QWidget *AdminOperationForm)
    {
        if (AdminOperationForm->objectName().isEmpty())
            AdminOperationForm->setObjectName(QString::fromUtf8("AdminOperationForm"));
        AdminOperationForm->resize(1200, 900);
        gridLayoutWidget = new QWidget(AdminOperationForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(300, 340, 651, 341));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnModifyLogin = new QPushButton(gridLayoutWidget);
        btnModifyLogin->setObjectName(QString::fromUtf8("btnModifyLogin"));

        gridLayout->addWidget(btnModifyLogin, 1, 0, 1, 1);

        btnModifyTotalRec = new QPushButton(gridLayoutWidget);
        btnModifyTotalRec->setObjectName(QString::fromUtf8("btnModifyTotalRec"));

        gridLayout->addWidget(btnModifyTotalRec, 2, 0, 1, 1);

        btnModifyUser = new QPushButton(gridLayoutWidget);
        btnModifyUser->setObjectName(QString::fromUtf8("btnModifyUser"));

        gridLayout->addWidget(btnModifyUser, 0, 0, 1, 1);

        btnExit = new QPushButton(gridLayoutWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        gridLayout->addWidget(btnExit, 3, 0, 1, 1);


        retranslateUi(AdminOperationForm);
        QObject::connect(btnExit, SIGNAL(clicked()), AdminOperationForm, SLOT(close()));

        QMetaObject::connectSlotsByName(AdminOperationForm);
    } // setupUi

    void retranslateUi(QWidget *AdminOperationForm)
    {
        AdminOperationForm->setWindowTitle(QCoreApplication::translate("AdminOperationForm", "Form", nullptr));
        btnModifyLogin->setText(QCoreApplication::translate("AdminOperationForm", "PlayerLoginManage", nullptr));
        btnModifyTotalRec->setText(QCoreApplication::translate("AdminOperationForm", "TotalRecordManage", nullptr));
        btnModifyUser->setText(QCoreApplication::translate("AdminOperationForm", "PlayerAccountManage", nullptr));
        btnExit->setText(QCoreApplication::translate("AdminOperationForm", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminOperationForm: public Ui_AdminOperationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINOPERATIONFORM_H
