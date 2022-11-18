#ifndef RNG_H
#define RNG_H

#include<QString>
#include"random"
#include"chrono"

class RNG
{
public:
    static long long genUserId();
    static std::string getSeed();
    static int genEnemyType();
    static float genEnemyLocation();
    static float genParticleSize();

private:
    RNG();
    static std::random_device device;
    static std::mt19937 mtRNG;
    static std::uniform_real_distribution<long double> idDist;
    static std::uniform_real_distribution<float> enemyTypeDist;
    static std::uniform_real_distribution<float> locDist;
    static std::uniform_real_distribution<float> sizeDist;
};

#endif // RNG_H
