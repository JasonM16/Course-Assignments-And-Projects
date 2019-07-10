/*
* ASSIGNMENT	: Lab 5
* FILE	 		: lab5_q1.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: October 22/14
* DESCRIPTION	: This program takes as input two integers a and b. The function
				  returns the largest of the two.

				  Example:
				  Please enter two integers: 15 10
				  Max(15, 10) has returned 15
*/


#include <stdio.h> // printf, scanf


// function prototypes
int Max(int, int);


// program entry
int main (void)
{
	int a = 0;
	int b = 0;
		
	printf("\nPlease enter two integers: ");
	scanf("%d %d", &a, &b);
	
	int result = Max(a, b);

	printf("\nMax(%d, %d) has returned %d\n\n", a, b, result);

	return 0;
}





/******************************************************************************
FUNCTION		: Max

DESCRIPTION		: This function returns the largest of two integers

INPUT			: Type			: int
				: Description	: the first integer to be compared
				: Type			: int
				: Description	: the second integer to be compared
				
OUTPUT			: Type 			: int
				: Description	: the larger of the two integers
******************************************************************************/
int Max(int a, int b) { return a >= b ? a : b; }



// EOF
