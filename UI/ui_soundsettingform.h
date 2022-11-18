/********************************************************************************
** Form generated from reading UI file 'soundsettingform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUNDSETTINGFORM_H
#define UI_SOUNDSETTINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SoundSettingForm
{
public:
    QPushButton *btnSaveandQuit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbtnMute;
    QRadioButton *rbtnFullVolumn;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSlider *horizontalSlider;
    QLabel *label;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QWidget *SoundSettingForm)
    {
        if (SoundSettingForm->objectName().isEmpty())
            SoundSettingForm->setObjectName(QString::fromUtf8("SoundSettingForm"));
        SoundSettingForm->resize(1200, 900);
        btnSaveandQuit = new QPushButton(SoundSettingForm);
        btnSaveandQuit->setObjectName(QString::fromUtf8("btnSaveandQuit"));
        btnSaveandQuit->setGeometry(QRect(920, 770, 131, 34));
        horizontalLayoutWidget = new QWidget(SoundSettingForm);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(420, 580, 621, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rbtnMute = new QRadioButton(horizontalLayoutWidget);
        rbtnMute->setObjectName(QString::fromUtf8("rbtnMute"));
        rbtnMute->setAutoExclusive(true);

        horizontalLayout->addWidget(rbtnMute);

        rbtnFullVolumn = new QRadioButton(horizontalLayoutWidget);
        rbtnFullVolumn->setObjectName(QString::fromUtf8("rbtnFullVolumn"));
        rbtnFullVolumn->setAutoExclusive(true);

        horizontalLayout->addWidget(rbtnFullVolumn);

        gridLayoutWidget = new QWidget(SoundSettingForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(420, 470, 621, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(gridLayoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSingleStep(5);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBothSides);
        horizontalSlider->setTickInterval(5);

        gridLayout->addWidget(horizontalSlider, 0, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayoutWidget_2 = new QWidget(SoundSettingForm);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(420, 640, 621, 109));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        textBrowser = new QTextBrowser(horizontalLayoutWidget_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        horizontalLayout_2->addWidget(textBrowser);

        pushButton = new QPushButton(horizontalLayoutWidget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setTabletTracking(false);

        horizontalLayout_2->addWidget(pushButton);


        retranslateUi(SoundSettingForm);

        QMetaObject::connectSlotsByName(SoundSettingForm);
    } // setupUi

    void retranslateUi(QWidget *SoundSettingForm)
    {
        SoundSettingForm->setWindowTitle(QCoreApplication::translate("SoundSettingForm", "Form", nullptr));
        btnSaveandQuit->setText(QCoreApplication::translate("SoundSettingForm", "Save and Quit", nullptr));
        rbtnMute->setText(QCoreApplication::translate("SoundSettingForm", "Mute", nullptr));
        rbtnFullVolumn->setText(QCoreApplication::translate("SoundSettingForm", "FullVolume", nullptr));
        label->setText(QCoreApplication::translate("SoundSettingForm", "Volume", nullptr));
        label_2->setText(QCoreApplication::translate("SoundSettingForm", "Import BGM", nullptr));
        pushButton->setText(QCoreApplication::translate("SoundSettingForm", "Choose File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SoundSettingForm: public Ui_SoundSettingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUNDSETTINGFORM_H
