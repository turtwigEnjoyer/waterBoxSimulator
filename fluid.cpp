#include <iostream>
#include "hello.hpp"
#include "progargs.hpp"

using namespace std;

int main(int argc, char** argv)
{
	for(int i=0; i<argc; i++){
		cout<<argv[i]<< " =" << i<<endl;
	}
	cout << atoi(argv[1]) << endl;
	int out= pargs::checkParams(argc, argv);
	if(out<0) return out;

	cout << "Hello World" << endl;

	return 0;
}