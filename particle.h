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


    constexpr static TPrecisionInfo STIFF_PRESS =3.0;
    constexpr static TPrecisionInfo STIFF_COLL =30000.0;
    constexpr static TPrecisionInfo DAMPING =128.0;
    constexpr static TPrecisionInfo P_SIZE =0.0002;
    constexpr static TPrecisionInfo T_STEP =1000.0;

    int id;
    //TBlockIndex blockIndex; //Is it really useful?
    //Should they be vectors or arrays? They will be accessed together most of the time
    //TPrecisionInfo ax,ay,az;
    TPrecisionInfo px,py,pz;
    TPrecisionInfo vx,vy,vz;
    TPrecisionInfo hvx,hvy,hvz;
    TPrecisionInfo density; 


    particle(float initArray[]);
    particle(float x, float y, float z); //for tests   

  public://no entiendo la definición que has hecho aqui...

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
    void ClearDensity();
    void DensityTransformation();

    void Reposition();
    void CalculateDistance(PParticle& other);
    TPrecisionInfo DensityIncrease(TPrecisionInfo distance);
  private:
    void MoveTo(TPrecisionInfo x, TPrecisionInfo y, TPrecisionInfo z);
    void PutInCaja();
    void AddDensity(TPrecisionInfo increase);

};
