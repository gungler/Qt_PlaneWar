#ifndef PLAYERPLANE_H
#define PLAYERPLANE_H

#include <QObject>
#include <QtGlobal>
#include <QVector>
#include <QTimer>

#include <QDebug>
#include <QException>

#include"gameobject.h"
#include"playerbullet.h"
#include"skill.h"
#include"soundengine.h"

class PlayerPlane : public GameObject, public Skill
{
public:
    explicit PlayerPlane(QVector4D position = {},
                         QVector3D color = {},
                         QString skillName = "",
                         int skinIndex = 0);

    using GameObject::Position;
    using GameObject::isDestroied;
    using GameObject::Color;
    using GameObject::setSpeed;
    using GameObject::getSpeed;
    using GameObject::moveUp;
    using GameObject::moveDown;
    using GameObject::moveLeft;
    using GameObject::moveRight;

    using Skill::addEnergy;
    using Skill::getEnergy;
    using Skill::setMaxEnergy;

    void bulletMoveUp();

    void setHealth(int health);
    void setSkill(int skilltype);
    void takeDamage(int damage);
    bool isRedBullet();

    void changeScore(int score);
    int getScore();
    int getHealth();
    float getShootSpeed();

    QString getSkill();

    QVector2D getCollideC();
    float getCollideR();

    void useSkill();
    void restoreAllHealth();

    void setBulletDamage(int damage);

    QVector<PlayerBullet> playerbullets;
    int skinIndex;

private:
    //skill state. 4 to make byte alignment
    static QTimer* skillTimer;
    static QTimer* invincibleTimer;
    static SoundEngine sounds;

    int health = 0;
    int armour = 0;
    int score = 0;

    QVector2D collideC;
    float collideR;
    float shootSpeed = 0.2f;

    QString skillName = "";
    bool skillstate = 0;
    bool invincible = 0;

private slots:
    void skillEnd();
    void invincibleEnd();
};

#endif // PLAYERPLANE_H
