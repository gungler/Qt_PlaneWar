#include "skill.h"

Skill::Skill(QString skill)
{
    if(skill == "RedBullet"){
    this->skill = Redbullet;
    this->maxEnergy = 120;
    }
    else if(skill == "Heal"){
        this->skill = Heal;
        this->maxEnergy = 80;
    }
    else if(skill == "Crush"){
        this->skill = Crash;
        this->maxEnergy = 120;
    }

    else{
        this->skill = Bomb;
        this->maxEnergy = 150;
    }
}

void Skill::setMaxEnergy(int amount){
    this->maxEnergy = amount;
}

bool Skill::canUseSkill(){
    //reset energy
    if(this->energy == this->maxEnergy){
        this->energy = 0;
        return true;
    }
    else
    return false;
}

void Skill::addEnergy(int amount){
    //enegrgy is not full
    if(this->energy < this->maxEnergy){
    this->energy += amount;
    }
    else{
         this->energy = this->maxEnergy;
    }
}

int Skill::getEnergy(){
    return this->energy;
}
