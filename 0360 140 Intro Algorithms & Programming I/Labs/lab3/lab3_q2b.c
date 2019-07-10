/*
 * ASSIGNMENT	: Lab 3
 * FILE	 		: lab3_q2b.c
 * AUTHOR		: Jason Choquette
 * ID			: 104337378
 * DATE			: October 06/14
 * DESCRIPTION	: This program will read a single character from the 
				  user as follows:

				  ‘y’ or ‘Y’ for YES
				  ‘n’ or ‘N’ for NO
				  Invalid entry otherwise
 
				  Example: (this output is based on a single run!)
				  
				  Please answer with yes or no: b
				  You entry is invalid!!!
				  
				  Please answer with yes or no: N
				  You responded No!
 */


#include <stdio.h> // printf, getchar


// program entry
int main (void)
{
	// loop forever. Program will break on valid user input
	while(1)
	{
		printf("\n\nPlease answer with yes or no: ");

		// get a single charachter from the console
		char input = getchar();
		    
		if (input == 'y' || input == 'Y')
		{
			printf("You responded Yes!");    
			break;
		}
		else if (input == 'n' || input == 'N')
		{
			printf("You responded No!");    
			break;
		}
		else
		{
			printf("Your entry is invalid!!!");    
		}
	}
	
	printf("\n\n");

	return 0;
}


// EOF