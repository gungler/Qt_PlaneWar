/********************************************************************************
** Form generated from reading UI file 'exitform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXITFORM_H
#define UI_EXITFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExitForm
{
public:
    QPushButton *btnSubmit;
    QPushButton *btnExit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *lbPassword;
    QLabel *lbUsername;
    QLineEdit *leUsername;
    QLineEdit *lePassword;

    void setupUi(QWidget *ExitForm)
    {
        if (ExitForm->objectName().isEmpty())
            ExitForm->setObjectName(QString::fromUtf8("ExitForm"));
        ExitForm->resize(400, 300);
        btnSubmit = new QPushButton(ExitForm);
        btnSubmit->setObjectName(QString::fromUtf8("btnSubmit"));
        btnSubmit->setGeometry(QRect(140, 240, 71, 31));
        btnExit = new QPushButton(ExitForm);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(240, 240, 81, 31));
        gridLayoutWidget = new QWidget(ExitForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(100, 140, 241, 80));
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


        retranslateUi(ExitForm);
        QObject::connect(btnExit, SIGNAL(clicked()), ExitForm, SLOT(close()));

        QMetaObject::connectSlotsByName(ExitForm);
    } // setupUi

    void retranslateUi(QWidget *ExitForm)
    {
        ExitForm->setWindowTitle(QCoreApplication::translate("ExitForm", "Form", nullptr));
        btnSubmit->setText(QCoreApplication::translate("ExitForm", "OK", nullptr));
        btnExit->setText(QCoreApplication::translate("ExitForm", "Exit", nullptr));
        lbPassword->setText(QCoreApplication::translate("ExitForm", "Password", nullptr));
        lbUsername->setText(QCoreApplication::translate("ExitForm", "Username", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExitForm: public Ui_ExitForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXITFORM_H
