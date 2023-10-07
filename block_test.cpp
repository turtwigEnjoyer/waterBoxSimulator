#include <gtest/gtest.h>
#include "block.h"
#include "particle.h"

//To apply the following tests we have to create several particles:
// Create particle instances with valid data --> necesitamos crear 3 particulas para los siguientes tests

/*float particleData[9] = {0.1f, 0.2f, 0.3f, 1.0f, 2.0f, 3.0f, 0.01f, 0.02f, 0.03f};
particle particle1(particleData);

particle particle1({0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
particle particle2({1.0f, 1.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f});
particle particle3({2.0f, 2.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f});*/

// Test the block class
TEST(BlockTest, BlockOperations) {
    // Create a block object
    block testBlock;

    // Create some particles or ParticlePos objects (assuming you have a way to create them)
    particle::PParticle particle1;
    ParticlePos position1;

    // Push particles or positions to the block
    testBlock.PushBack(particle1);
    testBlock.PushBack(position1);

    // Call CalculateDistances and CalculateSelfDistances (assuming these methods are defined)
    block otherBlock; // Create another block for testing distances
    testBlock.CalculateDistances(otherBlock);
    testBlock.CalculateSelfDistances();

    // Clear distances (assuming the method is defined)
    testBlock.ClearDistances();

}

// Test pushing particles into the block
TEST(BlockTest, PushParticles) {
    // Create a block object
    block testBlock;

    // Create some particles
    particle::PParticle particle1;
    particle::PParticle particle2;
    particle::PParticle particle3;

    // Push particles into the block
    testBlock.PushBack(particle1);
    testBlock.PushBack(particle2);
    testBlock.PushBack(particle3);

    // Check if the block contains the expected number of particles
    EXPECT_EQ(testBlock.GetParticleCount(), 3);
}

// Test clearing distances after calculations
TEST(BlockTest, ClearDistances) {
    // Create a block object
    block testBlock;

    // Create some particles
    particle::PParticle particle1;
    particle::PParticle particle2;

    // Push particles into the block
    testBlock.PushBack(particle1);
    testBlock.PushBack(particle2);

    // Calculate distances (assuming these methods are defined)
    block otherBlock; // Create another block for testing distances
    testBlock.CalculateDistances(otherBlock);

    // Clear distances
    testBlock.ClearDistances();

    // Check if all particle distances are cleared
    for (const auto& particle : testBlock.GetParticles()) {
        EXPECT_EQ(particle.GetDistances().size(), 0); //to verify that all particle distances within the block are cleared (have a size of 0)
    }
}