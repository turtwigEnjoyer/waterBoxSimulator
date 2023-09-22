#include <iostream>
#include "hello.hpp"
#include "progargs.hpp"

using namespace std;

int main(int argc, char** argv)
{
	int out= pargs::checkParams(argc, argv);
	if(out<0) return out;

	//MISSING DATA TYPES FOR PARTICLE STORAGE
	//MISSING GRID AND BLOCK EMULATORS
	//MISSING FORMULAS




	return 0;
}