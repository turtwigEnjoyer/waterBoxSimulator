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
  float px, py, pz;

  float vx, vy, vz;

  float hvx, hvy, hvz;

  particle(float px, float py, float pz, float vx, float vy, float vz, float hvx, float hvy, float hvz);
  //void read(ifstream file){}

};
void printParticle(particle name);
