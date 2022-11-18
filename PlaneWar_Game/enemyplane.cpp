#include "enemyplane.h"

EnemyPlane::EnemyPlane(QVector4D position, QVector3D color, int type)
        :GameObject(position, color)
{
    this->enemyType = type;
    switch(type){
    case 0:
        this->collideR = 0.07f;
        this->collideC = QVector2D(0.07f, 0.07f);
        this->health = 80;
        this->bonusEnergy = 5;
        break;
    case 1:
        this->collideR = 0.15f;
        this->collideC = QVector2D(0.15f, 0.15f);
        this->health = 100;
        this->armour = 5;
        this->bonusEnergy = 10;
        break;
    case 2:
        this->collideR = 0.27f;
        this->collideC = QVector2D(0.27f, 0.27f);
        this->health = 300;
        this->armour = 10;
        this->bonusEnergy = 50;
        break;
    default:break;
    }
}

void EnemyPlane::setHealth(int health){
    this->health = health;
}

void EnemyPlane::takeDamage(int damage){
    int trueDmg = damage - armour;
    if(trueDmg > 0)
    this->health -= trueDmg;
    if(this->health <0) this->setDestroied();
}

void EnemyPlane::planeMoveDown(){
    this->moveDown();
    if(Position().y() < -1.0f)
       setDestroied();
}

void EnemyPlane::bulletMoveDown(){
        for(EnemyBullet* i=enemybullets.begin(); i < enemybullets.end();){
            i->moveDown();
            if(i->Position().y() < -1.0f){
                enemybullets.erase(i);
            }else{
                 i++;
            }
        }
}

QVector2D EnemyPlane::getCollideC(){
    return QVector2D(this->Position().x() + collideC.x(),
                     this->Position().y() + collideC.y());
}

float EnemyPlane::getCollideR(){
    return this->collideR;
}

void EnemyPlane::setSpeed(float s){
     GameObject::setSpeed(s);
}

void EnemyPlane::setType(int type){
    this->enemyType = type;
}

int EnemyPlane::getType(){
   return this->enemyType;
}

int EnemyPlane::getBonusEnergy(){
    return this->bonusEnergy;
}
