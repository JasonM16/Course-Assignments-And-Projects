/*
 * ASSIGNMENT	: Lab 3
 * FILE	 		: lab3_q2.c
 * AUTHOR		: Jason Choquette
 * ID			: 104337378
 * DATE			: October 06/14
 * DESCRIPTION	: This program will read a single character from the 
				  user as follows:
				  
				  - ‘y’ or ‘Y’ for YES
				  - ‘n’ or ‘N’ for NO
				  - Invalid entry otherwise

				  Examples:

				  Please answer with yes or no: y
				  You responded Yes! 

				  Please answer with yes or no: N
				  You responded No! 

				  Please answer with yes or no: s
				  Your entry is invalid!!! 
 */


#include <stdio.h> // printf, getchar


// program entry
int main (void)
{

	printf("\n\nPlease answer with yes or no: ");

	// get a single charachter from the console
    char input = getchar();
        
    if (input == 'y' || input == 'Y')
    {
    	printf("You responded Yes!");    
    }
    else if (input == 'n' || input == 'N')
    {
    	printf("You responded No!");    
    }
    else
    {
    	printf("Your entry is invalid!!!");    
    }

	printf("\n\n");

	return 0;
}


// EOF