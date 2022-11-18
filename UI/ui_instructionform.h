/********************************************************************************
** Form generated from reading UI file 'instructionform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTIONFORM_H
#define UI_INSTRUCTIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InstructionForm
{
public:
    QTextBrowser *textBrowser;
    QPushButton *btnOk;

    void setupUi(QWidget *InstructionForm)
    {
        if (InstructionForm->objectName().isEmpty())
            InstructionForm->setObjectName(QString::fromUtf8("InstructionForm"));
        InstructionForm->resize(1200, 900);
        textBrowser = new QTextBrowser(InstructionForm);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(90, 0, 900, 900));
        btnOk = new QPushButton(InstructionForm);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setGeometry(QRect(1040, 700, 112, 34));

        retranslateUi(InstructionForm);

        QMetaObject::connectSlotsByName(InstructionForm);
    } // setupUi

    void retranslateUi(QWidget *InstructionForm)
    {
        InstructionForm->setWindowTitle(QCoreApplication::translate("InstructionForm", "Form", nullptr));
        btnOk->setText(QCoreApplication::translate("InstructionForm", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InstructionForm: public Ui_InstructionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTIONFORM_H
