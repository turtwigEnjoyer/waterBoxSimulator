/* DEADLINE OCTOBER 30TH !!  */


#include "progargs.hpp"

using namespace std;


int main(int argc, char** argv)
{
/* int out= pargs::checkParams(argc, argv);
	if(out<0) return out; */
	
	particle a(1,1,1,2,2,2,3,3,3);
	particle ps[] = {a,a,a};
	vector<particle> Input = {};
	int np;
	float ppm;


 	ofstream fout;
	fout.open("../fout.bin", ios::binary | ios::out);
	pargs::writeOutput(fout, 10.0f, 11, ps, sizeof(ps));
	fout.close(); 

 	ifstream fin;
	fin.open("../small.fld", ios::binary | ios::in);
	pargs::readInput(fin, np, ppm, Input);
	for( auto it = Input.begin(); it != Input.end(); it++){
		printParticle(*it);
	}
	fin.close();

/* 	fin.seekg(0, fin.end);
  	size_t fileSize = fin.tellg();
  	fin.seekg(0, fin.beg);
	char buffer[fileSize];
	fin.read(buffer, fileSize); */


	//MISSING DATA TYPES FOR PARTICLE STORAGE
	//MISSING GRID AND BLOCK EMULATORS
	//MISSING FORMULAS
	
	return 0;
}