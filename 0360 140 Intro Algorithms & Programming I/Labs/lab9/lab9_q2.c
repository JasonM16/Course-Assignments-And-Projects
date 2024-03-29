/*
* ASSIGNMENT	: Lab 9
* FILE	 		: lab9_q2.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: November 18/14
* DESCRIPTION	: This program swaps two values and as well as triples a value.
*/


// program dependencies
#include <stdio.h>  // printf 
#include <time.h>   // time
#include <stdlib.h> // rand, srand 


// function prototypes
int Triple(int * n);
void Swap(int * a, int * b);
void RunManual(void);
void RunAutomatically(void);
void PrintResults(int a, int b, int c);
				

// program entry
int main(void)
{	
	int choice = 0;
	
	while(1)
	{
		printf("\n1. Enter numbers manually\n");
		printf("2. Run Automatically\n");
		printf("3. Exit\n");
		
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				RunManual();
				break;
		
			case 2:
				RunAutomatically();
				break;
				
			case 3:
				printf("Goodbye!\n\n");
				return;
				
			default:
				printf("Not a valid choice. Try again\n\n");
				break;		
		}	
	}

	return 0;
}




/******************************************************************************
FUNCTION		: RunManual

DESCRIPTION		: This function obtains values from a user and then calls
				  PrintResults with those values.

INPUT			: N/A

OUTPUT			: N/A
******************************************************************************/
void RunManual(void)
{		
	int a = 0;
	int b = 0;	
	int c = 0;
	
	printf("\nEnter a single value: ");
	scanf("%d", &c);
	
	printf("Enter two values: ");
	scanf("%d %d", &a, &b);
	
	PrintResults(a, b, c);	
}





/******************************************************************************
FUNCTION		: RunAutomatically

DESCRIPTION		: This function generates random values and then calls the
				  PrintResults function with those values.

INPUT			: N/A

OUTPUT			: N/A
******************************************************************************/
void RunAutomatically(void)
{
	srand((int)time(NULL));

	int a = rand() % 1000 + 1;
	int b = rand() % 1000 + 1;
	int c = rand() % 500 + 1;
	
	PrintResults(a, b, c);
}




/******************************************************************************
FUNCTION		: PrintResults

DESCRIPTION		: This function prints the results of Triple and Swap

INPUT			: Type			: int 
				: Description	: The first value to swap

				: Type			: int 
				: Description	: The second value to swap
				
				: Type			: int 
				: Description	: The number to be tripled

OUTPUT			: N/A
******************************************************************************/
void PrintResults(int a, int b, int c)
{
	printf("\nBefore calling Triple: %d\n", c);	
	printf("After calling Triple:  %d\n\n", Triple(&c));
	printf("Before calling Swap: a = %d\tb = %d\n", a, b);
	Swap(&a, &b);
	printf("After calling Swap:  a = %d\tb = %d\n", a, b);	
}





/******************************************************************************
FUNCTION		: Swap

DESCRIPTION		: This function swaps two values

INPUT			: Type			: int *
				: Description	: The first value to swap

				: Type			: int *
				: Description	: The second value to swap

OUTPUT			: N/A
******************************************************************************/
void Swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}





/******************************************************************************
FUNCTION		: Triple

DESCRIPTION		: This function triples a number

INPUT			: Type			: int *
				: Description	: The number to multiply
				
OUTPUT			: Type			: int
				: Description	: The multiplied number
******************************************************************************/
int Triple(int * n)
{
	*n *= 3;

	return *n;
}



// EOF
