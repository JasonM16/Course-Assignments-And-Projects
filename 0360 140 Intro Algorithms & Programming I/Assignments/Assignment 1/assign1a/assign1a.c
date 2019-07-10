/*
 * ASSIGNMENT	: Assignment 1
 * FILE	 		: assign1a.c
 * AUTHOR		: Jason Choquette
 * ID			: 104337378
 * DATE			: October 01/14
 * DESCRIPTION	: This program takes an input of 5 digits in any order, and 
                  outputs (with no spacing) the largest integer that can be 
                  composed of the digits.

				  Sample input:
				  1 4 5 3 2
				  Sample output:
				  54321
	
				  Another sample input:
				  9 8 2 9 9 
				  Sample output:
				  99982
 */


#include <stdio.h>  // printf, scanf, NULL
#include <stdlib.h> // srand, rand
#include <time.h>   // time


//define a constant for the size of the array
#define ARRAY_SIZE 5


// function prototype declarations
void RunAutomatedTests(void);
void RunManualTests(void);
void SortAndPrint(int []);


// program entry
int main (void)
{    
    // option to run automatic or maual test
    int option = 0;

    printf("Choose an option to run the program:\n\n");
    printf("1. Run automated tests\n2. Run manual test\n\n");
    scanf("%d", &option);

    // switch on option
    switch (option)
    {
        case 1:
	  		RunAutomatedTests();
        break;

		case 2:
	  		RunManualTests();
		break;

		default: 
	  		printf("Please select an option from the menu.");
        break;
    }    

    printf("\n\n");

	// ensure we can see the printed output.
    getchar();	
    
    return 0;
}





/******************************************************************************
 FUNCTION		: RunAutomatedTests

 DESCRIPTION	: this function is an automated testing suite that will create
 				  an array of random numbers and then call a function to sort
 				  and print the array. 
 
 INPUT			: N/A
		 
 OUTPUT			: N/A	 
******************************************************************************/
void RunAutomatedTests()
{
    int i = 0;
    int j = 0;
    int numbers [ARRAY_SIZE]; 
    
    printf("Running automated tests...\nCreating random numbers to sort.\n\n");

    // initialize random seed. Use NULL to use the default initilizer 
    srand (time(NULL)); 
    
    for(j = 0; j < ARRAY_SIZE; ++j)
    {
        for(i = 0; i < ARRAY_SIZE; ++i)
        {
            numbers[i] = rand() % 9 + 0; // pick a random digit from 0 to 9
        }
    
        printf("--------------------\n");
        printf("Test #%d\n", j + 1);
        printf("--------------------\n");
        printf("Unsorted: \n");        

        for(i = 0; i < ARRAY_SIZE; ++i)
            printf("%d", numbers[i]);

        printf("\n\n");

        SortAndPrint(numbers);

        printf("\n--------------------\n");
        printf("\n");
    } 
}





/******************************************************************************
 FUNCTION       : RunManualTests

 DESCRIPTION    : this function asks the user for five integers and then 
 				  stores the numbers into an array. That array is then passed
 				  to a function to sort and print the array.
 
 INPUT          : N/A
 
 OUTPUT         : N/A
******************************************************************************/
void RunManualTests()
{
    int numbers[ARRAY_SIZE];
    int i = 0;
         
    printf("Enter the numbers to sort with a space in between each number \n");

	// insert the numbers into an array
    for (i = 0; i < ARRAY_SIZE; ++i)
        scanf("%d", &numbers[i]);

	// send the numbers to be sorted and printed
    SortAndPrint(numbers);
}





/******************************************************************************
 FUNCTION       : SortAndPrint

 DESCRIPTION    : this function uses a naive sorting algorithm to sort an array
 				  of numbers and then prints the sorted array to the console. 
 
 INPUT          : Type : int[]  
                : Description : this is an array integers to be sorted

 OUTPUT         : N/A
******************************************************************************/
void SortAndPrint(int numbers[])
{
    int i = 0;
    int j = 0;
    int temp = 0;
    
    for (i = 0; i < ARRAY_SIZE; ++i)
    {
        for (j = i + 1; j < ARRAY_SIZE; ++j)
        {   
        	// if the current number is less than the next number, swap them
            if (numbers[i] < numbers[j])
            {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

	// go through the array and print each number to the console
    printf("Sorted:\n");

    for (i = 0; i < ARRAY_SIZE; ++i)
    {
        printf("%d", numbers[i]);
    }
}


// EOF