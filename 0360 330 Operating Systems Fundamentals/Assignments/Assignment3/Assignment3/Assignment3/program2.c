/*
* PROJECT		: Assignment 3
* FILE			: program2.c
* AUTHOR		: Jason Choquette 104337378
* DATE			: Feb. 9, 2018
* DESCRIPTION	: Repeat Program-1 but instead of using a separate thread to 
				  generate random points, use OpenMP to parallelize the 
				  generation of points. Be careful not to place the calculation 
				  of pi in the parallel region, since you want to calculate pi 
				  only once.
*/


#include "A3_Prototypes.h"


/******************************************************************************
FUNCTION		: generateRandomPoints

DESCRIPTION		: A multi-threaded algorithm that creates a separate thread 
				  (the slave-thread) to generate a number of random points. 
				  The slave-thread will count the number of points that occur
				  within the circle (the hit_count). When the slave-thread has 
				  exited, the parent thread (the master-thread) will calculate 
				  and output the estimated value of pi.

INPUT			: Type			: int
				: Description	: The number of simulations to calculate.

OUTPUT			: Type 			: void
				: Description	: N/A
******************************************************************************/
void generateRandomPoints(int number_of_simulations)
{	
	int count = 0;
	
	#pragma omp parallel
	while (count++ <= number_of_simulations)
	{
		double x = randomDouble() * 2.0 - 1.0;
		double y = randomDouble() * 2.0 - 1.0;
		if (sqrt(x*x + y * y) < 1.0)
			hit_count += 1;		
	}
}





/******************************************************************************
FUNCTION		: main

DESCRIPTION		: The main function waits for a thread to execute a Monte
				  Carlo simulation that will attempt to count the number of
				  random points that fall within a circle of radius one.
				  Once the points have been calculated, they are used to 
				  estimate the value of pi. Once this value has been calculated,
				  the result and program execution time are printed to the 
				  console.

INPUT			: Type			: void
				: Description	: N/A

OUTPUT			: Type 			: int
				: Description	: The return value of the program.
******************************************************************************/
int main()
{
	int number_of_simulations = NUMBER_OF_POINTS;
	srand((unsigned)time(NULL)); // seed random number generator

	clock_t t = clock();

	// call to threaded function
	generateRandomPoints(number_of_simulations);	
	double pi = calculatePi(number_of_simulations);

	t = clock() - t;

	const double time = (double)t / CLOCKS_PER_SEC;

	printf("Calculated value of pi: %f\n", pi);
	printf("Total time taken by CPU: %f seconds\n", time);

	_getch();

	return 0;
}