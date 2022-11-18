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

private:
    RNG();
    static std::random_device device;
    static std::mt19937 mtRNG;
    static std::uniform_real_distribution<long double> idDist;
};

#endif // RNG_H
