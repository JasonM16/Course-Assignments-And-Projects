/*
* PROJECT		: Assignment 3
* FILE			: program4.c
* AUTHOR		: Jason Choquette 104337378
* DATE			: Feb. 9, 2018
* DESCRIPTION	: Program-4. Program-2 asked you to design a program using 
				  OpenMP that estimated pi using the Monte Carlo technique. 
				  Examine your solution to Program-2 looking for any possible
				  race conditions. If you identify a race condition, protect 
				  against it using the strategy outline in Section 5.10.2 of 
				  the textbook.
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
	int sims = number_of_simulations;
	int count = 0;
	
	#pragma omp parallel num_threads(NUMBER_OF_SLAVES)
	while (count++ <= sims)
	{
		double x = randomDouble() * 2.0 - 1.0;
		double y = randomDouble() * 2.0 - 1.0;
		#pragma omp critical  //-------- Program 4 diff from Program 2
		if (sqrt(x*x + y * y) < 1.0)
			hit_count += 1;		
	}
}





/******************************************************************************
FUNCTION		: main

DESCRIPTION		: The main function waits for a multiple threads to execute a 
				  Monte Carlo simulation that will attempt to count the number
				  of random points that fall within a circle of radius one.
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
	int number_of_simulations = NUMBER_OF_POINTS / NUMBER_OF_SLAVES;
	srand((unsigned)time(NULL));
	clock_t t = clock();
	generateRandomPoints(number_of_simulations);
	double pi = calculatePi(number_of_simulations);

	t = clock() - t;

	const double time = (double)t / CLOCKS_PER_SEC;

	printf("Calculated value of pi: %f\n", pi);
	printf("Total time taken by CPU: %f seconds\n", time);	

	_getch();

	return 0;
}