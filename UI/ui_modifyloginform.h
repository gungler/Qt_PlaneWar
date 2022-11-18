/********************************************************************************
** Form generated from reading UI file 'modifyloginform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYLOGINFORM_H
#define UI_MODIFYLOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyLoginForm
{
public:
    QPushButton *btnDelete;
    QPushButton *btnInsert;
    QTableView *tableView;
    QPushButton *btnCancel;
    QLabel *label;
    QPushButton *btnAdd;
    QPushButton *btnSubmit;
    QPushButton *btnExit;

    void setupUi(QWidget *ModifyLoginForm)
    {
        if (ModifyLoginForm->objectName().isEmpty())
            ModifyLoginForm->setObjectName(QString::fromUtf8("ModifyLoginForm"));
        ModifyLoginForm->resize(1200, 900);
        btnDelete = new QPushButton(ModifyLoginForm);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setGeometry(QRect(990, 500, 101, 29));
        btnInsert = new QPushButton(ModifyLoginForm);
        btnInsert->setObjectName(QString::fromUtf8("btnInsert"));
        btnInsert->setGeometry(QRect(990, 400, 101, 29));
        tableView = new QTableView(ModifyLoginForm);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(255, 341, 691, 311));
        btnCancel = new QPushButton(ModifyLoginForm);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(990, 450, 101, 29));
        label = new QLabel(ModifyLoginForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 300, 181, 18));
        btnAdd = new QPushButton(ModifyLoginForm);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(990, 350, 101, 29));
        btnSubmit = new QPushButton(ModifyLoginForm);
        btnSubmit->setObjectName(QString::fromUtf8("btnSubmit"));
        btnSubmit->setGeometry(QRect(990, 550, 101, 29));
        btnExit = new QPushButton(ModifyLoginForm);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(990, 610, 101, 29));

        retranslateUi(ModifyLoginForm);
        QObject::connect(btnExit, SIGNAL(clicked()), ModifyLoginForm, SLOT(close()));

        QMetaObject::connectSlotsByName(ModifyLoginForm);
    } // setupUi

    void retranslateUi(QWidget *ModifyLoginForm)
    {
        ModifyLoginForm->setWindowTitle(QCoreApplication::translate("ModifyLoginForm", "Form", nullptr));
        btnDelete->setText(QCoreApplication::translate("ModifyLoginForm", "Delete", nullptr));
        btnInsert->setText(QCoreApplication::translate("ModifyLoginForm", "Insert", nullptr));
        btnCancel->setText(QCoreApplication::translate("ModifyLoginForm", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("ModifyLoginForm", "User Login State", nullptr));
        btnAdd->setText(QCoreApplication::translate("ModifyLoginForm", "Add", nullptr));
        btnSubmit->setText(QCoreApplication::translate("ModifyLoginForm", "Submit", nullptr));
        btnExit->setText(QCoreApplication::translate("ModifyLoginForm", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyLoginForm: public Ui_ModifyLoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYLOGINFORM_H
