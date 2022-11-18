#include "playerbullet.h"

PlayerBullet::PlayerBullet(QVector4D position, QVector3D color)
    : GameObject(position, color)
{
    this->collideR =0.005f;
    this->collideC = QVector2D(0.005f, 0.005f);
    this->damage = 20;
}

void PlayerBullet::setDamage(int num){
    this->damage = num;
}

int PlayerBullet::getDamage(){
    return this->damage;
}

QVector2D PlayerBullet::getCollideC(){
    return QVector2D(Position().x() + this->collideC.x(), Position().y() + this->collideC.y());
}

float PlayerBullet::getCollideR(){
    return this->collideR;
}

void PlayerBullet::setSpeed(float s){
     GameObject::setSpeed(s);
}
