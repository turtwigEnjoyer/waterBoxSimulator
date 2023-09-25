#include "particle.hpp"
#include <iostream>


particle::particle(float* p){
    this->px = p[0];
    this->py = p[1];
    this->pz = p[2];

    this->vx = p[3];
    this->vy = p[4];
    this->vz = p[5];

    this->hvx = p[6];
    this->hvy = p[7];
    this->hvz = p[8];
}
/* s */ 
void printParticle(particle name){
    std::cout << "px, py, pz: (" << name.px << name.py << name.pz << ")\n";
}
