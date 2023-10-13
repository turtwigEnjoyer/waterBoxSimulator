#include "headers/grid.h"

grid* grid::pSingleton;

grid::grid(){
    pSingleton=this;
}
grid::~grid(){

}
void grid::initializeBlocks(){
    for(size_t index= 0; index<blocks.size();index++){
        blocks[index].amIEdge(index,nx,ny,nz);
        direction(index);
    }
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

    //Initialise important "constants"
    grid::H2= pow(h,2);
    grid::H6 = pow(h,6);
    PI_DIV315 = (315*m)/(M_1_PI*pow(h,9)*64);
    PI_DIV45 = 45*VISCOSITY*m/(M_PI*H6);
    PI_DIV15 = PI_DIV45/2;

}
void grid::printGridInfo(int numberParticles){
    cout << "Number of particles: " << numberParticles << "\n";
    cout << "Particles per meter: " << ppm << "\n";
    cout << "Smoothing length: " << h << "\n";
    cout << "Particle mass: " << m << "\n";
    cout << "Grid size: " << nx << " x " << ny << " x " << nz <<"\n";
    cout << "Number of blocks: " << nx*ny*nz << "\n" ;
    cout << "Block size: " << sx << " x " << sy << " x " << sz << "\n";
}
void grid::PutInBlock(particle::PParticle particle, int whichBlock){
    blocks[whichBlock].PushBack(particle);
}
void grid::PutInBlock(particle::PParticle particle){
    int index=BlockIndex(particle.GetX(),particle.GetY(),particle.GetZ());
    blocks[index].PushBack(particle);
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
TBlockIndex grid::BlockIndex(TPrecisionInfo px,TPrecisionInfo py,TPrecisionInfo pz ){
    int ix=Range((px-XMIN)/sx,0,nx-1);
    int iy=Range((py-YMIN)/sy,0,ny-1);
    int iz=Range((pz-ZMIN)/sz,0,nz-1);

    return ix+iy*nx+iz*(nx*ny);
}
void grid::DensityIncrease(){

    for(size_t index=0; index< blocks.size(); index++){
        blocks[index].CalculateSelfDistances(); //Good
        for(int i: blocks[index].adjacents){ //integer vector of all adjacent indexes
            blocks[index].CalculateDistances(blocks[i]);
        }
    }
}
void grid::AccelerationTransfer(){
    for (size_t index =0; index< blocks.size(); index++){
        blocks[index].CalculateSelfAccelerations();
        for(int i: blocks[index].adjacents){
            blocks[index].CalculateAccelerations(blocks[i]);
        }
    }
}
/*  Fallen out of Use. Dont delete just in case
int grid::WhichDirections(int index){
    bool xRightEdge, yRightEdge, zRightEdge;
    bool xLeftEdge, yLeftEdge, zLeftEdge;
     We will treat every block as a corner, any block having to do at most 7 operations with its neighbors.
    We will calculate with the block on the xDirection if our x position is not an edge
        That is i%nx != nx-1 Because every k*(nx-1) mod nx is an edge by our indexing.
    Same for yDirection and zDirection. (the current code works thanks to integer division truncating results)
    Example nx=2 ny= 5. 2 Dimensions. Every second block will be an x edge, and blocks 8,9 will be y edges

    We return a tertiary base representation of this boolean. 2= Right Edge 1=Left Edge 0=No edge
    This is to do avoid HUGE if else statement with a switch
     
    (index % nx)==(nx-1)?(xRightEdge=true):xRightEdge=false;
    (index/nx)%ny ==ny-1 ?(yRightEdge=true):yRightEdge=false;
    (index/(nx*ny))%nz == nz-1 ?(zRightEdge=true):zRightEdge=false;

    (index % nx)==(0)?(xLeftEdge=true):xLeftEdge=false;
    (index/nx)%ny ==0 ?(yLeftEdge=true):yLeftEdge=false;
    (index/(nx*ny))%nz == 0 ?(zLeftEdge=true):zLeftEdge=false;

    int ret = 4*(int)zRightEdge+2*(int)yRightEdge+1*(int)xRightEdge;
    return ret;
}*/
/*
void grid::chooseDirections(int choose, size_t index){
    switch(choose){
        case(0):
            XYZdir(index);
        break;
        case(1):
            YZdir(index);
        break;
        case(2):
            XZdir(index);
        break;
        case(3): //Only Z
            blocks[index].CalculateDistances(blocks[index+nx*ny]);
        break;
        case(4):
            XYdir(index);
        break;
        case(5): //Only Y
            blocks[index].CalculateDistances(blocks[index+nx]);
        break;
        case(6): //Only X
            blocks[index].CalculateDistances(blocks[index+1]);
        break;
        //Case 7 We do nothing
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
 */
void grid::ClearDensities(){
    for(auto i : blocks){
        i.ClearDensities();
    }
}
void grid::DensityTransformations(){
    for(auto i: blocks){
        i.DensityTransformations();
    }
}


//Este codigo es lo mas feo que he escrito en mi vida -Nora
//Basicamente determina en que direccion calculamos las distancias
//Como regla para no calcular dos veces siempre calculamos con indices de blocks mayores al nuestro
//Es TAN largo y feo xq las direcciones cambian segun si no somos, o somos borde positivo o negativo de X,Y,Z
//Se reduce a 16 casos (Creo (Revisar luego)), Esta bien hecho asi que no tocar porfi
//P.D. Sandra no hacen falta tests
void grid::direction(size_t index){
    dirZedge(index);
    if(blocks[index].zPosEdge){
        return;
    }
    else{
        int rep= 1*blocks[index].xPosEdge+2*blocks[index].xNegEdge+3*blocks[index].yPosEdge+6*blocks[index].yNegEdge;
        dirZFree(rep, index );
    }
}
void grid::dirZedge(size_t index){
    if(blocks[index].yPosEdge){
        if(blocks[index].xPosEdge){
            blocks[index].PushBackAdjacents(index+1);
        }
    }else{
        blocks[index].PushBackAdjacents(index+nx);
        if(blocks[index].xPosEdge){
            blocks[index].PushBackAdjacents(index+nx);
            blocks[index].PushBackAdjacents(index+nx-1);
        }
        else if(blocks[index].xNegEdge){
            blocks[index].PushBackAdjacents(index+1);
            blocks[index].PushBackAdjacents(index+nx+1);

        }else{
            blocks[index].PushBackAdjacents(index+1);
            blocks[index].PushBackAdjacents(index+nx-1);
            blocks[index].PushBackAdjacents(index+nx+1);
        }
    }
}
void grid::dirZFree(int rep, size_t index){
    switch(rep){
        case(0): Alldir( index);
        break;
        case(1): XP( index);
        break;
        case(2): XN( index);
        break;
        case(3): YP( index);
        break;
        case(4): XPYP( index);
        break;
        case(5): XNYP( index);
        break;
        case(6): YN( index);
        break;
        case(7): XPYN( index);
        break;
        case(8): XPYP( index);
        break;
    }
}
void grid::Alldir(size_t index){
    blocks[index].PushBackAdjacents(index+ny*nx -nx -1);
    blocks[index].PushBackAdjacents(index+ny*nx -nx);
    blocks[index].PushBackAdjacents(index+ny*nx -nx +1);

    blocks[index].PushBackAdjacents(index+ny*nx -1);
    blocks[index].PushBackAdjacents(index+ny*nx);
    blocks[index].PushBackAdjacents(index+ny*nx +1);

    blocks[index].PushBackAdjacents(index+ny*nx +nx -1);
    blocks[index].PushBackAdjacents(index+ny*nx +nx);
    blocks[index].PushBackAdjacents(index+ny*nx +nx +1);
}
void grid::XPYP(size_t index){
    blocks[index].PushBackAdjacents(index+ny*nx -nx -1);
    blocks[index].PushBackAdjacents(index+ny*nx -nx);

    blocks[index].PushBackAdjacents(index+ny*nx -1);
    blocks[index].PushBackAdjacents(index+ny*nx);

}
void grid::XPYN(size_t index){
    blocks[index].PushBackAdjacents(index+ny*nx);
    blocks[index].PushBackAdjacents(index+ny*nx +1);  
    blocks[index].PushBackAdjacents(index+ny*nx +nx);
    blocks[index].PushBackAdjacents(index+ny*nx +nx +1);

}
void grid::XP(size_t index){
    blocks[index].PushBackAdjacents(index+ny*nx -nx -1);
    blocks[index].PushBackAdjacents(index+ny*nx -nx);

    blocks[index].PushBackAdjacents(index+ny*nx -1);
    blocks[index].PushBackAdjacents(index+ny*nx);

    blocks[index].PushBackAdjacents(index+ny*nx +nx -1);
    blocks[index].PushBackAdjacents(index+ny*nx +nx);
}
void grid::XNYP(size_t index){
    blocks[index].PushBackAdjacents(index+ny*nx -nx);
    blocks[index].PushBackAdjacents(index+ny*nx -nx +1);

    blocks[index].PushBackAdjacents(index+ny*nx);
    blocks[index].PushBackAdjacents(index+ny*nx +1);

}
void grid::XNYN(size_t index){

    blocks[index].PushBackAdjacents(index+ny*nx);
    blocks[index].PushBackAdjacents(index+ny*nx +1);

    blocks[index].PushBackAdjacents(index+ny*nx +nx);
    blocks[index].PushBackAdjacents(index+ny*nx +nx +1);
}
void grid::XN(size_t index){
    blocks[index].PushBackAdjacents(index+ny*nx -nx);
    blocks[index].PushBackAdjacents(index+ny*nx -nx +1);

    blocks[index].PushBackAdjacents(index+ny*nx);
    blocks[index].PushBackAdjacents(index+ny*nx +1);

    blocks[index].PushBackAdjacents(index+ny*nx +nx);
    blocks[index].PushBackAdjacents(index+ny*nx +nx +1);
}
void grid::YP(size_t index){
    blocks[index].PushBackAdjacents(index+ny*nx -nx -1);
    blocks[index].PushBackAdjacents(index+ny*nx -nx);
    blocks[index].PushBackAdjacents(index+ny*nx -nx +1);

    blocks[index].PushBackAdjacents(index+ny*nx -1);
    blocks[index].PushBackAdjacents(index+ny*nx);
    blocks[index].PushBackAdjacents(index+ny*nx +1);

}
void grid::YN(size_t index){
    blocks[index].PushBackAdjacents(index+ny*nx -1);
    blocks[index].PushBackAdjacents(index+ny*nx);
    blocks[index].PushBackAdjacents(index+ny*nx +1);

    blocks[index].PushBackAdjacents(index+ny*nx +nx -1);
    blocks[index].PushBackAdjacents(index+ny*nx +nx);
    blocks[index].PushBackAdjacents(index+ny*nx +nx +1);
}

