#include "particle.hpp"
#include <iostream>


particle::particle(float px, float py, float pz, float vx, float vy, float vz, float hvx, float hvy, float hvz){
    this->px = px;
    this->py = py;
    this->pz = pz;

    this->vx = vx;
    this->vy = vy;
    this->vz = vz;

    this->hvx = hvx;
    this->hvy = hvy;
    this->hvz = hvz;
}
void printParticle(particle name){
    std::cout << "px, py, pz: (" << name.px << name.py << name.pz << ")\n";
}
