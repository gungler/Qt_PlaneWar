/********************************************************************************
** Form generated from reading UI file 'modifytotalrecform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYTOTALRECFORM_H
#define UI_MODIFYTOTALRECFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyTotalRecForm
{
public:
    QPushButton *btnSubmit;
    QPushButton *btnDelete;
    QPushButton *btnAdd;
    QPushButton *btnExit;
    QTableView *tableView;
    QPushButton *btnInsert;
    QPushButton *btnCancel;
    QLabel *label;

    void setupUi(QWidget *ModifyTotalRecForm)
    {
        if (ModifyTotalRecForm->objectName().isEmpty())
            ModifyTotalRecForm->setObjectName(QString::fromUtf8("ModifyTotalRecForm"));
        ModifyTotalRecForm->resize(1200, 900);
        btnSubmit = new QPushButton(ModifyTotalRecForm);
        btnSubmit->setObjectName(QString::fromUtf8("btnSubmit"));
        btnSubmit->setGeometry(QRect(940, 680, 101, 29));
        btnDelete = new QPushButton(ModifyTotalRecForm);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setGeometry(QRect(940, 630, 101, 29));
        btnAdd = new QPushButton(ModifyTotalRecForm);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(940, 480, 101, 29));
        btnExit = new QPushButton(ModifyTotalRecForm);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(940, 740, 101, 29));
        tableView = new QTableView(ModifyTotalRecForm);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(205, 471, 691, 311));
        btnInsert = new QPushButton(ModifyTotalRecForm);
        btnInsert->setObjectName(QString::fromUtf8("btnInsert"));
        btnInsert->setGeometry(QRect(940, 530, 101, 29));
        btnCancel = new QPushButton(ModifyTotalRecForm);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(940, 580, 101, 29));
        label = new QLabel(ModifyTotalRecForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 430, 231, 18));

        retranslateUi(ModifyTotalRecForm);

        QMetaObject::connectSlotsByName(ModifyTotalRecForm);
    } // setupUi

    void retranslateUi(QWidget *ModifyTotalRecForm)
    {
        ModifyTotalRecForm->setWindowTitle(QCoreApplication::translate("ModifyTotalRecForm", "Form", nullptr));
        btnSubmit->setText(QCoreApplication::translate("ModifyTotalRecForm", "Submit", nullptr));
        btnDelete->setText(QCoreApplication::translate("ModifyTotalRecForm", "Delete", nullptr));
        btnAdd->setText(QCoreApplication::translate("ModifyTotalRecForm", "Add", nullptr));
        btnExit->setText(QCoreApplication::translate("ModifyTotalRecForm", "Exit", nullptr));
        btnInsert->setText(QCoreApplication::translate("ModifyTotalRecForm", "Insert", nullptr));
        btnCancel->setText(QCoreApplication::translate("ModifyTotalRecForm", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("ModifyTotalRecForm", "User Total Play Record", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyTotalRecForm: public Ui_ModifyTotalRecForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYTOTALRECFORM_H
