/********************************************************************************
** Form generated from reading UI file 'modifyuserform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYUSERFORM_H
#define UI_MODIFYUSERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyUserForm
{
public:
    QPushButton *btnSubmit;
    QPushButton *btnDelete;
    QTableView *tableView;
    QPushButton *btnInsert;
    QPushButton *btnAdd;
    QLabel *label;
    QPushButton *btnCancel;
    QPushButton *btnExit;

    void setupUi(QWidget *ModifyUserForm)
    {
        if (ModifyUserForm->objectName().isEmpty())
            ModifyUserForm->setObjectName(QString::fromUtf8("ModifyUserForm"));
        ModifyUserForm->resize(1200, 900);
        btnSubmit = new QPushButton(ModifyUserForm);
        btnSubmit->setObjectName(QString::fromUtf8("btnSubmit"));
        btnSubmit->setGeometry(QRect(980, 550, 101, 29));
        btnDelete = new QPushButton(ModifyUserForm);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setGeometry(QRect(980, 500, 101, 29));
        tableView = new QTableView(ModifyUserForm);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(245, 341, 691, 311));
        btnInsert = new QPushButton(ModifyUserForm);
        btnInsert->setObjectName(QString::fromUtf8("btnInsert"));
        btnInsert->setGeometry(QRect(980, 400, 101, 29));
        btnAdd = new QPushButton(ModifyUserForm);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(980, 350, 101, 29));
        label = new QLabel(ModifyUserForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 300, 181, 18));
        btnCancel = new QPushButton(ModifyUserForm);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(980, 450, 101, 29));
        btnExit = new QPushButton(ModifyUserForm);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(980, 610, 101, 29));

        retranslateUi(ModifyUserForm);

        QMetaObject::connectSlotsByName(ModifyUserForm);
    } // setupUi

    void retranslateUi(QWidget *ModifyUserForm)
    {
        ModifyUserForm->setWindowTitle(QCoreApplication::translate("ModifyUserForm", "Form", nullptr));
        btnSubmit->setText(QCoreApplication::translate("ModifyUserForm", "Submit", nullptr));
        btnDelete->setText(QCoreApplication::translate("ModifyUserForm", "Delete", nullptr));
        btnInsert->setText(QCoreApplication::translate("ModifyUserForm", "Insert", nullptr));
        btnAdd->setText(QCoreApplication::translate("ModifyUserForm", "Add", nullptr));
        label->setText(QCoreApplication::translate("ModifyUserForm", "User Inforamtions", nullptr));
        btnCancel->setText(QCoreApplication::translate("ModifyUserForm", "Cancel", nullptr));
        btnExit->setText(QCoreApplication::translate("ModifyUserForm", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyUserForm: public Ui_ModifyUserForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYUSERFORM_H
