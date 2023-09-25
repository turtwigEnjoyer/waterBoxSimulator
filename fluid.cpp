/* DEADLINE OCTOBER 30TH !!  */


#include "progargs.hpp"

using namespace std;


int main(int argc, char** argv)
{
	input in;
	int out= pargs::checkParams(argc, argv, in);
	if(out<0) return out;


	//MISSING DATA TYPES FOR PARTICLE STORAGE
	//MISSING GRID AND BLOCK EMULATORS
	//MISSING FORMULAS
	
	return 0;
}