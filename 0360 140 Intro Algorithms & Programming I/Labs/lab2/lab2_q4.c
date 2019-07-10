/*
* ASSIGNMENT	: Lab 2
* FILE	 		: lab2_q4.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: October 02/14
* DESCRIPTION	: This program accepts one five-digit number, separates the
				  number into its individual digits and prints the digits
				  separated from one another by three spaces each.

				  Example:
				  Please enter a five digit number: 15389
				  The digits of 15389 are: 1 5 3 8 9
*/


#include <stdio.h>   // printf, scanf, getchar
#include <stdbool.h> // bool, true, false
#include <math.h>    // floor


// define a const max number length
#define NUMBER_LENGTH 5


// function prototype declaration
void printExtractedDigits(int, int *);
int * extractDigits(int);


// program entry
int main(void)
{
	// store the user's number
	int number = 0;
		
	printf("Please enter a five digit number: ");

	// input
	scanf("%d", &number);			

	// call the extractDigits function and store the resulting array in a new 
	// variable  
	int * extracted = extractDigits(number);
	
	// print the array of extracted digits
	printExtractedDigits(number, extracted);
		
	// ensure the user can see the printed results	
	getchar();	

	return 0;
}




/******************************************************************************
FUNCTION		: extractDigits

DESCRIPTION		: This function extracts the individual digits from a number

INPUT			: Type			: int
				: Description	: the number to be extracted

OUTPUT			: Type 			: number[]
				: Description	: the extracted digits from the initial number
******************************************************************************/
int * extractDigits(int number)
{
	// counter
	int i;
	
	// store the remainder of a number when % is calculated 
	int remainder = 0;

	// set the initial divisor to 5 decimal places
	int divisor = 10000;

	// once we go out of scope, variable not available anymore, 
	// so make static 
	static int digits[NUMBER_LENGTH];

	for (i = 0; i < NUMBER_LENGTH; i++)
	{
		// obtain the leading digit of the number
		digits[i] = number / divisor;
		// set the remainder as the modulus of the current number
		remainder = number % divisor;
		// reset the number to the remainder
		number = remainder;
		// shift down one decimal place
		divisor /= 10; 
	}

	return digits;
}




/******************************************************************************
FUNCTION		: printExtractedDigits

DESCRIPTION		: This function prints an array of integers

INPUT			: Type 			: int
				: Description	: the initial number the user entered

				: Type			: int[]
				: Description	: the array of digits to print

OUTPUT			: N/A
******************************************************************************/
void printExtractedDigits(int number, int * digits)
{
	// counter
	int i;

	// print out the contents of the array
	printf("The digits of %d are: ", number);

	// print each digit of the array
	for (i = 0; i < NUMBER_LENGTH; i++)
	{
		printf("%d   ", digits[i]);
	}

	printf("\n\n");
}


// EOF