#include "enemybullet.h"

EnemyBullet::EnemyBullet(QVector4D position, QVector3D color)
    :GameObject(position, color)
{
    this->collideR = 0.005f;
    this->collideC = QVector2D(0.005f,0.005f);
}

void EnemyBullet::setDamage(int num){
    this->damage = num;
}

int EnemyBullet::getDamage(){
    return this->damage;
}

QVector2D EnemyBullet::getCollideC(){
    return QVector2D(Position().x() + collideC.x(),
                     Position().y() + collideC.y());
}

float EnemyBullet::getCollideR(){
    return this->collideR;
}

void EnemyBullet::setSpeed(float s){
     GameObject::setSpeed(s);
}
