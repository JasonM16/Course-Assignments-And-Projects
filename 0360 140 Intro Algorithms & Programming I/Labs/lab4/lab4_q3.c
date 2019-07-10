/*

* ASSIGNMENT	: Lab 4
* FILE	 		: lab4_q3.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: October 20/14
* DESCRIPTION	: Write a program that reads an integer number n between 1 and
				  10 and generates n random values between 1 and 49.
	
				  Example:
				  Please enter an integer n between 1 and 10: 5
				  5 random numbers between 1 and 49 are: 34 21 33 22 40
*/


#include <stdio.h> // printf, scanf, NULL
#include <time.h>  // srand


// program entry
int main (void)
{
	int n = 0;
	int i = 0;
	
	printf("Please enter an integer n between 1 and 10: ");
	scanf("%d", &n);
	
	// initialize random seed. Use NULL to use the default initilizer 
    srand (time(NULL)); 
		 
	printf("%d random numbers between 1 and 49 are: ", n);
	for(; i < n; i++)
		printf("%d ", rand() % 49 + 1); // pick a random digit from 1 to 49	
		
	printf("\n\n");

    return 0;
}


//EOF
