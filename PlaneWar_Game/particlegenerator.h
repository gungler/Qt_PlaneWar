#ifndef PARTICLEGENERATOR_H
#define PARTICLEGENERATOR_H

#include<QVector>
#include<QVector2D>
#include<QVector4D>
#include"gameobject.h"
#include<QDebug>

struct Particle{
    QVector2D Position, Speed;
    QVector4D Color;
    float Life;

    Particle():Position(0.0f, 0.0f), Speed(0.0f, 0.0f), Color(0.4f, 0.5f, 0.6f, 1.0f), Life(0.0f){}
};

class ParticleGenerator
{
public:
    ParticleGenerator();

    void update(float dt, GameObject& object, unsigned int newParticles, QVector2D offset = QVector2D(0.0f, 0.0f));
    QVector<Particle> particles;

private:
    unsigned int amount = 500;
    void init();
    unsigned int firstUnusedParticle();

    void respawnParticle(Particle& particle, GameObject& object, QVector2D offset = QVector2D(0.0f, 0.0f));
};

#endif // PARTICLEGENERATOR_H
