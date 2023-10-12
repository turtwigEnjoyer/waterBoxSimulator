#pragma once
#include "particle.h"

using namespace std;

//This is the class of a block which includes the functions related to the content of the block

class block{
   private:
   
   vector<ParticlePos> positions;
   
   //The following function represent the truth about the boundaries, if the edge(borde) are present or not
   bool xRightEdge, yRightEdge, zRightEdge;
   bool xLeftEdge, yLeftEdge, zLeftEdge;

   private:
      void amIEdge(int index);
      void direction();       

   public:
      vector<particle::PParticle> particles;
      block();
      virtual ~block(); //destructure of the block class, where a subclass can implement its own functions

      //Std::move() is much more useful/
      void PushBack(particle::PParticle pParticle);
      void PushBack(ParticlePos pos);
      void CalculateDistances(block& other);
      void CalculateSelfDistances();
      void ClearDensities();
      void DensityTransformations();
      //for tests 
      size_t GetParticlesSize();
      particle::PParticle GetParticleAtIndex(size_t index);

};
//tests
   void testCalculateDistances();