#pragma once
#include "particle.h"

using namespace std;

class block{

        vector<particle::PParticle> content;  
        public:
        block();
        virtual ~block();

        //Std::move() is much more useful/
        void PushBack(particle::PParticle p);
        void CalculateDistances(block& other);
};