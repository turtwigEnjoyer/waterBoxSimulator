/* DEADLINE OCTOBER 30TH !!  */


#include "headers/progargs.h"


int main(int argc, char** argv)
{
	grid singletonGrid;

	//This will initialize each particle
	// Particles for now are stored in a class static array
	int out= pargs::checkParams(argc, argv, singletonGrid);
	ofstream fout;

	if(out<0) return out;
	singletonGrid.initializeBlocks(); //Blocks, no se si aqui tenemos que cambiarlo para que haga las funciones que cambiaste el otro día?

	int timeSteps=100;
	//1000 takes 815 seconds
	//100 takes 8s With ParticlePos 6s with particle only
	//300 Takes 54s wtih ParticlePos 49s without. Difference seeems linear but iteration growth isnt?  of 
	auto start = chrono::high_resolution_clock::now();

	for(int i=0;i<timeSteps;i++)
	{
		//4.3.2
		singletonGrid.ClearDensities(); //Sets Distances to 0. Doesnt set acceleration to 0 yet
		singletonGrid.DensityIncrease(); //Performs 4.3.2 Densities Increase
		singletonGrid.DensityTransformations(); // Perfroms 4.3.2 Densitie Transformations
		singletonGrid.AccelerationTransfer();
		singletonGrid.CalculateCollisions();//Calculate the collision with boolean values of the bocks, to know if they are boundaries or not
		singletonGrid.CalculateBoundaries(); //Performs 4.3.5
	} 
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	cout << timeSteps<< " requiere "<< duration.count() <<endl;
	
	//cout << "número de partículas:" << singletonGrid.countParticles();
	//MISSING FORMULAS
	
	return 0;
}