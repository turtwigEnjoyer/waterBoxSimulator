#pragma once

#include "particle.hpp"
#include "block.hpp"

class grid{
    private:
        //STORING CONSTANTS (HERE FOR NOW ? MAYBE SOME SHOULD GO TO BLOCK)
        static const float RAD_MULT =1.695, DENSITY = 10^3, STIFF_PRESS =3.0, STIFF_COLL = 3*10^4;
        static const float DAMPING =128.0, VISCOSITY = 0.4, P_SIZE = 2*10^-4, T_STEP = 10^-3;
        static const float YMAX= 0.1, YMIN= -0.08, XMAX = 0.065, XMIN= -0.065, ZMAX = 0.065, ZMIN= -0.065;

        static float h, m;
        static float sx,sy,sz;        
        static int nx, ny, nz;

        //These will remain constant during the whole program and should be computed once instead of every it
        static float H2, H6;
        static float PI_DIV15, PI_DIV45, PI_DIV315;

        //Should contain some data structure of blocks inside of it ? block[] blocks? maybe 3d?( bad idea i think)
        //Using a pseudo binary base nx,ny nz
        //Array index is determined by bnX + nx*bnY +nx*ny*bnZ whre bnI is blockNumber for Ith coordinate
        //This is like binary. 7 = 1+ 2^1 +2^2. I think this will do better with memory

        vector<block> blocks(); 


    public:

    //Should assign particles to their respective blocks

    void determineBlock(particle p);
    grid(float ppm);
};