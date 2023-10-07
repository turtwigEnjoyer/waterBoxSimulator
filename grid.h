#pragma once

#include "block.h"


class grid{

    private:
        vector<block> blocks;

        TPrecisionInfo ppm;
        TPrecisionInfo h,m; //smoothing distance and mass
        TPrecisionInfo sx,sy,sz; //Size of blocks
        int nx, ny, nz; //Number of blocks

        //These will remain constant during the whole program and should be computed once instead of every iteration
        TPrecisionInfo H2, H6;
        TPrecisionInfo PI_DIV15, PI_DIV45, PI_DIV315;

        //Should contain some data structure of blocks inside of it ? block[] blocks? maybe 3d?( bad idea i think)
        //Using a pseudo binary base nx,ny nz
        //Vector index is determined by bnX + nx*bnY +nx*ny*bnZ whre bnI is blockNumber for Ith coordinate
        //This is like binary. 7 = 1+ 2^1 +2^2. I think this will do better with memory
    
    public:
        static grid* pSingleton;
    //Should assign particles to their respective blocks
    public:
        grid();
        virtual ~grid();
        
        void Load(ifstream& pFile);
        TBlockIndex PutInBlock(particle::PParticle p);
        void calculateDistances();
        //std::move is more useful
/*         void Move(particle::PParticle pParticula, TBlockIndex indiceOrigen, TBlockIndex indiceDestin); */
        TBlockIndex BlockIndex(TPrecisionInfo x, TPrecisionInfo y, TPrecisionInfo z);
        /* void determineBlock(particle p);
        void repositionParticles(); //4.3.1 Repositioning Particles    
        */
    private:
        void FillAdjacents();
        int WhichDirections(size_t index);
        void chooseDirections(int choose, int index);
        void XYZdir(int index);
        void XYdir(int index);
        void XZdir(int index);
        void YZdir(int index);
};

#define GRID (*grid::pSingleton)