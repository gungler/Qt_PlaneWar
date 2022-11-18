#include "gameobject.h"
#include <QDebug>
GameObject::GameObject(QVector4D position, QVector3D color)
{
    this->position = position;
    this->color = color;
}

QVector2D GameObject::Position(){
    return QVector2D(position.x(), position.y());
}

QVector3D GameObject::Color(){
    return color;
}

float GameObject::Speed(){
    return speed;
}

void GameObject::setDestroied(){
    this->destroied = 1;
}

bool GameObject::isDestroied(){
    return destroied;
}

void GameObject::moveUp(){
    if(position.z() < 1.0f){
        position.setY(position.y() + speed);
    }
}

void GameObject::moveDown(){
    if(position.y() > -1.0f)
    position.setY(position.y() - speed);

}

void GameObject::moveLeft(){
    if(position.x() > -1.0f)
    position.setX(position.x() - speed);
}

void GameObject::moveRight(){
    if(position.x() < 0.8f)
    position.setX(position.x() + speed);
}

void GameObject::setSpeed(float s){
    speed = s;
}

float GameObject::getSpeed(){
    return speed;
}
