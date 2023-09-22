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
	pargs::checkParams(argc, argv);

	cout << "Hello World" << endl;

	return 0;
}