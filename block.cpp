
#include "headers/block.h"
#include "headers/particle.h"



block::block(){
}

block::~block(){
}
size_t block::GetParticlesSize(){
    return particles.size();
}
particle::PParticle block::GetParticleAtIndex(size_t index){
    if (index < particles.size()) {
        return particles[index];
    } else {
       throw std::out_of_range("Index out of range of particles.");
    }
}

void block::PushBack(particle::PParticle pParticle){
    
    particles.push_back(pParticle);
}
void block::PushBack(ParticlePos pos)
{
    pos.setOwner(positions.size());
    positions.push_back(pos);
}

//Here we include some unitary tests for the upper functions:

/* void block::PutOut(particle::PParticle pParticle)
{
    positions.erase(find(positions.begin(),positions.end(),pParticle));
} */

/*
When ParticlePos is used
 void block::CalculateDistances(block& other){
    for(auto it= positions.begin();it!=positions.end();it++){
        for(auto jt=other.positions.begin();jt!=other.positions.end();jt++){
            TPrecisionInfo distance = it->CalculateDistance(*jt);
            particles[it->ownerId].distances.push_back(distance);
            other.particles[jt->ownerId].distances.push_back(distance);
        }
    }
}
void block::CalculateSelfDistances(){
    for(auto it =positions.begin(); it!=positions.end();it++){
        auto jt=it;
        jt++;
        for(;jt!= positions.end(); jt++){
            TPrecisionInfo distance= it->CalculateDistance(*jt);
            particles[it->ownerId].distances.push_back(distance);
            particles[jt->ownerId].distances.push_back(distance);
        }
    }
}
*/
TPrecisionInfo CalculateDistance(particle a, particle b){
    TPrecisionInfo dx=pow((a.GetX()-b.GetX()),2);
    TPrecisionInfo dy= pow((a.GetY()-b.GetY()),2);
    TPrecisionInfo dz = pow((a.GetZ()-b.GetZ()),2);
    return dx+dy+dz;
}
void block::CalculateDistances(block& other){
    for(size_t i= 0; i< particles.size(); i++){
        for (size_t j= 0; j<other.particles.size();j++){
            TPrecisionInfo distance= CalculateDistance(particles[i],other.particles[j]);
            particles[i].DensityIncrease(distance);
            other.particles[j].DensityIncrease(distance);
        }
    }
}
void block::CalculateSelfDistances(){
    for(auto it =particles.begin(); it!=particles.end();it++){
        auto jt=it;
        jt++;
        for(;jt!= particles.end(); jt++){
            it->CalculateDistance(*jt);
        }
    }
}
void block::ClearDensities(){
    for(auto i: particles){
        //i.ClearDistances();
        i.ClearDensity();
    }
}
void block::DensityTransformations(){
    for(auto i: particles){
        i.DensityTransformation();
    }
}


 void block::amIEdge(int index, int nx, int ny, int nz){
    //Is a block an edge of the grid, if so which edges

    (index % nx)==(nx-1)?(xPosEdge=true):xPosEdge=false;
    (index/nx)%ny ==ny-1 ?(yPosEdge=true):yPosEdge=false;
    (index/(nx*ny))%nz == nz-1 ?(zPosEdge=true):zPosEdge=false;

    (index % nx)==(0)?(xNegEdge=true):xNegEdge=false;
    (index/nx)%ny ==0 ?(yNegEdge=true):yNegEdge=false;
    //Result represented in tertiary base for simplicity (?is this the simplest way, really?)

    // nx*ny*nz
    //block(indice)
    // block(27)    y=3 z=0 x=7
    // block[0][3][7]
    // indice % numberXBlocks == 0 o nx-1
    //27 cases total... This seems overly complicated. Any ideas?
    /* Cases:
        NOT EDGE: 0
        xPosEdge: 1
        xNegEdge: 2
        yPosEdge: 3
        xPosEdge & yPosEdge: 4
        xNegEdge & yPosEdge: 5
        yNegEdge: 6
        xPosEdge & yNegEdge: 7
        xNegEdge & yNegEdge: 8
        zPosEdge: 9
        xNegEdge & zPosEdge: 11
        xPosEdge & zPosEdge: 10
        yPosEdge & zPosEdge: 12
        xPosEdge & yPosEdge & zPosEdge: 13
        xNegEdge & yPosEdge & zPosEdge: 14
        yNegEdge & zPosEdge: 15
        xPosEdge & yNegEdge & zPosEdge: 16
        xNegEdge & yNegEdge & zPosEdge: 17  
        zNegEdge: 18  
        xPosEdge & zNegEdge: 19
        xNegEdge & zNegEdge: 20
        yPosEdge & zNegEdge: 21 
        xPosEdge & yPosEdge & zNegEdge: 22
        xNegEdge & yPosEdge & zNegEdge: 23
        yNegEdge & zNegEdge: 24
        xPosEdge & yNegEdge & zNegEdge: 25 
        xNegEdge & yNegEdge & zNegEdge: 26       
     */
}



