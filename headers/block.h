#pragma once
#include "particle.h"

using namespace std;

//This is the class of a block which includes the functions related to the content of the block

class block{
   private:
   
   vector<ParticlePos> positions;
   
   //The following function represent the truth about the boundaries, if the edge(borde) are present or not
   int edgeRepresentation;


   public:
      vector<particle::PParticle> particles;
      vector<int> adjacents; //Trying to simplify code. Will store all adjacent blocks to itself
      bool xPosEdge, yPosEdge, zPosEdge;
      bool xNegEdge, yNegEdge, zNegEdge;

      block();
      virtual ~block(); //destructure of the block class, where a subclass can implement its own functions

      //Std::move() is much more useful/
      void amIEdge(int index, int nx, int ny, int nz);
      void PushBack(particle::PParticle pParticle);
      void PushBack(ParticlePos pos);
      void PushBackAdjacents(int i);
      void CalculateDistances(block& other);
      void CalculateSelfDistances();
      void ClearDensities();
      void DensityTransformations();
      void CalculateSelfAccelerations();
      void CalculateAccelerations(block& other);
      //for tests 
      size_t GetParticlesSize();
      particle::PParticle GetParticleAtIndex(size_t index);

};
//tests
   void testCalculateDistances();