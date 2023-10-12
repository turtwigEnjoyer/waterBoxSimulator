#pragma once
#include "particle.h"

using namespace std;

//This is the class of a block which includes the functions related to the content of the block

class block{
   private:
   
   vector<ParticlePos> positions;
   
   //The following function represent the truth about the boundaries, if the edge(borde) are present or not
   int edgeRepresentation;


   private:
      void amIEdge(int index, int nx, int ny, int nz);
   public:
      vector<particle::PParticle> particles;
      bool xPosEdge, yPosEdge, zPosEdge;
      bool xNegEdge, yNegEdge, zNegEdge;
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