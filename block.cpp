#include "block.h"

block::block()
{

}

block::~block()
{

}

void block::PushBack(particle::PParticle pParticle)
{
    particles.push_back(pParticle);
}
void block::PushBack(ParticlePos pos)
{
    pos.setOwner(positions.size());
    positions.push_back(pos);
}

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
void block::CalculateDistances(block& other){
    /* for(auto it= particles.begin();it!=particles.end();it++){
        for(auto jt=other.particles.begin();jt!=other.particles.end();jt++){
            it->CalculateDistance(*jt);
        }
    } */
    for(size_t i= 0; i< particles.size(); i++){
        for (size_t j= 0; j<other.particles.size();j++){
            particles[i].CalculateDistance(other.particles[j]);
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
/*  void block::amIEdge(int index){
        
    We will only calculate distances with forward blocks, assuming all backwards have been executed.
    We will calculate with the block on the xDirection if our x position is an edge
        That is i%nx == nx-1 Because every k*(nx-1) mod nx is an edge by our indexing. (Rightmost edge)
    Same for yDirection and zDirection. (the current code works thanks to integer division truncating results)
    Example nx=2 ny= 5. 2 Dimensions. Every second block will be an xRIghtEdge and blocks 8,9 will be yRightEdges
    
    (index % nx)==(nx-1)?(xRightEdge=true):xRightEdge=false;
    (index/nx)%ny ==ny-1 ?(yRightEdge=true):yRightEdge=false;
    (index/(nx*ny))%nz == nz-1 ?(zRightEdge=true):zRightEdge=false;

    (index % nx)==(0)?(xRightEdge=true):xRightEdge=false;
    (index/nx)%ny ==0 ?(yRightEdge=true):yRightEdge=false;
    (index/(nx*ny))%nz == 0 ?(zRightEdge=true):zRightEdge=false;
} 
 */
