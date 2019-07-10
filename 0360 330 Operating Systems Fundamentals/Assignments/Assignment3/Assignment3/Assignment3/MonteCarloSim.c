/*
* PROJECT		: Assignment 3
* FILE			: MonteCarloSim.c
* AUTHOR		: Jason Choquette 104337378
* DATE			: Feb. 9, 2018
* DESCRIPTION	:
*/


#include "A3_Prototypes.h"


/******************************************************************************
FUNCTION		: randomDouble

DESCRIPTION		: This function calculates and returns a random number.

INPUT			: Type			: void
				: Description	: N/A

OUTPUT			: Type 			: double
				: Description	: a random number of type double
******************************************************************************/
double randomDouble()
{
	return (double)rand() / RAND_MAX;
}





/******************************************************************************
FUNCTION		: calculatePi

DESCRIPTION		: This function calculates pi using randomization. This function
				  relies on multiple iterations in determining the hit count of
				  of random points inside a circle.

INPUT			: Type			: DWORD
				: Description	: The number of MonteCarlo simulations performed
								  to generate random points inside a circle.

OUTPUT			: Type 			: double
				: Description	: The calculated pi value
******************************************************************************/
double calculatePi(DWORD number_of_simulations)
{
	return 4 * (double)hit_count / number_of_simulations;
}