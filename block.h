#pragma once
#include "particle.h"

using namespace std;

class block{

        vector<particle::PParticle> particles;
        vector<ParticlePos> positions;
        bool xRightEdge, yRightEdge, zRightEdge;
        bool xLeftEdge, yLeftEdge, zLeftEdge;
        private:
        void amIEdge(int index);
        void direction();  
        public:
        block();
        virtual ~block();

        //Std::move() is much more useful/
        void PushBack(particle::PParticle p);
        void PushBack(ParticlePos pos);
        void CalculateDistances(block& other);
        void CalculateSelfDistances();
        void ClearDensities();
        void DensityTransformations();
};