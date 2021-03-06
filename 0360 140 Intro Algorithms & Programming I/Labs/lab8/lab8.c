/*
* ASSIGNMENT	: Lab 8
* FILE	 		: lab8.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: November 28/14
* DESCRIPTION	: This program allows a user to search for a key in a 
			      randomly assigned array of integers. It will then 
				  return the position of the key in the array if the
				  key was found.
*/

/*


List of functions:

BubbleSort
This function takes as parameters the array, its size and an order flag.
The flag can be 1=ascending, 2=descending order. The function sorts the
array accordingly. Has no return.


BinarySearch
This function takes as parameters the array, its size, and a key to
search for. Will apply binary search, so assumes the list is already
sorted. Then returns the index of the first occurrence of the item key,
or -1 if not found.


GetNumber
This function prompts the user to enter an integer value that will be
used to fill up the array elements (array initialization). The inputted
value will be validated to be within the range of min..max. The valid
entry will be returned. (refer to previous labs � reuse the function!)


InitArray
This function uses the value returned from GetNumber to initialize all
array elements with. The input parameters of this function are: name of
the array, size of the array and the initialization value. It does not
return a value.


PrintArray
This is a void function that accepts the name and size of array as two
input parameters and prints the contents of the array.


PopulateArray
This function is void return and it fills array elements with random
values in the range of 1 .. MAX/2. It has two input parameters which
are the name and size of the array.


*/


#include "lab8.h"


// program entry
int main()
{	
	RunMenu();	

	return 0;
}






/******************************************************************************
FUNCTION		: RunMenu

DESCRIPTION		: This function 

INPUT			: N/A

OUTPUT			: N/A
******************************************************************************/
void RunMenu()
{
	ARRAY A;
	int size  = MAX; // defined in lab8.h
	int min   = 0;   // the minimum value allowed to initialize the array 
	int order = 2;   // 1=ascending, 2=descending sort order

	// initialize and seed pseudo-random number generator
	srand((int) time(NULL));
	
	// ask the user to enter a number
	printf("\nPlease enter an integer between %d and %d: ", min, MAX);

	// obtain a number and initialize the array to that number	
	InitArray(&A, size, GetNumber(0, size));
	
	// print the initialized array
	printf("\nInitialized array:\t   ");
	PrintArray(&A, size);

	// populate the array with random values between 1 and MAX/2
	PopulateArray(&A, size);
	
	// print the randomly assigned array
	printf("\nRandomly Populated array:  ");
	PrintArray(&A, size);

	// sort the array ascending or descending based on order
	BubbleSort(&A, size, order); // 1=ascending, 2=descending sort order
	
	// print the sorted array
	printf("\nSorted array ");

	if (order == 1)
		printf("(ascending):  ");

	else if (order == 2)
		printf("(descending): ");

	PrintArray(&A, size);

	// allow the user to search for a key
	while (1)
	{
		printf("\nPlease enter a key between 1 and %d ", MAX / 2);

		int key = GetNumber(1, MAX / 2);
		int position = BinarySearch(&A, size, key);

		if (position == -1)
			printf("\n%d could not be found in array!\n", key);

		else
			printf("\nFound key %d in position %d of the array!\n", key, position);
		
		char c;

		// allow the user to search for keys indefinitely
		while (1)
		{
			printf("\nDo you want to search for more keys (Y/N)? ");
			scanf(" %c", &c);

			if (c == 'y' || c == 'Y')
				break;

			else if (c == 'n' || c == 'N')
			{
				printf("\nGoodbye!\n\n");
				return;
			}

			else
				printf("\n%c is not a valid option.", c);
		}
	}
}





/******************************************************************************
FUNCTION		: BubbleSort

DESCRIPTION		: This function sorts an array of integers ascending or 
				  descending

INPUT			: Type			: ARRAY *
				: Description	: The array of elements

				: Type			: int
				: Description	: The size of the array

				: Type			: int
				: Description	: The sort order - ascending/descending

OUTPUT			: N/A
******************************************************************************/
void BubbleSort(ARRAY *a, int size, int order)
{
	int i = 0;
	int j = 0;	

	for (i = 0; i < (size - 1); i++)
		for (j = 0; j < size - i - 1; j++)
			Compare(a, j, order); // compare the jth element with j + 1
}





/******************************************************************************
FUNCTION		: Compare

DESCRIPTION		: This function checks the current value and the next value
				  and determines if the values should be swapped depending on
				  whether the sort is ascending or descending.

INPUT			: Type			: ARRAY *
				: Description	: The array of elements

				: Type			: int
				: Description	: the index of the currently selected array
								  element
				
				: Type			: int
				: Description	: The order flag that is used to determine
								  ascending or descending order

OUTPUT			: N/A
******************************************************************************/
void Compare(ARRAY *a, int j, int order)
{
	if (order == 1) // 1-ascending
		if ((*a)[j] > (*a)[j + 1])
			Swap(a, j);		
	else
		if ((*a)[j + 1] > (*a)[j])
			Swap(a, j);	
}





/******************************************************************************
FUNCTION		: Swap

DESCRIPTION		: This function swaps the current index value with the next
				  index value in the array

INPUT			: Type			: ARRAY *
				: Description	: The array of elements

				: Type			: int
				: Description	: the index of the currently selected array
								  element
								  
OUTPUT			: N/A
******************************************************************************/
void Swap(ARRAY *a, int j)
{
	int temp = (*a)[j];
	(*a)[j] = (*a)[j + 1];
	(*a)[j + 1] = temp;
}





/******************************************************************************
FUNCTION		: BinarySearch

DESCRIPTION		: This function searches for the key using a divide and conquer
				  technique for efficient search times. **This function assumes
				  the array is already sorted** 

INPUT			: Type			: ARRAY *
				: Description	: The array of elements

				: Type			: int
				: Description	: The size of the array
				
				: Type			: int
				: Description	: The value to find

OUTPUT			: Type			: int
				: Description   : The array position of the key if found, -1 if
								  key could not be found
******************************************************************************/
int BinarySearch(ARRAY *a, int size, int key)
{	
	int first = 0;
	int last = size - 1;
	int middle = (first + last) / 2; 		
	int index_position = -1;

	// assumes array is sorted
	while (first <= last)
	{
		// since the array is already sorted we only have to look at the middle
		// value and determine if the key is greater or less than the middle
		// value. Once determined, we only look at that 'half' of the array.
		// Each comparison will leave the array half the size and decrease
		// potential search time by half
		if ((*a)[middle] < key)
			first = middle + 1;		
		
		// if we found the key, set the position variable and return
		else if ((*a)[middle] == key)
		{			
			index_position = middle + 1;
			break;
		}
		
		else
			last = middle - 1;

		middle = (first + last) / 2;
	}	

	return index_position;
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

	for (; i < size; i++)
		(*a)[i] = rand() % size / 2 + 1;
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
	int i = 0;
	int count = 0;

	for (; i < MAX; i++)
	{
		if ((*a)[i] == key)
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
	for (; i < size; i++)
	{
		if (i < size - 1)
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

	for (; i < MAX; i++)
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
	int valid = 0;
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
