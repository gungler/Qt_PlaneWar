#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include <QObject>
#include<QtGlobal>
#include<QVector4D>
#include<QVector3D>
#include<QString>

#include "gameobject.h"

class PlayerBullet : public GameObject
{
public:
    explicit PlayerBullet(QVector4D position = {},
                          QVector3D color = {});

    using GameObject::isDestroied;
    using GameObject::Position;
    using GameObject::Color;

    void setDamage(int num);
    int getDamage();

    QVector2D getCollideC();
    float getCollideR();

    void setSpeed(float s);
    QString getTexturePath();

private:
    int damage = 20;
    QVector2D collideC;
    float collideR;
};

#endif // PLAYERBULLET_H
