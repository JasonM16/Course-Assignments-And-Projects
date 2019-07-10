/*
* ASSIGNMENT	: Lab 5
* FILE	 		: lab5_q2.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: October 22/14
* DESCRIPTION	: This program takes as input parameters three integers a, b 
				  and c. The function returns the largest of the three integers.

		          Example:
				  Please enter three integers: 15 10 41
				  Max3(15, 10, 41) has returned 41
*/


#include <stdio.h> // printf, scanf


// function prototypes
int Max(int, int);
int Max3(int, int, int);


// program entry
int main (void)
{
	int a = 0;
	int b = 0;
	int c = 0;
		
	printf("\nPlease enter three integers: ");
	scanf("%d %d %d", &a, &b, &c);
	
	int result = Max3(a,b,c);

	printf("\nMax(%d, %d, %d) has returned %d\n\n", a, b, c, result);
	
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





/******************************************************************************
FUNCTION		: Max3

DESCRIPTION		: This function returns the largest of three integers

INPUT			: Type			: int
				: Description	: the first integer to be compared
				: Type			: int
				: Description	: the second integer to be compared
				: Type			: int
				: Description	: the third integer to be compared
				
OUTPUT			: Type 			: int
				: Description	: the largest of the three integers
******************************************************************************/
int Max3(int a, int b, int c)
{	
	int d = Max(a,b); 
	return d > c ? d : c;
}



// EOF
