/*
 * ASSIGNMENT	: Lab 3
 * FILE	 		: lab3_q1b.c
 * AUTHOR		: Jason Choquette
 * ID			: 104337378
 * DATE			: October 06/14
 * DESCRIPTION	: Write a program that prompts the user to enter an integer 
				  number between 1 and 10. The program will validate the 
				  input and print proper messages.
				  
				  Example: (this output is based on a single run!)
				  
				  Please enter an integer between 1 and 10: 15
				  You have entered an invalid entry!!!

				  Please enter an integer between 1 and 10: 11
				  You have entered an invalid entry!!!

				  Please enter an integer between 1 and 10: 8
				  You have entered a valid entry, Goodbye!
 */


#include <stdio.h> // scanf, printf


// program entry
int main (void)
{
	int input = 0;

	// loop forever. Program will break on valid user input
	while(1)
	{
		printf("\n\nPlease enter an integer between 1 and 10: ");

		// input
		scanf("%d", &input);
		
		printf("You have entered ");
		
		if (input <= 10)
		{
			printf("a valid entry, Goodbye!");    
			break;
		}
		else
		{
			printf("an invalid entry!!!");    
		}
	}
	
	printf("\n\n");

	return 0;
}


// EOF