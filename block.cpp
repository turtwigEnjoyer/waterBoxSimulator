#include "block.h"

block::block()
{

}

block::~block()
{

}

void block::PushBack(particle::PParticle pParticle)
{
    content.push_back(pParticle);
}

/* void block::PutOut(particle::PParticle pParticle)
{
    content.erase(find(content.begin(),content.end(),pParticle));
} */
void block::CalculateDistances(block& other){
    for(auto it= content.begin();it!=content.end();it++){
        for(auto jt=other.content.begin();jt!=other.content.end();jt++){
            
        }
    }
}
