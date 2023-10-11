#pragma once

#include "block.h"


class grid{

    private:
        constexpr static TPrecisionInfo VISCOSITY =0.4;
        constexpr static TPrecisionInfo RAD_MULT =1.695; 
        constexpr static TPrecisionInfo DENSITY =1000.0;

        vector<block> blocks;

        TPrecisionInfo ppm;
        TPrecisionInfo h,m; //smoothing distance and mass
        TPrecisionInfo sx,sy,sz; //Size of blocks
        int nx, ny, nz; //Number of blocks

        //These will remain constant during the whole program and should be computed once instead of every iteration
        //Should contain some data structure of blocks inside of it ? block[] blocks? maybe 3d?( bad idea i think)
        //Using a pseudo binary base nx,ny nz
        //Vector index is determined by bnX + nx*bnY +nx*ny*bnZ whre bnI is blockNumber for Ith coordinate
        //This is like binary. 7 = 1+ 2^1 +2^2. I think this will do better with memory
    
    public:
        static grid* pSingleton;
        TPrecisionInfo H2, H6;
        TPrecisionInfo PI_DIV15, PI_DIV45, PI_DIV315;
    //Should assign particles to their respective blocks
    public:
        grid();
        virtual ~grid();
        
        void Load(ifstream& pFile);
        void PutInBlock(particle::PParticle p, int whichBlock);
        int PutInBlock(ParticlePos pos); 
        void calculateDistances();
        void ClearDensities();
        void DensityTransformations();
        void AccelerationTransfer();
        //std::move is more useful
/*         void Move(particle::PParticle pParticula, TBlockIndex indiceOrigen, TBlockIndex indiceDestin); */
        TBlockIndex BlockIndex(vector<TPrecisionInfo> positions);
        /* void determineBlock(particle p);
        void repositionParticles(); //4.3.1 Repositioning Particles    
        */
    private:
        void FillAdjacents();
        int WhichDirections(int index);
        void chooseDirections(int choose, size_t index);
        void XYZdir(size_t index);
        void XYdir(size_t index);
        void XZdir(size_t index);
        void YZdir(size_t index);
};

#define GRID (*grid::pSingleton)