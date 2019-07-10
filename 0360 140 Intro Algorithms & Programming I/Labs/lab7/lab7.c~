/*
* ASSIGNMENT	: Lab 7
* FILE	 		: lab7.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: November 13/14
* DESCRIPTION	: This program allows a user to search for elements in a randomly
				  assigned array of integers. It will then return the number of 
				  occurences of that element.
*/


#include "lab7.h"


// program entry
int main (void)
{	
	ARRAY A;     // define the array type		
	int min = 0; // set the min value 
	
	printf("\n\t\t  MAX=%d\n", MAX_SIZE);
	
	srand(time(NULL));
	
	printf("\nPlease enter an integer between %d and %d: ", min, MAX_SIZE);
	
	InitArray(&A, MAX_SIZE, GetNumber(min, MAX_SIZE));
	
	printf("\nInitialized Array: ");	
	PrintArray(&A, MAX_SIZE);	
		
	PopulateArray(&A, MAX_SIZE);
	printf("\nPopulated Array:   ");	
	PrintArray(&A, MAX_SIZE);	
	
	while(1)
	{	
		printf("\nPlease enter a key between 1 and %d ", MAX_SIZE/2);
	
		int key = GetNumber(1, MAX_SIZE/2);
		int occurances = SearchArray(&A, key);
		
		if(occurances == 0)
			printf("No occurances");
		
		else if(occurances == 1)
			printf("1 occurance");
		
		else
			printf("%d occurances", occurances);
		
		printf(" found for value of %d in the array!", key);
	
		char c;
	
		while(1)
		{
			printf("\nDo you want to search for more keys (Y/N)? ");
			scanf(" %c", &c);
			
			if(c == 'y' || c == 'Y')
				break;
						
			else if(c == 'n' || c == 'N')
			{
				printf("\nGoodbye!\n\n");
				return;
			}			
			
			else
				printf("\n%c is not a valid option.", c);
		}	
	}
	
	return 0;
}





/******************************************************************************
FUNCTION		: PopulateArray

DESCRIPTION		: This function populates an array with random digits between
				  the size of the array / 2 and 1. 

INPUT			: Type			: ARRAY *
				: Description	: The array of elements
				
				: Type			: int
				: Description	: The size of the array
								
OUTPUT			: N/A
******************************************************************************/
void PopulateArray(ARRAY *a, int size)
{
	int i = 0;
	
	for(; i < size; i++)
		(*a)[i] = rand() % size/2 + 1;		
}





/******************************************************************************
FUNCTION		: SearchArray

DESCRIPTION		: This function will search the array for an element matching
				  a key given by the parameter. It will then return the number
				  of occurences of the key found in the array.

INPUT			: Type			: ARRAY *
				: Description	: The array of elements
				
				: Type			: int
				: Description	: The key that will be searched for in the array
								
OUTPUT			: Type			: int
				: Description	: The number of elements int the array that 
				                  match the search key.
******************************************************************************/
int SearchArray(ARRAY *a, int key)
{
	int i     = 0;
	int count = 0;

	for(; i < MAX_SIZE; i++)
	{
		if((*a)[i] == key)
			count++;
	}
	
	return count;
}





/******************************************************************************
FUNCTION		: PrintArray

DESCRIPTION		: This function prints each element of the array. 

INPUT			: Type			: ARRAY *
				: Description	: The array of elements
				
				: Type			: int
				: Description	: The size of the array
								
OUTPUT			: N/A
******************************************************************************/
void PrintArray(ARRAY *a, int size)
{
	int i = 0;
	printf("A=[");
	for(; i < size; i++)
	{
		if(i < size - 1)
			printf("%d, ", (*a)[i]);
		
		else
			printf("%d]\n", (*a)[i]);		
	}
}





/******************************************************************************
FUNCTION		: InitArray

DESCRIPTION		: This function will initialize all the elements of an array to
				  a value selected by the user that is passed in as a parameter. 

INPUT			: Type			: ARRAY *
				: Description	: The array of elements
				
				: Type			: int
				: Description	: the size of the array
				
				: Type			: int
				: Description	: the number to set each element to
				
OUTPUT			: N/A
******************************************************************************/
void InitArray(ARRAY *a, int size, int n)
{
	int i = 0;
		
	for(; i < MAX_SIZE; i++)		
		(*a)[i] = n;	
}





/******************************************************************************
FUNCTION		: GetNumber

DESCRIPTION		: This function obtains an integer value from the console and
				  validates the number between a given range which are the 
				  parameters of the function, min and max.

INPUT			: Type			: int
				: Description	: the minimum digit allowed as input
				
				: Type			: int
				: Description	: the maximum digit allowed as input
				
OUTPUT			: Type 			: int
				: Description	: the user's input as an integer between the min
								  and max range
******************************************************************************/
int GetNumber(int min, int max)
{
	// set to zero. Once the input is valid, set valid to 1 which will exit the
	// loop
	int valid      = 0;	
	int user_input = 0; // used to store and validate user input

	// continue to ask for a digit until a valid digit is entered
	do
	{
		printf(">> ");
		scanf("%d", &user_input);
		if (user_input < min || user_input > max)
		{
			printf("\n%d is not a valid number, please select a number between %d and %d!\n\n"
				, user_input, min, max);
				
			continue;
		}

		valid = 1;

	} while (!valid);

	return user_input;
}



// EOF
