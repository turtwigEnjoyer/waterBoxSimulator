#pragma once

#include "particle.hpp"

namespace pargs{
	int checkParams(int argc, char** argv);
	//void readInput(std::ifstream& input);
	void writeOutput(std::ofstream& output, float ppm, int np, particle* particle, size_t size); // Also Data Structure for particles
	void readInput(std::ifstream& fin, int& np, float& ppm, particle* ps);
};



