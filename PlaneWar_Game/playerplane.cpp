#include "playerplane.h"

QTimer* PlayerPlane::skillTimer;
QTimer* PlayerPlane::invincibleTimer;
SoundEngine PlayerPlane::sounds;

PlayerPlane::PlayerPlane(QVector4D position, QVector3D color, QString skillName, int skinIndex)
    :GameObject(position, color),
      Skill(skillName)
{
    this->collideR = 0.10f;
    this->collideC = QVector2D(0.12f, 0.10f);
    this->skillTimer = new QTimer();
    this->invincibleTimer = new QTimer();
    this->skillName = skillName;

    if(skillName == "Redbullet"){
        this->health = 100;
        this->armour = 10;
    }else if(skillName == "Heal"){
        this->health = 150;
        this->armour = 0;
    }else if(skillName == "Crush"){
        this->health = 120;
        this->armour = 20;
    }else{
        this->health = 120;
        this->armour = 5;
    }
    this->skinIndex = skinIndex;
}

void PlayerPlane::bulletMoveUp(){
        for(PlayerBullet* i = playerbullets.begin(); i != playerbullets.end();){
            i->moveUp();
            if(i->Position().y() > 1.0f){
                playerbullets.erase(i);
            }else{
                i++;
            }
        }
}

void PlayerPlane::setSkill(int skilltype){
    if(skilltype == 1){
        this->skillName = "Redbullet";
        this->health = 100;
        this->armour = 10;
        this->setMaxEnergy(120);
    }else if(skilltype == 2){
        this->skillName = "Heal";
        this->health = 150;
        this->armour = 0;
        this->setMaxEnergy(80);
    }else if(skilltype == 3){
        this->skillName = "Crush";
        this->health = 120;
        this->armour = 5;
        this->setMaxEnergy(120);
    }else if(skilltype == 0){
        this->skillName = "Bomb";
        this->health = 120;
        this->armour = 5;
        this->setMaxEnergy(150);
    }else{
        qDebug() << "error skill index";
    }
}

void PlayerPlane::takeDamage(int damage){
    int trueDmg = damage - armour;
    if(trueDmg > 0) this->health -= trueDmg;
    if(this->health < 0) GameObject::setDestroied();
}

int PlayerPlane::getScore(){
    return this->score;
}

void PlayerPlane::changeScore(int score){
    this->score += score;
}

QString PlayerPlane::getSkill(){
    return this->skillName;
}

QVector2D PlayerPlane::getCollideC(){
    return QVector2D(Position().x() + this->collideC.x(), Position().y() + this->collideC.x());
}

float PlayerPlane::getCollideR(){
    return this->collideR;
}


void PlayerPlane::skillEnd(){
    this->skillstate = 0;
    this->skillTimer->stop();
}

void PlayerPlane::invincibleEnd(){
    this->invincible = 0;
    this->invincibleTimer->stop();
}

int PlayerPlane::getHealth(){
   return this->health;
}

void PlayerPlane::restoreAllHealth(){
    if(skillName == "Redbullet"){
        this->health = 100;;
    }else if(skillName == "Heal"){
        this->health = 150;
    }else if(skillName == "Crash"){
        this->health = 120;
    }else{
        this->health = 120;
    }
}

float PlayerPlane::getShootSpeed(){
    return this->shootSpeed;
}
