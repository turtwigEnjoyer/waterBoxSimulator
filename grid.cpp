#include "grid.h"

grid* grid::pSingleton;

grid::grid(){
    pSingleton=this;
}
grid::~grid(){}

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
    vector<block> blocks(nx*ny*nz);
    FillAdjacents();

    //Initialise important "constants"
    grid::H2= pow(h,2);
    grid::H6 = pow(h,6);
    PI_DIV15 = 15/(M_1_PI*H6);
    PI_DIV315 = (315*m)/(M_1_PI*pow(h,9)*64);
    PI_DIV45 = 3* PI_DIV15* (float)VISCOSITY *m;

}
TBlockIndex grid::PutInBlock(particle* pParticle){
    //This operation is going to happen a lot. Can we find a way to do it less?
    int index=BlockIndex(GET_PARTICLE(pParticle)->GetX(),
                        GET_PARTICLE(pParticle)->GetY(),
                        GET_PARTICLE(pParticle)->GetZ());
    blocks[index].PutIn(pParticle);
    return index;
}
void grid::Move(particle::PParticle pParticula, TBlockIndex indiceOrigen, TBlockIndex indiceDestino)
{
    blocks[indiceOrigen].PutOut(pParticula);
    blocks[indiceDestino].PutIn(pParticula);
}

int Range(int x,int min,int max)
{
    return (((x)<(min))?(min):(((x)>(max))?(max):(x)));
}
TBlockIndex grid::BlockIndex(TPrecisionInfo x, TPrecisionInfo y, TPrecisionInfo z){
    int ix=Range((x-XMIN)/sx,0,nx-1);
    int iy=Range((y-YMIN)/sy,0,ny-1);
    int iz=Range((z-ZMIN)/sz,0,nz-1);

    return ix+iy*nx+iz*(nx*ny);
}
void grid::FillAdjacents()
{
    for(size_t index=0;index<blocks.size();index++)
    {
        int x=index%nx;
        int y=index%(nx*ny);
        int z=index/(nx*ny);
        for(int kx=MAX(x-1,0);(kx<=(x+1)) && (kx<(nx-1));kx++)
        {
            for(int ky=MAX(y-1,0);(ky<=(y+1)) && (ky<(ny-1));ky++)
            {
                for(int kz=MAX(z-1,0);(kz<=(z+1)) && (kz<(nz-1));kz++)
                {
                    size_t adjacentIndex=kx+ky*nx+kz*(nx*ny);

                    if (adjacentIndex>index)
                    {
                        blocks[index].AddAdjacents(adjacentIndex);
                    }
                }
            }
        }
    }
}

void grid::CalculateDistances()
{
    particle::CleanDistances();
    for(auto it=blocks.begin();it!=blocks.end();it++)
    {
        it->CalculateDistances();
    }
}