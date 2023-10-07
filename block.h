#pragma once
#include "particle.h"

using namespace std;

class block{

        vector<particle::PParticle> particles;
        vector<ParticlePos> positions;  
        public:
        block();
        virtual ~block();

        //Std::move() is much more useful/
        void PushBack(particle::PParticle p);
        void PushBack(ParticlePos pos);
        void CalculateDistances(block& other);
        void CalculateSelfDistances();
        void ClearDistances();
        void DensityTransformations();
};