#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <QObject>
#include <QtGlobal>
#include <QVector4D>
#include <QVector3D>
#include <QString>

#include"gameobject.h"

class EnemyBullet : public GameObject
{
public:
    explicit EnemyBullet(QVector4D position = {}, QVector3D color = {});

    using GameObject::Position;
    using GameObject::Color;
    using GameObject::isDestroied;

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

#endif // ENEMYBULLET_H
