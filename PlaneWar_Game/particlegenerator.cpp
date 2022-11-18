#include "particlegenerator.h"
unsigned int lastUsedParticle = 0;

ParticleGenerator::ParticleGenerator()
{
    qDebug() <<"i";
    for(unsigned int i = 0; i < 500; ++i)
        this->particles.push_back(Particle());
}

void ParticleGenerator::update(float dt, GameObject& object, unsigned int newParticles, QVector2D offset){
    //respawn a dead particle
    for(unsigned int i=0; i < newParticles; ++i){
        int unusedParticle = this->firstUnusedParticle();
        this->respawnParticle(this->particles[unusedParticle], object, offset);
    }

    //update all particles
    for(unsigned int i = 0; i < this->amount; ++i){
        Particle &p = this->particles[i];
        p.Life -= dt;
        if(p.Life > 0.0f){//particle not dead
            p.Position -= p.Speed * dt;
            p.Color.setW(p.Color.w() - dt * 0.25f);
        }
    }
}

unsigned int ParticleGenerator::firstUnusedParticle(){
    //first search from last used particle since they are more likely to dead
    for(unsigned int i = lastUsedParticle; i < this->amount; ++i){
        if(this->particles[i].Life <= 0.0f){
            lastUsedParticle = i;
            return i;
        }
    }

    //linear search
    for(unsigned int i=0; i < this->amount; ++i){
        if(this->particles[i].Life <= 0.0f){
            lastUsedParticle = i;
            return i;
        }
    }

    lastUsedParticle = 0;
    return 0;
}

void ParticleGenerator::respawnParticle(Particle& particle, GameObject& object, QVector2D offset){
    //generate a new particle with random Life
    float random = ((rand() % 100) - 50) / 10.0f;
    float rColor = 0.5f + ((rand() % 100) / 100.0f);
    particle.Position = object.Position() + QVector2D(0.0f, random) + offset;
    particle.Color = QVector4D(rColor, rColor, rColor, 1.0f);
    particle.Life = 1.0f;
    particle.Speed = QVector2D(object.Speed() * 0.5f, object.Speed() * 0.5f);
}
