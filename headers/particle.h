
#pragma once
#include "ParticlePos.h"

class particle{
  public:
    typedef int TId; //We are using int now, but might need bigger
    typedef particle PParticle;
    
    // vector<TPrecisionInfo> distances; We were using too much memory! !
    //static vector<particle> particles; Not needed any more

  private:
    static TId lastId;
    static int sParticles;

    static constexpr TPrecisionInfo FLUID_DENSITY = 1000.0;
    static constexpr TPrecisionInfo STIFF_PRESS = 3.0;
    static constexpr TPrecisionInfo STIFF_COLL =30000.0;
    static constexpr TPrecisionInfo DAMPING =128.0;
    static constexpr TPrecisionInfo VISCOSITY = 0.4;
    static constexpr TPrecisionInfo P_SIZE =0.0002;
    static constexpr TPrecisionInfo T_STEP =0.001;
    static constexpr TPrecisionInfo GRAVITY = -9.8;

    int id;
    //TBlockIndex blockIndex; //Is it really useful?
    //Should they be vectors or arrays? They will be accessed together most of the time
    TPrecisionInfo ax,ay,az;
    TPrecisionInfo px,py,pz;
    TPrecisionInfo vx,vy,vz;
    TPrecisionInfo hvx,hvy,hvz;
    TPrecisionInfo density; 


    particle(float initArray[]);
   

  public://no entiendo la definición que has hecho aqui...
  
    particle(float x, float y, float z); //for tests   
    virtual ~particle();

    void MoveTo(float x, float y, float z);
    static void Sload(ifstream& fin, int pCount);
    //void ClearDistances();
  
  public:
   //Getters and setters
    TId GetId() const;
    TPrecisionInfo GetX() const;
    TPrecisionInfo GetY() const;
    TPrecisionInfo GetZ() const;
    TPrecisionInfo GetDensity() const;
    TPrecisionInfo GetAX() const;
    TPrecisionInfo GetAY() const;
    TPrecisionInfo GetAZ() const;
   
    
    //Particles functions 
    void ClearDensity();
    void DensityTransformation();
    void ClearDistances();
    void ClearAcceleration();
    void CalculateAccelerations(particle& other);
  
  
    //Collision´s Function for particles
    void CalculateCollisionsXP();
    void CalculateCollisionsXN();
    void CalculateCollisionsYP();
    void CalculateCollisionsYN();
    void CalculateCollisionsZP();
    void CalculateCollisionsZN();

    // Particles motion
    void CalculateParticlesMotionPar();

    //Boundarie´s functions for particles
    void CalculateBoundariesParXP();
    void CalculateBoundariesParXN();
    void CalculateBoundariesParYP();
    void CalculateBoundariesParYN();
    void CalculateBoundariesParZP();
    void CalculateBoundariesParZN();
    


    void Reposition();
    TPrecisionInfo CalculateDistance(PParticle other);
    TPrecisionInfo DensityIncrease(TPrecisionInfo distance);
    
  private:
    void MoveTo(TPrecisionInfo x, TPrecisionInfo y, TPrecisionInfo z);
    void PutInCaja();
    void AddDensity(TPrecisionInfo increase);

};