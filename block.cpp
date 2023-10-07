#include "block.h"

block::block()
{

}

block::~block()
{

}

void block::PushBack(particle::PParticle pParticle)
{
    particles.push_back(pParticle);
}
void block::PushBack(ParticlePos pos)
{
    pos.setOwner(positions.size());
    positions.push_back(pos);
}

/* void block::PutOut(particle::PParticle pParticle)
{
    positions.erase(find(positions.begin(),positions.end(),pParticle));
} */

/*
When ParticlePos is used
 void block::CalculateDistances(block& other){
    for(auto it= positions.begin();it!=positions.end();it++){
        for(auto jt=other.positions.begin();jt!=other.positions.end();jt++){
            TPrecisionInfo distance = it->CalculateDistance(*jt);
            particles[it->ownerId].distances.push_back(distance);
            other.particles[jt->ownerId].distances.push_back(distance);
        }
    }
}
void block::CalculateSelfDistances(){
    for(auto it =positions.begin(); it!=positions.end();it++){
        auto jt=it;
        jt++;
        for(;jt!= positions.end(); jt++){
            TPrecisionInfo distance= it->CalculateDistance(*jt);
            particles[it->ownerId].distances.push_back(distance);
            particles[jt->ownerId].distances.push_back(distance);
        }
    }
}
*/
void block::CalculateDistances(block& other){
    for(auto it= particles.begin();it!=particles.end();it++){
        for(auto jt=other.particles.begin();jt!=other.particles.end();jt++){
            it->CalculateDistance(*jt);
        }
    }
}
void block::CalculateSelfDistances(){
    for(auto it =particles.begin(); it!=particles.end();it++){
        auto jt=it;
        jt++;
        for(;jt!= particles.end(); jt++){
            it->CalculateDistance(*jt);
        }
    }
}
void block::ClearDistances(){
    for(auto i: particles){
        i.ClearDistances();
        i.ClearDensity();
    }
}
