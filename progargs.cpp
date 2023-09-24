#include "progargs.hpp"
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
bool isNumber(const char* str){
	for(int i=0; i< strlen( str ); i++){
		if(!isdigit(str[i])){
			return false;
		}
	}
	return true;
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
	ifstream inputFile (argv[2], ios::binary);
	ofstream outputFile(argv[3], ios::binary);

	if (!inputFile) {
		cout <<"Error: Cannot open init.fld for reading\n";
		return -3;
	}
	if(!outputFile){
		cout << "Error: Cannot open final.fld for writing\n";
		return -4;
	}
	// Check input file
	return 1;

}