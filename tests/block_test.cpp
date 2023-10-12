#include <gtest/gtest.h>
#include "../block.h"
#include "../particle.h"


// Test the block class
TEST(BlockTest, BlockOperations) {
    // Create a block object
    block testBlock;

    // Create some particles or ParticlePos objects (assuming you have a way to create them)
    particle::PParticle particle1(0.1,1.0,0.2);
    //ParticlePos position1(3); ahora mismo no usamos

    // Push particles or positions to the block
    testBlock.PushBack(particle1);
    //testBlock.PushBack(position1); ahora mismo no usamos

    // Call CalculateDistances and CalculateSelfDistances (assuming these methods are defined)
    block otherBlock; // Create another block for testing distances
    testBlock.CalculateDistances(otherBlock);
    testBlock.CalculateSelfDistances();

    // Clear distances (the method is not defined yet)
    //testBlock.ClearDistances();

}

// Test pushing particles into the block
TEST(BlockTest, PushParticles) {
    // Create a block object
    block testBlock;

    // Create some particles
    particle::PParticle particle1(0.1,1.0,0.2);
    particle::PParticle particle2(1.0,0.5,0.2);
    particle::PParticle particle3(0.0,0.6,0.8);

    // Push particles into the block
    testBlock.PushBack(particle1);
    testBlock.PushBack(particle2);
    testBlock.PushBack(particle3);

    // Check if the block contains the expected number of particles
  //  EXPECT_EQ(testBlock.GetParticleCount(), 3); --> DOES NOT EXISTS ANY FUNCTION, SUCH AS GETPARTICLECOUNT
}

// Test clearing distances after calculations
TEST(BlockTest, ClearDistances) {
    // Create a block object
    block testBlock;

    // Create some particles
    particle::PParticle particle1(0.1,1,0.2);
    particle::PParticle particle2(1,0.5,0.2);;

    // Push particles into the block
    testBlock.PushBack(particle1);
    testBlock.PushBack(particle2);

    // Calculate distances (assuming these methods are defined)
    block otherBlock; // Create another block for testing distances
    testBlock.CalculateDistances(otherBlock);

    // Clear distances (the method is not defined yet)
    //testBlock.ClearDistances();

    /* Check if all particle distances are cleared --> CHECK BECAUSE THERE ARE SOME FUNCTION WHICH DOES NOT EXIST
    for (const auto& particle : testBlock.GetParticles()) {
        EXPECT_EQ(particle.GetDistances().size(), 0); //to verify that all particle distances within the block are cleared (have a size of 0)
    }*/
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


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}