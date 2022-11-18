#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QObject>
#include <QtGlobal>
#include <QVector>
#include <QVector4D>
#include <QVector3D>
#include <QString>

#include <QDebug>
#include <QException>

#include "gameobject.h"
#include "enemybullet.h"

class EnemyPlane : public GameObject
{
public:
    explicit EnemyPlane(QVector4D position = {},
                        QVector3D color = {},
                        int type = 0);

    using GameObject::isDestroied;
    using GameObject::Position;
    using GameObject::Color;

    void setHealth(int health);
    void takeDamage(int damage);

    void planeMoveDown();
    void bulletMoveDown();
    QVector2D getCollideC();
    float getCollideR();

    int getBonusEnergy();
    void setSpeed(float s);
    void setType(int type);
    int getType();
    QVector<EnemyBullet> enemybullets;


private:
    QVector2D collideC;
    float collideR;

    //0 = small, 1 = medium, 2 = big
    int enemyType = 0;

    int health = 0;
    int armour = 0;
    int bonusEnergy = 0;
};

#endif // ENEMYPLANE_H
