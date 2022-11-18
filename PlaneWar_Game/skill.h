#ifndef SKILL_H
#define SKILL_H

#include <QObject>
#include <QString>
#include <QDebug>

enum SkillType{
    Bomb,
    Redbullet,
    Heal,
    Crash
};

class Skill
{
public:
    explicit Skill(QString skill="Bomb");

    bool canUseSkill();
    void addEnergy(int amount);
    bool EnergyFull();
    int getEnergy();
    void setMaxEnergy(int value);

private:
    int maxEnergy = 0;
    int energy = 0;
    SkillType skill = Bomb;
};

#endif // SKILL_H
