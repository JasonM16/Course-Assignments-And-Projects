/*
* PROJECT		: Assignment 3
* FILE			: program1.c
* AUTHOR		: Jason Choquette 104337378
* DATE			: Feb. 9, 2018
* DESCRIPTION	: An interesting way of calculating pi is to use a technique
				  known as Monte Carlo, which involves randomization. This 
				  technique works as follows. 
				  
				  Suppose you have a circle inscribed within a square.
				  First, generate s series of points as simple (x, y) 
				  coordinates. These points must fall within the Cartesian 
				  coordinates that bound the square. Of the total number of 
				  random points that are generated, some will occur within the 
				  circle. 
				  
				  Next, estimate pi by performing the following calculation:
				  pi = 4 x (number of points in circle) / (total number of points)

				  Write a multi-threaded version of this algorithm that creates
				  a separate thread (the slave-thread) to generate a number of 
				  random points. The slave-thread will count the number of 
				  points that occur within the circle (the hit_count) and store 
				  that result in the global variable circle_count. When the 
				  slave-thread has exited, the parent thread (the master-thread) 
				  will calculate and output the estimated value of pi. 
				  
				  It is worth experimenting with the number of random points 
				  generated. As a general rules, the greater the number of 
				  random points, the closer the approximation of pi.
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

INPUT			: Type			: LPVOID
				: Description	: The threaded function argument that will be
								  cast to type DWORD (int) which is the number
								  of simulations. The threaded function must 
								  have this signiture for the WINAPI threading 
								  system call.
								  The long void pointer can then be type-cast 
								  inside the function.

OUTPUT			: Type 			: void
				: Description	: N/A
******************************************************************************/
void WINAPI generateRandomPoints(LPVOID number_of_simulations)
{	
	const DWORD sims = *(DWORD *)number_of_simulations;
	DWORD count = 0;
	
	while (count++ <= sims)
	{
		double x = randomDouble() * 2.0 - 1.0;
		double y = randomDouble() * 2.0 - 1.0;
		if ( sqrt(x*x + y*y) < 1.0)
			hit_count += 1;				
	}	
}





/******************************************************************************
FUNCTION		: main

DESCRIPTION		: The main function creates a single thread to execute a Monte
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
	DWORD ThreadId;
	HANDLE ThreadHandle;
	DWORD number_of_simulations = NUMBER_OF_POINTS;
	srand((unsigned)time(NULL));	// seed random number generator

	clock_t t = clock();
	// create thread to calculate random number of points
	ThreadHandle = 
	  CreateThread(
		NULL,	// default security attributes
		0,		// use default stack size
		(LPTHREAD_START_ROUTINE)generateRandomPoints, // thread function name
		&number_of_simulations,	// argument to thread function
		0,			 // use default creation flags
		&ThreadId);	// returns the thread identifier

	
	// when slave thread has ended master will calculate estimate of pi.
	if (ThreadHandle != NULL)
	{
		WaitForSingleObject(ThreadHandle, INFINITE);
		CloseHandle(ThreadHandle);
		// call calculation...
		double pi = calculatePi(number_of_simulations);
		t = clock() - t;

		const double time = (double)t / CLOCKS_PER_SEC;

		printf("Calculated value of pi: %f\n", pi);
		printf("Total time taken by CPU: %f seconds\n", time);
	}

	_getch();

	return 0;
}