/*
* PROJECT		: Assignment 3
* FILE			: program3.c
* AUTHOR		: Jason Choquette 104337378
* DATE			: Feb. 9, 2018
* DESCRIPTION	: Modify Program-1 so that you create several slave-threads, 
				  each of which generates random points and determines if the 
				  points fall within the circle.
				  Each slave-thread will have to update the global count of 
				  all points that fall within the circle. 
	
				  Protect against race conditions on updates to the shared 
				  global variable by using mutex locks.

				  Note: each slave-thread must generate points_per_thread 
				  random points, which is the ratio of the total number of 
				  random points to the number of slave-threads.
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
	const DWORD sims = *(DWORD*)number_of_simulations;
	DWORD count = 0;

	const DWORD dwWaitResult = WaitForSingleObject(
		ghMutex,    // handle to mutex
		INFINITE);  // no time-out interval	
	switch (dwWaitResult)
	{
		// The thread got ownership of the mutex
	case WAIT_OBJECT_0:
		__try
		{
			while (count++ < sims)
			{
				const double x = randomDouble() * 2.0 - 1.0;
				const double y = randomDouble() * 2.0 - 1.0;
				if (sqrt(x*x + y * y) < 1.0)
					hit_count += 1;
			}
		}
		__finally
		{
			// Release ownership of the mutex object
			if (!ReleaseMutex(ghMutex))
				printf("ReleaseMutex error: %lu\n", GetLastError());
		}

		printf("Thread %lu: wait succeeded\n", GetCurrentThreadId());
		break;

	case WAIT_TIMEOUT:
		printf("Thread %lu: wait timed out\n", GetCurrentThreadId());
		break;

		// The thread got ownership of an abandoned mutex				
	case WAIT_ABANDONED:
		return;
	default:;
	}
}





/******************************************************************************
FUNCTION		: main

DESCRIPTION		: The main function creates multiple threads to execute a Monte
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
	// seed prng
	srand((unsigned)time(NULL));
	

	// Create a mutex with no initial owner
	ghMutex = CreateMutex(
				NULL,              // default security attributes
				FALSE,             // initially not owned
				NULL);             // unnamed mutex

	if (ghMutex == NULL)
	{
		printf("CreateMutex error: %lu\n", GetLastError());
		return 1;
	}


	int i;
	DWORD number_of_simulations = NUMBER_OF_POINTS / NUMBER_OF_SLAVES;
	DWORD ThreadId;
	HANDLE aThread[NUMBER_OF_SLAVES];

	// Create worker threads
	for (i = 0; i < NUMBER_OF_SLAVES; i++)
	{
		aThread[i] =
		 CreateThread(
			NULL,						// default security attributes
			0,							// default stack size
			(LPTHREAD_START_ROUTINE)generateRandomPoints, 
			&number_of_simulations,	// thread function arguments
			0,							// default creation flags
			&ThreadId);				// receive thread identifier

		if (aThread[i] == NULL)
		{
			printf("CreateThread error: %lu\n", GetLastError());
			return 1;
		}
	}

	clock_t t = clock();

	// Wait for all threads to terminate

	/*  WaitForMultipleObjects has some weird behaviour... 
	    If the required number of threads is less than 64, 
		then the actual number of threads is required. 
		In this case, NUMBER_OF_SLAVES
	*/
	if(NUMBER_OF_SLAVES >= 64)
		WaitForMultipleObjects(MAXIMUM_WAIT_OBJECTS /*64*/, 
			aThread,
			TRUE,
			INFINITE); 

	else
		WaitForMultipleObjects(NUMBER_OF_SLAVES, aThread, TRUE, INFINITE);

	// Close thread and mutex handles
	for (i = 0; i < NUMBER_OF_SLAVES; i++)
		CloseHandle(aThread[i]);
	
	CloseHandle(ghMutex);


	const double pi = calculatePi(number_of_simulations) / NUMBER_OF_SLAVES;	
	t = clock() - t;

	const double time = (double) t / CLOCKS_PER_SEC;
	
	printf("Calculated value of pi: %f\n", pi);
	printf("Total time taken by CPU: %f seconds\n", time);

	_getch();

	return 0;
}