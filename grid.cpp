#include "grid.hpp"

using namespace std;

grid::grid(float ppm){
    h = RAD_MULT / ppm;
    m= DENSITY * ppm;
    nx,ny,nz = (int)(XMAX-XMIN)/h, (int)(YMAX-YMIN)/h, (int)(ZMAX-ZMIN)/h;
    sx,sy,sz = (XMAX-XMIN)/nx, (YMAX-YMIN)/ny, (ZMAX-ZMIN)/nz;
    //initialize blocks
    vector<block> blocks(nx*ny*nz);

    //Initialise important "constants"
    H2= pow(h,2);
    H6 = pow(h,6);
    PI_DIV15 = 15/(M_1_PI*H6);
    PI_DIV315 = (315*m)/(M_1_PI*pow(h,9)*64);
    PI_DIV45 = 3* PI_DIV15*VISCOSITY*m;



}
void grid::determineBlock(particle p){
    //This operation is going to happen a lot. Can we find a way to do it less?

    int i = (p.px - XMIN)/nx; 
    int j = (p.py - YMIN)/ny;
    int k = (p.pz - ZMIN)/nz;
    // blocks[i+ nx*j+ nx*ny*k] add p;
}