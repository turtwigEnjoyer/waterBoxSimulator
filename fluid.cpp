/* DEADLINE OCTOBER 30TH !!  */


#include "progargs.h"

using namespace std;


int main(int argc, char** argv)
{
	grid singletonGrid;
	int out= pargs::checkParams(argc, argv, singletonGrid);
	if(out<0) return out;

	int timeSteps=10000;

	auto start = chrono::high_resolution_clock::now();

	for(int i=0;i<timeSteps;i++)
	{
		singletonGrid.CalculateDistances();
	}
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	cout << timeSteps<< " requiere "<< duration.count() <<endl;
	//MISSING FORMULAS
	
	return 0;
}