#include "block.h"

block::block()
{

}

block::~block()
{

}

void block::PutIn(particle::PParticle pParticle)
{
    content.push_back(pParticle);
}

void block::PutOut(particle::PParticle pParticle)
{
    content.erase(find(content.begin(),content.end(),pParticle));
}

void block::AddAdjacents(TBlockIndex indice) 
{
    //figure out how to spell adyacent
    adyacents.push_back(indice);
}

void block::CalculateDistances()
{
    for(auto it=content.begin();it!=content.end();it++)
    {
        auto jt=it;
        jt++;
        for(;jt!=content.end();jt++)
        {
            GET_PARTICLE(*it)->CalculateDistance(GET_PARTICLE(*jt));
        }
    }
}