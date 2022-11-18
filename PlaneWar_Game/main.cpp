#include "planewar.h"

#include <QApplication>
#include <iostream>
#include <QString>
#include <QVector>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
    QApplication a(argc, argv);
    PlaneWar w;

    //playernums, namelist, difficulty, skinList, skillList, volumn and bgmpath
    int playernums = QString::fromLocal8Bit(argv[1]).toInt() - 10;
    for(int i = 2; i < playernums + 2; ++i)
        w.playernames.push_back(QString::fromLocal8Bit(argv[i]));

    w.setDifficulty(QString::fromLocal8Bit(argv[playernums + 2]).toInt());
    for(int j = 0; j < playernums; ++j){
        w.setSkin(j, QString::fromLocal8Bit(argv[playernums + 3 + j]).toInt());
    }

    for(int i=0; i < playernums; ++i){
        w.setSkill(i, QString::fromLocal8Bit(argv[2 * playernums + 3 + i]).toInt());
    }

    w.setBGM(QString::fromLocal8Bit(argv[3 * playernums + 4]), QString::fromLocal8Bit(argv[3 * playernums + 3]).toInt());
    w.setAttribute(Qt::WA_TranslucentBackground, true);
    w.show();
    return a.exec();
}
