#include "grid.hpp"

using namespace std;

grid::grid(float ppm){
    h = RAD_MULT / ppm;
    nx,ny,nz = (int)(XMAX-XMIN)/h, (int)(YMAX-YMIN)/h, (int)(ZMAX-ZMIN)/h;
    sx,sy,sz = (XMAX-XMIN)/nx, (YMAX-YMIN)/ny, (ZMAX-ZMIN)/nz;
    //initialize blocks
    vector<block> blocks(nx*ny*nz);
}
void grid::determineBlock(particle p){
    //This operation is going to happen a lot. Can we find a way to do it less?

    int i = (p.px - XMIN)/nx; 
    int j = (p.py - YMIN)/ny;
    int k = (p.pz - ZMIN)/nz;
    // blocks[i+ nx*j+ nx*ny*k] add p;
}