/*
* ASSIGNMENT	: Lab 2
* FILE	 		: lab2_q1.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: October 01/14
* DESCRIPTION	: This program reads in five integers and then determines and 
				  prints the largest and the smallest integers in the group 

                  Example:
                  
				  Please enter five integers: 5 12 -10 0 1
                  The Max is : 12
                  The Min is : -10
*/


#include <stdio.h> // printf, scanf, getchar


// program entry
int main(void)
{
	// declare and initialize number variables used to store the user's numbers
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	int num5 = 0;

	printf("\n\nPlease enter five integers: ");

	// input the numbers from prompt
	scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);

	// set the largest and smallest number as the first number
	int largest = 0;
	int smallest = 0;

	// find the largest number

	// check num1
	if ((num1 >= num2) && (num1 >= num3) && (num1 >= num4) && (num1 >= num5))
	{
		largest = num1;
	}
	// check num2
	if ((num2 >= num1) && (num2 >= num3) && (num2 >= num4) && (num2 >= num5))
	{
		largest = num2;
	}
	// check num3
	if ((num3 >= num1) && (num3 >= num2) && (num3 >= num4) && (num1 >= num5))
	{
		largest = num3;
	}
	// check num4
	if ((num4 >= num1) && (num4 >= num2) && (num4 >= num3) && (num4 >= num5))
	{
		largest = num4;
	}
	// check num5
	if ((num5 >= num1) && (num5 >= num2) && (num5 >= num3) && (num5 >= num4))
	{
		largest = num5;
	}

	// check for the smallest number

	// check num1
	if ((num1 <= num2) && (num1 <= num3) && (num1 <= num4) && (num1 <= num5))
	{
		smallest = num1;
	}
	// check num2
	if ((num2 <= num1) && (num2 <= num3) && (num2 <= num4) && (num2 <= num5))
	{
		smallest = num2;
	}
	// check num3
	if ((num3 <= num1) && (num3 <= num2) && (num3 <= num4) && (num3 <= num5))
	{
		smallest = num3;
	}
	// check num4
	if ((num4 <= num1) && (num4 <= num2) && (num4 <= num3) && (num4 <= num5))
	{
		smallest = num4;
	}
	// check num5
	if ((num5 <= num1) && (num5 <= num2) && (num5 <= num3) && (num5 <= num4))
	{
		smallest = num5;
	}

	// print the results
	printf("\nThe Max is : %d\n", largest);
	printf("The Min is : %d\n\n", smallest);

	// ensure the user can see the printed results
	getchar();
	
	return 0;
}

// wrote this before I notice we couldn't use arrays
//#include <stdio.h>
//
//
//// 
//#define SIZE 5
//
//
//// program entry
//int main(void)
//{
//
//    int numbers [SIZE]; 
//    int i;    
//   
//    printf("\n\nPlease enter five integers: ");
//
//    for(i = 0; i < SIZE; ++i)
//    {
//        scanf("%d", &numbers[i]);
//    }
//
//    // set the largest and smallest number as the first index of the array
//    int largest = numbers[0];
//    int smallest = numbers[0];
//
//
//    for(i = 0; i < SIZE - 1; ++i)
//    {		
//        if(numbers[i+1] > largest)
//        {
//            largest = numbers[i+1];   
//        }
//        if(numbers[i+1] < smallest)
//        {
//			smallest = numbers[i+1];
//        }		
//    }
//
//    printf("\nThe Max is : %d\n", largest);
//    printf("The Min is : %d\n\n", smallest);
//
//    getchar();
//	  getchar();
//
//    return 0;
//}

// EOF