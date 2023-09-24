#pragma once

#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

namespace pargs{
	int checkParams(int argc, char** argv);
	//void readInput(std::ifstream& input);
	void writeOutput(std::ofstream& output, float ppm, int np); // Also Data Structure for particles
};



