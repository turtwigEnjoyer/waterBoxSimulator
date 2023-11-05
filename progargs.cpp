#include "headers/progargs.h"

using namespace std;

bool isNumber(const char* str){
	for(size_t i=0; i< strlen( str ); i++){
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

void pargs::writeOutput(ofstream& fout, grid& singletonGrid){
	TPrecisionInfo ppm = singletonGrid.GetPPM();
	int np = singletonGrid.countParticles();
	fout.write(reinterpret_cast<char*>(&ppm),sizeof( ppm));
	fout.write(reinterpret_cast<char*>( &np), sizeof( np));
}

void pargs::readInput(char* filename, grid& singletonGrid){

	//We are first going to read and store Np, and then store an array of particles? 
	// Is it better to concatenate vectors and then write or a write per particle??
	// Binary files are float, int , 9 float * number of particles.
	int np;
	ifstream fin;

	fin.open(filename, std::ios::binary | std::ios::in);
	if(!fin){
		throw (-3);
		return;
	}
	fin.seekg(0, fin.end);
  	size_t fileSize = fin.tellg();
  	fin.seekg(0, fin.beg);
	
	//Calculates particle count from total file size -header
	const int pCount = (fileSize- sizeof(float)- sizeof(int))/(sizeof(float)*9);
	
	//Initializes Grid, important constants
	singletonGrid.Load(fin); // reads ppm, intializes grid and blocks
	fin.read(reinterpret_cast<char*>(&np), sizeof(int));
    if (np != pCount){
		throw "Error: Number of particles mismatch. Header: "+ to_string(np)+ ", Found: " + to_string(pCount);
		return;
	}
	singletonGrid.printGridInfo(np);

    particle::Sload(fin, pCount);
}

int pargs::checkParams(int argc, char** argv, grid& pSingelton, ofstream& fout) {
 	if (argc != 4) {
		cout << "Error: Invalid number of arguments: "<< argc-1 << "\n";
		return -1;
 	}
	if (argv[1][0]=='-'){
		cout << "Error: Invalid number of time steps.\n";
		return -2;
	}
	if (!isNumber(argv[1])){
		cout << "Error: time steps must be numeric.\n";
		return -1;
	}

	// Input file
	try{
		readInput(argv[2], pSingelton);
	}catch(const char* headerMismatch){
		cout << headerMismatch << endl;
		return -5;
	}catch( int fileUnreachable){
		cout << "Error: Cannot open "<< argv[2] << " for reading\n";
		return -3;
	}

	ofstream fout;
 	/*fout.open(argv[3], std::ios::binary | std::ios::out);
	if(!fout){
		cout << "Error: Cannot open " << argv[3] << " for writing\n";
		return -4;
	} 
	return 1;

}