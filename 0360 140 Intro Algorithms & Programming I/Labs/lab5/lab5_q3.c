/*
* ASSIGNMENT	: Lab 5
* FILE	 		: lab5_q3.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: October 22/14
* DESCRIPTION	: This program will accept an integer n from the user and will
				  print the sum from 1..n

				  Example:
				  Please enter a positive integer n: 5
				  Sum(5) = 5+4+3+2+1 = 15
*/


#include <stdio.h> // printf, scanf


// function prototypes
int Sum(int);

// program entry
int main (void)
{
	int n = 0;
	int i = 0;
		
	printf("\nPlease enter a positive integer n: ");
	scanf("%d", &n);
	
	int result = Sum(n);

	printf("\nSum(%d) = ", n);
	
	for(i = n; i > 1; i--)
	{
		printf("%d+", i);
	}
	printf("1 = %d\n\n", result);

	return 0;
}




/******************************************************************************
FUNCTION		: Sum

DESCRIPTION		: This function returns the sum of integers from 1 to n:
				  Ex: 1 + ... + (n - 2) + (n -1) + n

INPUT			: Type			: int
				: Description	: n
				
OUTPUT			: Type 			: int
				: Description	: the sum of the integers
******************************************************************************/
int Sum(int n)
{
	int i = n;	
	int sum = 0;
	
	for(; i > 0; i--)
	{
		sum += i;	
	}
	
	return sum;
}



// EOF
