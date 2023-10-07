#include <gtest/gtest.h>
#include "grid.h"
#include "block.h"
#include "particle.h" // Include particle class or appropriate headers

// Test the grid class
TEST(GridTest, GridOperations) {
    // Create a grid object
    grid testGrid;

    // Load grid data from a file (assuming you have a test input file)
    std::ifstream inputFile("test_input_file.txt");
    EXPECT_NO_THROW(testGrid.Load(inputFile));
    inputFile.close();

    // Create a test particle (assuming you have a way to create particles)
    particle testParticle;
    // Set the position of the test particle (assuming you have a way to do this)
    testParticle.MoveTo(1.0, 2.0, 3.0);

    // Put the test particle in a specific block (assuming you have a way to do this)
    int blockIndex = 5;/*It`s an example, specify the block index */
    testGrid.PutInBlock(testParticle, blockIndex);

    // Calculate distances within the grid
    testGrid.calculateDistances();

    // Clear distances
    testGrid.ClearDistances();

    // Determine the block index for a set of particle positions (assuming you have positions)
    std::vector<TPrecisionInfo> particlePositions = /* specify particle positions */;
    TBlockIndex index = testGrid.BlockIndex(particlePositions);
    EXPECT_GE(index, 0); // Ensure a valid block index

    // Add more test cases for other grid operations as needed
}

//OTHER TEST WHICH MIX BLOCK AND GRID CLASSES
TEST(GridTest, BlockIndex) {
    grid myGrid;

    // Test BlockIndex function
    TPrecisionInfo x = 2.5; /* set a valid x-coordinate */
    TPrecisionInfo y = 3.0; /* set a valid y-coordinate */
    TPrecisionInfo z = 1.8; /* set a valid z-coordinate */

    // Assuming valid values for sx, sy, sz, nx, ny, and nz are set in myGrid
    TBlockIndex index = myGrid.BlockIndex(x, y, z);

    // Define your expectations based on your implementation
    EXPECT_EQ(index, /* Expected block index for (x, y, z) */); //maybe we need to change the order
    EXPECT_TRUE(/* Check if the particle is in the correct block */);
}

//THIS ARE ANOTHER TESTS FOR GRID:
TEST(GridTest, Move) {
    grid myGrid;
    TPrecisionInfo x1 = /* set a valid x-coordinate for particle 1 */;
    TPrecisionInfo y1 = /* set a valid y-coordinate for particle 1 */;
    TPrecisionInfo z1 = /* set a valid z-coordinate for particle 1 */;
    TPrecisionInfo x2 = /* set a valid x-coordinate for particle 2 */;
    TPrecisionInfo y2 = /* set a valid y-coordinate for particle 2 */;
    TPrecisionInfo z2 = /* set a valid z-coordinate for particle 2 */;
    particle* pParticle1 = /* create particle 1 */;
    particle* pParticle2 = /* create particle 2 */;
    TBlockIndex index1 = myGrid.PutInBlock(pParticle1);
    TBlockIndex index2 = myGrid.PutInBlock(pParticle2);

    // Test Move function
    myGrid.Move(pParticle1, index1, index2);

    // Define your expectations based on your implementation
    // Check if the particles have been moved to the correct blocks.
    EXPECT_TRUE(/* Check if particle 1 is in the correct block */);
    EXPECT_TRUE(/* Check if particle 2 is in the correct block */);
}

TEST(GridTest, FillAdjacents) {
    grid myGrid;
    
    // Test FillAdjacents function
    myGrid.FillAdjacents();

    // Define your expectations based on your implementation
    // Check if the adjacents have been filled correctly for each block.
    // You might want to check specific adjacent lists for known block indices.
    EXPECT_TRUE(/* Check if adjacents for a specific block are as expected */);
}

TEST(GridTest, CalculateDistances) {
    grid myGrid;
    
    // Test CalculateDistances function
    myGrid.CalculateDistances();

    // Define your expectations based on your implementation
    // Check if the distances have been calculated correctly for the particles in each block.
    EXPECT_TRUE(/* Check if distances are as expected for particles in a specific block */);
}





