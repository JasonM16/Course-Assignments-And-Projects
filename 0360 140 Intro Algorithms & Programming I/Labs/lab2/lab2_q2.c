/*
* ASSIGNMENT	: Lab 2
* FILE	 		: lab2_q2.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: September 28/14
* DESCRIPTION	: This program reads an integer and determines and prints 
		 		  whether it is odd or even.

				  Example:
				  Please enter an integer: 5
				  5 is odd!
*/


#include <stdio.h> // printf, scanf, getchar


// program entry
int main(void)
{
	// used to store the user's number
    int num = 0;
    
    printf("Please enter an integer: ");
    
    // input
    scanf("%d", &num);

    printf("%d is ", num);
    
    // if the number is even, print even
    if(num % 2 == 0)
    {
		printf("even!\n");
    }
    // if not print false
    else
    {
		printf("odd!\n");
    }

    printf("\n");

	// ensure the user can see the printed results
	getchar();
	
    return 0;
}


// EOF