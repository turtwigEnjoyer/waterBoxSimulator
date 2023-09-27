#include "particle.h"
#include "grid.h"

particle::TId particle::lastId=0;
int particle::sParticles=0;
vector<particle> particle::particles;


particle::particle(float* p){
    px = p[0];
    py = p[1];
    pz = p[2];

    vx = p[3];
    vy = p[4];
    vz = p[5];

    hvx = p[6];
    hvy = p[7];
    hvz = p[8];

    id=lastId;
    lastId++;
    #ifdef PARTICULA_POR_IDENTIFICADOR
        blockIndex=GRID.putInBlock(id);
    #else
        blockIndex=GRID.PutInBlock(this);
    #endif 
}
particle::~particle(){
    
}
void particle::Sload(ifstream& fin, int pCount){
	
	float p[9];  //create an space of 9 to define the body of each particle
	//Particles are read, intiliased and stored in a vector
	for (int i = 0; i< pCount; i++){
		fin.read(reinterpret_cast<char*>(p), 9* sizeof(float));
        particles.push_back(particle(p)); //Constructor already adds to our Data Structure on Grid and Block
	}

}
void particle::MoveTo(TPrecisionInfo x, TPrecisionInfo y, TPrecisionInfo z)
{
    TBlockIndex newIndex=GRID.BlockIndex(x,y,z);
    px=x;
    py=y;
    pz=z;
    if (blockIndex!=newIndex)
    {
#ifdef PARTICULA_POR_IDENTIFICADOR
        GRID.Mover(id,blockIndex,newIndex);
#else
        GRID.Move(this,blockIndex,newIndex);
#endif
        blockIndex=newIndex;
    }
}

void particle::Reposition()
{
    ax=INIT_GX;
    ay=INIT_GY;
    az=INIT_GZ;
}

void particle::CalculateDistance(particle* pOperando)
{
    TPrecisionInfo d=pow(px-pOperando->px,2)+pow(py-pOperando->py,2)+pow(py-pOperando->py,2);
    distances.push_back(d);
    pOperando->distances.push_back(d);
}
void particle::CleanDistances()
{
    for(auto it=particles.begin();it!=particles.end();it++)
    {
        it->distances.clear();
    }
}


//Getters and Setters
TPrecisionInfo particle::GetX() const{
    return px;
}
TPrecisionInfo particle::GetY() const{
    return py;
}
TPrecisionInfo particle::GetZ() const{
    return pz;
}
particle::TId particle::GetId() const{
    return id;
}