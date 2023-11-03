#pragma once

#include "grid.h"

namespace pargs{
	int checkParams(int argc, char** argv, grid& space);
	//void readInput(std::ifstream& input);
	//void writeOutput(std::ofstream& output, float ppm, int np, particle* particle, size_t size); // Also Data Structure for particles
	void writeOutput(ofstream& output, grid& space);
	void readInput(char* fileDir, grid& space);
};



