#include "progargs.hpp"

using namespace std;

bool isNumber(const char* str){
	for(int i=0; i< strlen( str ); i++){
		if(!isdigit(str[i])){
			return false;
		}
	}
	return true;
};

void pargs::writeOutput(ofstream& fout, float ppm, int np, particle* particles, size_t size){
	//  First we write the header ppm float, np int
	fout.write(reinterpret_cast<char*>( &ppm),sizeof( ppm));
	fout.write(reinterpret_cast<char*>( &np), sizeof( np));
	fout.write(reinterpret_cast<const char*>(particles), size * sizeof(particle));

	return;
};
void pargs::readInput(ifstream& fin, int& anp, float& appm, particle* ps){

	//We are first going to read and store Np, and then store an array of particles? 
	// Is it better to concatenate vectors and then write or a write per particle??
	int np;
	float ppm;
	fin.seekg(0, fin.end);
  	size_t fileSize = fin.tellg();
  	fin.seekg(0, fin.beg);
	const size_t count = (fileSize- sizeof(float)- sizeof(int))/sizeof(particle);

	fin.read(reinterpret_cast<char*>(&ppm),sizeof(float));
	fin.read(reinterpret_cast<char*>(&np), sizeof(int));

	fin.read(reinterpret_cast<char*>(ps), count*sizeof(particle));
	cout << np << endl;
	cout << ppm << endl;
	
}
int pargs::checkParams(int argc, char** argv) {
	if (argc != 4) {
		cout << "Error: Invalid number of arguments: "<< argc-1 << "\n";
		return -1;
	}
	if (!isNumber(argv[1])){
		cout << "Error: time steps must be numeric.\n";
		return -1;
	}
	if (argv[1][0]=='-'){
		cout << "Error: Invalid number of time steps.\n";
		return -2;
	}

	int np = atoi(argv[1]);
	ifstream fin;
	ofstream fout(argv[3], ios::binary);

	
	/* if (!fin) {
		cout <<"Error: Cannot open init.fld for reading\n";
		return -3;
	} */
/* 	fout.open("./IO/output.txt", ios::out | ios::binary);
	if(!fout){
		cout << "Error: Cannot open final.fld for writing\n";
		return -4;
	}
	else writeOutput( fout, 10.f, 10, {});
	fout.close();
 */
	// Check input file
	return 1;

}