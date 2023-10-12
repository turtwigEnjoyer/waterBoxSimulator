#include <iostream>
#include "block.h"
#include "particle.h"
#include "ParticlePos.h"


block::block(){
}

block::~block(){
}
size_t GetParticlesSize(){
    return particles.size();
}
particle::PParticle GetParticleAtIndex(size_t index){
    if (index < particles.size()) {
        return particles[index];
    } else {
       throw std::out_of_range("Index out of range of particles.");
    }
}

void block::PushBack(particle::PParticle pParticle){
    
    particles.push_back(pParticle);
}
void block::PushBack(ParticlePos pos)
{
    pos.setOwner(positions.size());
    positions.push_back(pos);
}

//Here we include some unitary tests for the upper functions:

void testPushBackParticle() {
    block myBlock; // Crea un objeto de la clase block

    particle::PParticle particle(0.5,0.1,0.2); //Create a particle
    myBlock.PushBack(particle); // Agrega la partícula al bloque

    // Verifica si la partícula se ha agregado correctamente
    if (myBlock.particles.size() == 1) {
        std::cout << "Test PushBackParticle: PASSED" << std::endl;
    } else {
        std::cout << "Test PushBackParticle: FAILED" << std::endl;
    }
}

// Función para probar PushBack con posiciones
void testPushBackPosition() {
    block myBlock; 

    float pos[3] = {1.0, 2.0, 3.0}; //initialized a vector pos which contains the informartion to testPos
    ParticlePos testPos(pos); // Crea una posición de prueba
    myBlock.PushBack(testPos); // Agrega la posición al bloque

    bool testPassed = false;  // Inicializa una variable para el resultado de la prueba

    for (size_t i = 0; i < myBlock.positions.size(); i++){
        if (pos == testPos) {
            testPassed = true;  // Se encontró testPos en el vector
            break;  // Puedes salir del bucle si la encontraste
        }
}

    if (testPassed) {
        std::cout << "Test PushBackPosition: PASSED" << std::endl;
    } else {
        std::cout << "Test PushBackPosition: FAILED" << std::endl;
    }
}



/* void block::PutOut(particle::PParticle pParticle)
{
    positions.erase(find(positions.begin(),positions.end(),pParticle));
} */

/*
When ParticlePos is used
 void block::CalculateDistances(block& other){
    for(auto it= positions.begin();it!=positions.end();it++){
        for(auto jt=other.positions.begin();jt!=other.positions.end();jt++){
            TPrecisionInfo distance = it->CalculateDistance(*jt);
            particles[it->ownerId].distances.push_back(distance);
            other.particles[jt->ownerId].distances.push_back(distance);
        }
    }
}
void block::CalculateSelfDistances(){
    for(auto it =positions.begin(); it!=positions.end();it++){
        auto jt=it;
        jt++;
        for(;jt!= positions.end(); jt++){
            TPrecisionInfo distance= it->CalculateDistance(*jt);
            particles[it->ownerId].distances.push_back(distance);
            particles[jt->ownerId].distances.push_back(distance);
        }
    }
}
*/
void block::CalculateDistances(block& other){
    /* for(auto it= particles.begin();it!=particles.end();it++){
        for(auto jt=other.particles.begin();jt!=other.particles.end();jt++){
            it->CalculateDistance(*jt);
        }
    } */
    for(size_t i= 0; i< particles.size(); i++){
        for (size_t j= 0; j<other.particles.size();j++){
            particles[i].CalculateDistance(other.particles[j]);
        }
    }
}
void block::CalculateSelfDistances(){
    for(auto it =particles.begin(); it!=particles.end();it++){
        auto jt=it;
        jt++;
        for(;jt!= particles.end(); jt++){
            it->CalculateDistance(*jt);
        }
    }
}
void block::ClearDensities(){
    for(auto i: particles){
        //i.ClearDistances();
        i.ClearDensity();
    }
}
void block::DensityTransformations(){
    for(auto i: particles){
        i.DensityTransformation();
    }
}

// The following tests prove the functionality of the diferent distances and densities:
void testCalculateDistances() {
    block myBlock1;
    block myBlock2;
 
    particle::PParticle particle1(0.5, 0.1, 0.2);
    myBlock1.PushBack(particle1); // Agrega una partícula al primer bloque

    particle::PParticle particle2(1.0, 0.7, 0.3);
    myBlock2.PushBack(particle2); // Agrega una partícula al segundo bloque


    // Realiza el cálculo de distancias entre los dos bloques
    myBlock1.CalculateDistances(myBlock2);

    // Agrega aquí aserciones para verificar si el cálculo fue exitoso
}

// Función para probar CalculateSelfDistances
void testCalculateSelfDistances() {
    block myBlock;

    // Agrega algunas partículas al bloque

    // Realiza el cálculo de distancias dentro del mismo bloque
    myBlock.CalculateSelfDistances();

    // Agrega aquí aserciones para verificar si el cálculo fue exitoso
}

// Función para probar ClearDensities
void testClearDensities() {
    block myBlock;

    // Agrega algunas partículas al bloque

    // Llama a la función para limpiar densidades
    myBlock.ClearDensities();

    // Agrega aquí aserciones para verificar que las densidades se hayan limpiado correctamente
}

// Función para probar DensityTransformations
void testDensityTransformations() {
    block myBlock;

    // Agrega algunas partículas al bloque

    // Llama a la función para realizar transformaciones de densidad
    myBlock.DensityTransformations();

    // Agrega aquí aserciones para verificar si las transformaciones se realizaron correctamente
}

/*  void block::amIEdge(int index){
        
    We will only calculate distances with forward blocks, assuming all backwards have been executed.
    We will calculate with the block on the xDirection if our x position is an edge
    That is i%nx == nx-1 Because every k*(nx-1) mod nx is an edge by our indexing. (Rightmost edge)
    Same for yDirection and zDirection. (the current code works thanks to integer division truncating results)
    Example nx=2 ny= 5. 2 Dimensions. Every second block will be an xRIghtEdge and blocks 8,9 will be yRightEdges
    
    (index % nx)==(nx-1)?(xRightEdge=true):xRightEdge=false;
    (index/nx)%ny ==ny-1 ?(yRightEdge=true):yRightEdge=false;
    (index/(nx*ny))%nz == nz-1 ?(zRightEdge=true):zRightEdge=false;

    (index % nx)==(0)?(xRightEdge=true):xRightEdge=false;
    (index/nx)%ny ==0 ?(yRightEdge=true):yRightEdge=false;
    (index/(nx*ny))%nz == 0 ?(zRightEdge=true):zRightEdge=false;
} 
 */

int main() {
    
    // Execute the main test, so we can see the result
    testPushBackParticle();
    testPushBackPosition();
    testCalculateDistances();
    testCalculateSelfDistances();
    testClearDensities();
    testDensityTransformations();

    return 0;
}