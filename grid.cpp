#include "grid.h"

grid* grid::pSingleton;

grid::grid(){
    pSingleton=this;
}
grid::~grid(){

}

void grid::Load(ifstream& fin){
    float rppm;
    fin.read(reinterpret_cast<char*>(&rppm), sizeof(int));
    ppm = rppm;
    h = RAD_MULT / ppm;
    m= DENSITY * ppm;
    nx = (int)((XMAX-XMIN)/h);
    ny = (int)((YMAX-YMIN)/h);
    nz = (int)((ZMAX-ZMIN)/h);
    sx = (XMAX-XMIN)/nx; 
    sy = (YMAX-YMIN)/ny; 
    sz = (ZMAX-ZMIN)/nz;
    //initialize blocks
    blocks = vector<block>(nx*ny*nz);
    //FillAdjacents(); //Maybe irrelevant? We should try without to make more readable

    //Initialise important "constants"
    grid::H2= pow(h,2);
    grid::H6 = pow(h,6);
    PI_DIV15 = 15/(M_1_PI*H6);
    PI_DIV315 = (315*m)/(M_1_PI*pow(h,9)*64);
    PI_DIV45 = 3* PI_DIV15* (float)VISCOSITY *m;

}
void grid::PutInBlock(particle::PParticle particle, int whichBlock){
    blocks[whichBlock].PushBack(particle);
}
int grid::PutInBlock(ParticlePos pos){
    int index=BlockIndex(pos.position);
    blocks[index].PushBack(pos);
    return index;
}
/* void grid::Move(particle::PParticle pParticula, TBlockIndex indiceOrigen, TBlockIndex indiceDestino)
{
    blocks[indiceOrigen].PutOut(pParticula);
    blocks[indiceDestino].PutIn(pParticula);
} */

int Range(int x,int min,int max)
{
    //If x<0 ret 0, x>max ret max, else return x
    return (((x)<(min))?(min):(((x)>(max))?(max):(x)));
}
TBlockIndex grid::BlockIndex(vector<TPrecisionInfo> positions){
    int ix=Range((positions[0]-XMIN)/sx,0,nx-1);
    int iy=Range((positions[1]-YMIN)/sy,0,ny-1);
    int iz=Range((positions[2]-ZMIN)/sz,0,nz-1);

    return ix+iy*nx+iz*(nx*ny);
}

void grid::calculateDistances(){

    for(size_t index=0; index< blocks.size(); index++){
        blocks[index].CalculateSelfDistances();
        chooseDirections( WhichDirections( static_cast<int>(index) ), index);
    }
}
int grid::WhichDirections(int index){
    bool xDir, yDir, zDir;
    /* We will treat every block as a corner, any block having to do at most 7 operations with its neighbors.
    We will calculate with the block on the xDirection if our x position is not an edge
        That is i%nx != nx-1 Because every k*(nx-1) mod nx is an edge by our indexing.
    Same for yDirection and zDirection. (the current code works thanks to integer division truncating results)
    Example nx=2 ny= 5. 2 Dimensions. Every second block will be an x edge, and blocks 8,9 will be y edges

    Finally, as we have to consider the 8 cases of output, we return a decimal base representation
    of our binary variables --> Zdir, Ydir, XDir e (000 --> 111)(binary)= (0-8)(decimal).
    This is to do avoid HUGE if else statement with a switch
     */
    (index % nx)!=(nx-1)?(xDir=true):xDir=false;
    (index/nx)%ny !=ny-1 ?(yDir=true):yDir=false;
    (index/(nx*ny))%nz != nz-1 ?(zDir=true):zDir=false;

    return 4*zDir+2*yDir+1*xDir;
}
void grid::chooseDirections(int choose, size_t index){
    switch(choose){
        case(7):
            XYZdir(index);
        break;
        case(6):
            YZdir(index);
        break;
        case(5):
            XZdir(index);
        break;
        case(4): //Only Z
            blocks[index].CalculateDistances(blocks[index+nx*ny]);
        break;
        case(3):
            XYdir(index);
        break;
        case(2): //Only Y
            blocks[index].CalculateDistances(blocks[index+nx]);
        break;
        case(1): //Only X
            blocks[index].CalculateDistances(blocks[index+1]);
        break;
        //Case 0 We do nothing
    }
}
void grid::XYZdir(size_t index){
    blocks[index].CalculateDistances(blocks[index+1]); //XDir
    blocks[index].CalculateDistances(blocks[index+nx]);//YDir
    blocks[index].CalculateDistances(blocks[index+nx+1]); //XYDir
    blocks[index].CalculateDistances(blocks[index+nx*ny]); //ZDir
    blocks[index].CalculateDistances(blocks[index+nx*ny+1]); //ZXDir
    blocks[index].CalculateDistances(blocks[index+nx*ny+nx]); //ZYDir
    blocks[index].CalculateDistances(blocks[index+nx*ny+nx+1]); //ZXY Dir
}
void grid::XYdir(size_t index){
    blocks[index].CalculateDistances(blocks[index+1]); //XDir
    blocks[index].CalculateDistances(blocks[index+nx]);//YDir
    blocks[index].CalculateDistances(blocks[index+nx+1]); //XYDir
}
void grid::XZdir(size_t index){
    blocks[index].CalculateDistances(blocks[index+1]); //XDir
    blocks[index].CalculateDistances(blocks[index+nx*ny]); //ZDir
    blocks[index].CalculateDistances(blocks[index+nx*ny+1]); //ZXDir
}
void grid::YZdir(size_t index){
    blocks[index].CalculateDistances(blocks[index+nx]);//YDir
    blocks[index].CalculateDistances(blocks[index+nx*ny]); //ZDir
    blocks[index].CalculateDistances(blocks[index+nx*ny+nx]); //ZYDir
}
void grid::ClearDistances(){
    for(auto i : blocks){
        i.ClearDistances();
    }
}