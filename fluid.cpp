/* DEADLINE OCTOBER 30TH !!  */


#include "headers/progargs.h"


int main(int argc, char** argv)
{
	grid singletonGrid;

	//This will initialize each particle
	// Particles for now are stored in a class static array
	int out= pargs::checkParams(argc, argv, singletonGrid);
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
		singletonGrid.ClearDensities(); //Sets Distances to 0 AND accelerations to 0,gravity,0
		singletonGrid.DensityIncrease(); //Performs 4.3.2 Densities Increase
		singletonGrid.DensityTransformations(); // Perfroms 4.3.2 Densitie Transformations
		singletonGrid.AccelerationTransfer(); // Acceleration Transfer. Currently takes up HALF RUN TIME --> NEEDS PERFORMANCE EVAL
		singletonGrid.CalculateCollisions();//Calculate the collision with boolean values of the bocks, to know if they are boundaries or not
		singletonGrid.CalculateParticlesMotion(); //Performs 4.3.4
		singletonGrid.CalculateBoundaries(); //Performs 4.3.5
	} 
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	//int output = pargs::writeOutput(fout, singletonGrid.ppm, singletonGrid.countParticles(),);
	pargs::writeOutput(fout, singletonGrid);

	cout << timeSteps<< " requiere "<< duration.count() <<endl;
	//MISSING FORMULAS
	
	return 0;
}