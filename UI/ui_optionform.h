/********************************************************************************
** Form generated from reading UI file 'optionform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONFORM_H
#define UI_OPTIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnGameSetting;
    QPushButton *btnMusicSetting;
    QPushButton *btnExit;

    void setupUi(QWidget *OptionForm)
    {
        if (OptionForm->objectName().isEmpty())
            OptionForm->setObjectName(QString::fromUtf8("OptionForm"));
        OptionForm->resize(1200, 900);
        verticalLayoutWidget = new QWidget(OptionForm);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(420, 460, 491, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnGameSetting = new QPushButton(verticalLayoutWidget);
        btnGameSetting->setObjectName(QString::fromUtf8("btnGameSetting"));

        verticalLayout->addWidget(btnGameSetting);

        btnMusicSetting = new QPushButton(verticalLayoutWidget);
        btnMusicSetting->setObjectName(QString::fromUtf8("btnMusicSetting"));

        verticalLayout->addWidget(btnMusicSetting);

        btnExit = new QPushButton(verticalLayoutWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        verticalLayout->addWidget(btnExit);


        retranslateUi(OptionForm);
        QObject::connect(btnExit, SIGNAL(clicked()), OptionForm, SLOT(close()));

        QMetaObject::connectSlotsByName(OptionForm);
    } // setupUi

    void retranslateUi(QWidget *OptionForm)
    {
        OptionForm->setWindowTitle(QCoreApplication::translate("OptionForm", "Form", nullptr));
        btnGameSetting->setText(QCoreApplication::translate("OptionForm", "Game Setting", nullptr));
        btnMusicSetting->setText(QCoreApplication::translate("OptionForm", "Music Setting", nullptr));
        btnExit->setText(QCoreApplication::translate("OptionForm", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionForm: public Ui_OptionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONFORM_H
