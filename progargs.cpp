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
void pargs::readInput(char* fLocation, input& in){

	//We are first going to read and store Np, and then store an array of particles? 
	// Is it better to concatenate vectors and then write or a write per particle??
	// Binary files are float, int , 9 float * number of particles.

	ifstream fin;

	fin.open(fLocation, std::ios::binary | std::ios::in);
	if(!fin){
		throw (-3);
		return;
	}
	fin.seekg(0, fin.end);
  	size_t fileSize = fin.tellg();
  	fin.seekg(0, fin.beg);
	//Calculates particle count from total file size -header
	const int pCount = (fileSize- sizeof(float)- sizeof(int))/(sizeof(float)*9);

	fin.read(reinterpret_cast<char*>(&in.ppm),sizeof(float));
	fin.read(reinterpret_cast<char*>(&in.np), sizeof(int));
	
	if (in.np != pCount){
		throw "Error: Number of particles mismatch. Header: "+ to_string(in.np)+ ", Found: " + to_string(pCount);
		return;
	} 
	
	float p[9];
	//Particles are read, intiliased and stored in a vector
	for (int i = 0; i< pCount; i++){
		fin.read(reinterpret_cast<char*>(p), 9* sizeof(float));
		in.ps.push_back(particle(p));
	}
}
int pargs::checkParams(int argc, char** argv, input& in) {
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
	// Input file
	try{
		readInput(argv[2], in);
	}catch( const char* headerMismatch){
		cout << headerMismatch << endl;
		return -5;
	}catch( int fileUnreachable){
		cout << "Error: Cannot open init.fld for reading\n";
		return -3;
	}
	ofstream fout;
	fout.open(argv[3], std::ios::binary | std::ios::out);
	if(!fout){
		cout << "Error: Cannot open " << argv[3] << " for writing\n";
		return -4;
	}
	return 1;

}