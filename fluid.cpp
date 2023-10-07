/* DEADLINE OCTOBER 30TH !!  */


#include "progargs.h"

using namespace std;


int main(int argc, char** argv)
{
	grid singletonGrid;

	//This will initialize each particle
	// Particles for now are stored in a class static array
	int out= pargs::checkParams(argc, argv, singletonGrid);
	if(out<0) return out;

	int timeSteps=500;
	//1000 takes 815 seconds
	//100 takes 8 seconds --> makes no sense?
	auto start = chrono::high_resolution_clock::now();

	for(int i=0;i<timeSteps;i++)
	{
		singletonGrid.ClearDistances();
		singletonGrid.calculateDistances();
	} 
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	cout << timeSteps<< " requiere "<< duration.count() <<endl;
	//MISSING FORMULAS
	
	return 0;
}