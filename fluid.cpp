#include <iostream>
#include "progargs.hpp"

using namespace std;

int main(int argc, char** argv)
{
	/* int out= pargs::checkParams(argc, argv);
	if(out<0) return out; */
	ofstream fout;
	fout.open("../file.dat", ios::binary | ios::out);
	pargs::writeOutput(fout, 10.0f, 10);
	fout.close();

	//MISSING DATA TYPES FOR PARTICLE STORAGE
	//MISSING GRID AND BLOCK EMULATORS
	//MISSING FORMULAS
	
	return 0;
}