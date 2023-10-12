#include "headers/ParticlePos.h"

ParticlePos::ParticlePos(float pos[]){
    for(int i= 0; i<3; i++){
        position.push_back((float)pos[i]); //loads px,py,pz
    }
}
ParticlePos::~ParticlePos(){

}
void ParticlePos::setOwner(int ownerId){
    this->ownerId=ownerId;
}
 
TPrecisionInfo ParticlePos::CalculateDistance(ParticlePos& other){
    TPrecisionInfo distance=pow(position[0]-other.position[0],2)+pow(position[1]-other.position[1],2)+pow(position[2]-other.position[2],2);
    return distance;
}