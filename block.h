#pragma once
#include "particle.h"

using namespace std;

class block{

    list<particle::PParticle> content;
    list<TBlockIndex> adyacents;
    public:
        block();
        virtual ~block();

        void PutIn(particle::PParticle pParticula);
        void PutOut(particle::PParticle pParticula);

        void AddAdjacents(TBlockIndex index);
        void CalculateDistances();
};