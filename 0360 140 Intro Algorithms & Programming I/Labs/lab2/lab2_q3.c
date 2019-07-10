/*
* ASSIGNMENT	: Lab 2
* FILE	 		: lab2_q3.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: September 28/14
* DESCRIPTION	: Write a program that reads in two integers and determines 
				  and prints if the first is a multiple of the second

				  Example:
				  Please enter two integer: 15 5
				  15 is a multiple of 5

				  Please enter two integer: 11 5
				  11 is not a multiple of 5
*/


#include <stdio.h> // printf, scanf, getchar


// program entry
int main(void)
{
	// used to store the user's two numbers
    int num1 = 0;
    int num2 = 0;
    
    
    printf("Please enter two integers: ");
 
    // input
    scanf("%d %d", &num1, &num2);

    printf("%d is ", num1);

	// use modulus operator to determine if multiple
    if(num1 % num2 != 0)
    {
		printf("not ");
    }

    printf("a multiple of %d\n\n", num2);   

	// ensure the user can see the printed results
	getchar();
	
    return 0;
}


// EOF