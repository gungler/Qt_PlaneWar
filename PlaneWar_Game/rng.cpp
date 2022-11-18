#include "rng.h"

//instance of all datas
std::random_device RNG::device{RNG::getSeed()};
std::mt19937 RNG::mtRNG(RNG::device());
std::uniform_real_distribution<long double> RNG::idDist{0.0L, 1.0e6L};
std::uniform_real_distribution<float> RNG::enemyTypeDist{0.0f, 100.0f};
std::uniform_real_distribution<float> RNG::locDist{-0.9f, 0.9f};
std::uniform_real_distribution<float> RNG::sizeDist{0.002f, 0.004f};

RNG::RNG()
{
}

std::string RNG::getSeed(){
    //use system time as the seed of rng
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::chrono::nanoseconds duration = now.time_since_epoch();//1970
    std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(duration);
    long x = static_cast<long>(sec.count());
    QString seed = QString::fromStdString(std::to_string(x));
    std::string seeds = seed.toStdString();
    return seeds;
}

long long RNG::genUserId(){
    return static_cast<long long>(idDist(mtRNG));
}

int RNG::genEnemyType(){
    int type = static_cast<int>(enemyTypeDist(mtRNG));
    if(type % 3 == 0){
        return 0;
    }else if(type % 3 == 1){
        return 1;
    }else{
        return 2;
    }
}

float RNG::genEnemyLocation(){
    return static_cast<float> (locDist(mtRNG));
}

float RNG::genParticleSize(){
    return sizeDist(mtRNG);
}
