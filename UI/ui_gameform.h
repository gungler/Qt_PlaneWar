/********************************************************************************
** Form generated from reading UI file 'gameform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEFORM_H
#define UI_GAMEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnGameStart;
    QPushButton *btnJoinGame;
    QPushButton *btnPlayInstruction;
    QPushButton *btnPlayerSet;
    QPushButton *btnOption;
    QPushButton *btnExitGame;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QLabel *lbPlayerList;

    void setupUi(QWidget *GameForm)
    {
        if (GameForm->objectName().isEmpty())
            GameForm->setObjectName(QString::fromUtf8("GameForm"));
        GameForm->resize(1200, 900);
        verticalLayoutWidget = new QWidget(GameForm);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(289, 429, 441, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnGameStart = new QPushButton(verticalLayoutWidget);
        btnGameStart->setObjectName(QString::fromUtf8("btnGameStart"));

        verticalLayout->addWidget(btnGameStart);

        btnJoinGame = new QPushButton(verticalLayoutWidget);
        btnJoinGame->setObjectName(QString::fromUtf8("btnJoinGame"));

        verticalLayout->addWidget(btnJoinGame);

        btnPlayInstruction = new QPushButton(verticalLayoutWidget);
        btnPlayInstruction->setObjectName(QString::fromUtf8("btnPlayInstruction"));

        verticalLayout->addWidget(btnPlayInstruction);

        btnPlayerSet = new QPushButton(verticalLayoutWidget);
        btnPlayerSet->setObjectName(QString::fromUtf8("btnPlayerSet"));

        verticalLayout->addWidget(btnPlayerSet);

        btnOption = new QPushButton(verticalLayoutWidget);
        btnOption->setObjectName(QString::fromUtf8("btnOption"));

        verticalLayout->addWidget(btnOption);

        btnExitGame = new QPushButton(verticalLayoutWidget);
        btnExitGame->setObjectName(QString::fromUtf8("btnExitGame"));

        verticalLayout->addWidget(btnExitGame);

        gridLayoutWidget = new QWidget(GameForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(860, 460, 160, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(gridLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);

        lbPlayerList = new QLabel(GameForm);
        lbPlayerList->setObjectName(QString::fromUtf8("lbPlayerList"));
        lbPlayerList->setGeometry(QRect(860, 420, 161, 31));
        lbPlayerList->setAlignment(Qt::AlignCenter);

        retranslateUi(GameForm);
        QObject::connect(btnExitGame, SIGNAL(clicked()), GameForm, SLOT(close()));

        QMetaObject::connectSlotsByName(GameForm);
    } // setupUi

    void retranslateUi(QWidget *GameForm)
    {
        GameForm->setWindowTitle(QCoreApplication::translate("GameForm", "Form", nullptr));
        btnGameStart->setText(QCoreApplication::translate("GameForm", "Start Game", nullptr));
        btnJoinGame->setText(QCoreApplication::translate("GameForm", "Join game", nullptr));
        btnPlayInstruction->setText(QCoreApplication::translate("GameForm", "Play Instruction", nullptr));
        btnPlayerSet->setText(QCoreApplication::translate("GameForm", "PlayerOptions", nullptr));
        btnOption->setText(QCoreApplication::translate("GameForm", "Options", nullptr));
        btnExitGame->setText(QCoreApplication::translate("GameForm", "Exit", nullptr));
        lbPlayerList->setText(QCoreApplication::translate("GameForm", "Oline Player", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameForm: public Ui_GameForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEFORM_H
