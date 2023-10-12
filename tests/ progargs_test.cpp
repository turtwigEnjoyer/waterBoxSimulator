#include <gtest/gtest.h>
#include "progargs.h"



// Test isNumber function
TEST(ProgArgsTest, IsNumber) {
    EXPECT_TRUE(isNumber("12345"));//valee que no está definido el number
    EXPECT_TRUE(isNumber("-12345"));
    EXPECT_FALSE(isNumber("abc"));
    EXPECT_FALSE(isNumber("12a45"));
}

//Generate particles to test the functionality of ReadInput:
std::vector<particle> GenerateTestParticles() {
    std::vector<particle> particles;

    // Add test particles with specific data
    particle p1;
    p1.MoveTo(1.0, 2.0, 3.0);
    particles.push_back(p1);

    particle p2;
    p2.MoveTo(4.0, 5.0, 6.0);
    particles.push_back(p2);

    // Add more test particles as needed

    return particles;
}

// Test readInput function
TEST(ProgArgsTest, ReadInput) {
    grid singletonGrid;

    // Create a test binary input file with known content

    // Case 1: Valid input file
    char validFile[] = "valid_input.bin";
    EXPECT_NO_THROW(pargs::readInput(validFile, singletonGrid));

    // Case 2: Invalid input file (non-existent)
    char nonexistentFile[] = "nonexistent_input.bin";
    EXPECT_THROW(pargs::readInput(nonexistentFile, singletonGrid), int);

    // Case 3: Invalid input file (header mismatch)
    char mismatchFile[] = "mismatch_input.bin";
    // Create a test binary input file with a header mismatch
    EXPECT_THROW(pargs::readInput(mismatchFile, singletonGrid), const char*);
}

// Test writeOutput function
TEST(ProgArgsTest, WriteOutput) {
    // Create a test binary output file with known content

    // Assuming you have a way to generate particles for testing
    int np = 100;/* number of particles */
    std::vector<particle> particles = /* generate particles */;
    float ppm = 1.0; // Set an appropriate ppm value

    // Case 1: Valid output file
    char validOutput[] = "valid_output.bin";
    ofstream fout(validOutput, std::ios::binary | std::ios::out);
    EXPECT_NO_THROW(pargs::writeOutput(fout, ppm, np, particles, size));
    fout.close();

    // Add more cases as needed to test different scenarios
}

// Test checkParams function
TEST(ProgArgsTest, CheckParams) {
    grid singletonGrid;

    // Case 1: Invalid number of arguments
    std::vector<std::string> args1 = { "program_name" };
    EXPECT_EQ(pargs::checkParams(args1, singletonGrid), -1);

    // Case 2: Invalid time steps (not numeric)
    std::vector<std::string> args2 = { "program_name", "abc", "input_file" };
    EXPECT_EQ(pargs::checkParams(args2, singletonGrid), -1);

    // Case 3: Invalid time steps (negative)
    std::vector<std::string> args3 = { "program_name", "-5", "input_file" };
    EXPECT_EQ(pargs::checkParams(args3, singletonGrid), -2);

    // Add more cases as needed to test different scenarios

    // Case 4: Valid arguments
    std::vector<std::string> args4 = { "program_name", "10", "input_file" };
    EXPECT_EQ(pargs::checkParams(args4, singletonGrid), 1);
}