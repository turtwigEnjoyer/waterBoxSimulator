#pragma once
#include "Dependencies.h"
//#define PARTICULA_POR_IDENTIFICADOR
class particle{
  public:
    typedef int TId; //We are using int now, but might need bigger
    #ifdef PARTICULA_POR_IDENTIFICADOR
    typedef size_t PParticle;
    #else
    typedef particle* PParticle;
    #endif
    
    static vector<particle> particles;

  private:
    static TId lastId;
    static int sParticles;

    int id;
    TBlockIndex blockIndex; //Is it really useful?
    //Should they be vectors or arrays? They will be accessed together most of the time
    TPrecisionInfo ax,ay,az;
    TPrecisionInfo px,py,pz;
    TPrecisionInfo vx,vy,vz;
    TPrecisionInfo hvx,hvy,hvz;

    vector<TPrecisionInfo> distances;

    particle(float* initArray);
  public:
    virtual ~particle();
    void MoveTo(float x, float y, float z);
    static void Sload(ifstream& fin, int pCount);
    static void CleanDistances();
  public:
   //Getters and setters
    TId GetId() const;
    TPrecisionInfo GetX() const;
    TPrecisionInfo GetY() const;
    TPrecisionInfo GetZ() const;

    void Reposition();
    void CalculateDistance(particle* pOperando);
  private:
    void MoveTo(TPrecisionInfo x, TPrecisionInfo y, TPrecisionInfo z);
    void PutInCaja();

};
#ifdef PARTICULA_POR_IDENTIFICADOR
    #define GET_PARTICLE(pIndex) (&(Particle::particles[pIndex]))
#else
    #define GET_PARTICLE(pIndex) (pIndex)
#endif
