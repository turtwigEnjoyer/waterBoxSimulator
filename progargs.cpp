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
void pargs::checkParams(int argc, char** argv) {
	if (argc != 3) {
		cout << "Invalid number of args\n";
		//throw INVALID_NUMBER_ARGS;
		return;
	}
	if (!isNumber(argv[1])){
		cout << "NAN \n";
	}
	
	int np = atoi(argv[1]);
	ifstream inputFile (argv[2], ios::binary);
	if (!inputFile) {
		cout <<"Unreachable";
		//throw IN_FILE_UNREACHABLE;
	}
	return;

}