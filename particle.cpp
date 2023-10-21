#include "headers/particle.h"
#include "headers/grid.h"

particle::TId particle::lastId=0;
int particle::sParticles=0;

particle::particle(float p[]){
    px= p[0];
    py = p[1];
    pz = p[2];

    vx = p[3];
    vy = p[4];
    vz = p[5];

    hvx = p[6];
    hvy = p[7];
    hvz = p[8];
    density=0;

    id=lastId;
    lastId++;

}
particle::particle(float x, float y, float z){ // For easier testing for Sandra
    px= x;
    py= y;
    pz= z;
}
particle::~particle(){
    
}

void particle::Sload(ifstream& fin, int pCount){
	
	float p[9];  //create an space of 9 to define the body of each particle
	//Particles are read, intiliased and stored in a vector
	for (int i = 0; i< pCount; i++){
        if (i== pCount-1){
            i++;
            i--;
        }
		fin.read(reinterpret_cast<char*>(p), 9* sizeof(float));
        //int blocksIndex= GRID.PutInBlock(ParticlePos(p));
        
        GRID.PutInBlock(particle(p)); 
	}
}


/* void particle::MoveTo(TPrecisionInfo x, TPrecisionInfo y, TPrecisionInfo z)
{
    TBlockIndex newIndex=GRID.BlockIndex(x,y,z);
    px=x;
    py=y;
    pz=z;
    if (blockIndex!=newIndex)
    {
#ifdef PARTICULA_POR_IDENTIFICADOR
        GRID.Mover(id,blockIndex,newIndex);
#else
        GRID.Move(this,blockIndex,newIndex);
#endif
        blockIndex=newIndex;
    }
} */

/* void particle::Reposition()
{
    ax=INIT_GX;
    ay=INIT_GY;
    az=INIT_GZ;
}
 */
TPrecisionInfo particle::CalculateDistance(PParticle other)
{
    TPrecisionInfo dx=(px-other.GetX())*(px-other.GetX());
    TPrecisionInfo dy= pow(py-other.GetY(),2);
    TPrecisionInfo dz = pow(pz-other.GetZ(),2);
    return DensityIncrease(dx+dy+dz);

}

/*void particle::ClearDistances()
{
    distances.clear();
} */
TPrecisionInfo particle::DensityIncrease( TPrecisionInfo distance){
    if( distance < GRID.H2){
        return ( pow(GRID.H2-distance,3));
    }
    return 0;
}
void particle::DensityTransformation(){
    density = (density +GRID.H6)*GRID.PI_DIV315;
}

//Getters and Setters
TPrecisionInfo particle::GetX() const{
    return px;
}
TPrecisionInfo particle::GetY() const{
    return py;
}
TPrecisionInfo particle::GetZ() const{
    return pz;
}
particle::TId particle::GetId() const{
    return id;
}
TPrecisionInfo particle::GetDensity() const{
    return density;
}
TPrecisionInfo particle::GetAX() const{//Getters of accelerations
    return ax;
}
TPrecisionInfo particle::GetAY() const{
    return ay;
}
TPrecisionInfo particle::GetAZ() const{
    return az;
}


//particles's Functions
void particle::AddDensity(TPrecisionInfo increase){
    density= density +increase;
}
void particle::ClearDensity(){
    density= 0;
}
void particle::CalculateAccelerations(particle& other){
    //NOt funtional yet
    other.ax++;
}

//Funtions of Collisions Blocks
void particle::CalculateCollisionsXP(){
    px = px + hvx*T_STEP;
    //cout << "Position px: " << px << endl;
    double difx = fabs(P_SIZE-(px-XMIN));//applied the absolute value so the difference is not negative
    //cout << "Diference position x: " << difx << endl;
    if(difx > (1e-10)){
       //cout << "Difference is greater. Position upload: " << px << endl;
       ax = ax + ((STIFF_COLL*difx)-(DAMPING*vx)); 
    }
    else{
        cout <<"Particles position does not uploaded" << endl;
    }   
}
void particle::CalculateCollisionsXN(){
    px= px + hvx*T_STEP;
    double difx = fabs(P_SIZE-(XMAX-px));
    if(difx > (1e-10)){
        ax = ax - ((STIFF_COLL*difx)+(DAMPING*vx));
    }
}
void particle::CalculateCollisionsYP(){
    py = py + hvy*T_STEP;
    double dify = fabs(P_SIZE-(py-YMIN));
    if(dify > (1e-10)){
        ay = ay + ((STIFF_COLL*dify)-(DAMPING*vy));
    }  
}
void particle::CalculateCollisionsYN(){
    py= py + hvy*T_STEP;
    double dify = fabs(P_SIZE-(YMAX-px));
    if(dify > (1e-10)){
        ay = ay - ((STIFF_COLL*dify)+(DAMPING*vy));
    }
}
void particle::CalculateCollisionsZP(){
    pz= pz+ hvz*T_STEP;
    double difz = fabs(P_SIZE-(px-ZMIN));
    if(difz > (1e-10)){
        az = az + ((STIFF_COLL*difz)-(DAMPING*vz));
    } 
}
void particle::CalculateCollisionsZN(){
    pz= pz+ hvz*T_STEP;
    double difz = fabs(P_SIZE-(ZMAX-pz));
    if(difz > (1e-10)){
        az = az - ((STIFF_COLL*difz)+(DAMPING*vz));
    }
}

//Particles motion
void particle::CalculateParticlesMotionPar(){
    px = px + hvx*T_STEP + ax*(T_STEP*T_STEP);
    py = py + hvy*T_STEP + ay*(T_STEP*T_STEP);
    pz = pz + hvz*T_STEP + az*(T_STEP*T_STEP);
    vx = hvx +((ax*T_STEP)/2);
    vy = hvy +((ay*T_STEP)/2);
    vz = hvz +((az*T_STEP)/2);
    hvx = hvx + ax*T_STEP;
    hvy = hvy + ay*T_STEP;
    hvz = hvz + az*T_STEP;
}

//Boundarie´s functions for particles
void particle::CalculateBoundariesParXP(){
    double difx = px - XMIN;
    if(difx < 0){
        px = XMIN - difx;
        vx = -vx;
        hvx = -hvx;
    }
}
void particle::CalculateBoundariesParXN(){
    double difx = XMAX - px;
    if(difx < 0){
        px = XMAX + difx;
        vx = -vx;
        hvx = -hvx;        
    }
}
void particle::CalculateBoundariesParYP(){
    double dify = py - YMIN;
    if(dify < 0){
        py = YMIN - dify;
        vy = -vy;
        hvy = -hvy;
    }
}
void particle::CalculateBoundariesParYN(){
    double dify = YMAX - py;
    if(dify < 0){
        py = YMAX + dify;
        vy = -vy;
        hvy = -hvy;
    }
}
void particle::CalculateBoundariesParZP(){
    double difz = pz - ZMIN;
    if(difz < 0){
        pz = ZMIN - difz;
        vz = -vz;
        hvz = -hvz;
    }
}
void particle::CalculateBoundariesParZN(){
    double difz = ZMAX - pz;
    if(difz < 0){
        pz = ZMAX + difz;
        vz = -vz;
        hvz = -hvz;
    }
}