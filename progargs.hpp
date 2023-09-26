#pragma once

#include "particle.hpp"
#include <vector>
namespace pargs{
	int checkParams(int argc, char** argv, input& in);
	//void readInput(std::ifstream& input);
	void writeOutput(std::ofstream& output, float ppm, int np, particle* particle, size_t size); // Also Data Structure for particles
	void readInput(char* fileDir, input& in);
};



