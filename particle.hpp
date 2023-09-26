#pragma once

#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector> 

struct particle{
  //Position, hv (?), velocity
  //Should they be vectors or arrays? They will be accessed together most of the time 
  int id;
  float ax,ay,az;
  float px, py, pz;

  float vx, vy, vz;

  float hvx, hvy, hvz;

  //void read(ifstream file){}
  particle(float* p); //initialize an array p of particles

};
struct input{
  int np;
  float ppm;
  std::vector<particle> ps;
/*   input(); */
};
void printParticle(particle name);
