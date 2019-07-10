/*

* ASSIGNMENT	: Lab 4
* FILE	 		: lab4_q1.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: October 20/14
* DESCRIPTION	: Write a program that prompts the user to enter an integer 
				  number n between 1 and 10. The program then displays n 
				  asterisks. Note that the user will be given a maximum of 3
				  attempts to enter a valid code.

				  Example:
				  Please enter an integer between 1 and 10: 15
				  You have entered an invalid entry, 2 attempts left, try again!

				  Please enter an integer between 1 and 10: 5
				  5: *****

				  Another run:
				  Please enter an integer between 1 and 10: 15
				  You have entered an invalid entry, 2 attempts left, try again!

				  Please enter an integer between 1 and 10: 0
				  You have entered an invalid entry, 1 attempt left, try again!

				  Please enter an integer between 1 and 10: 11
				  You have entered an invalid entry! Goodbye!
*/


#include <stdio.h> // printf, scanf


// program entry
int main (void)
{
	
	int attempts = 3;
	int num = 0;
	
	while (1)
	{
		printf("Please enter an integer between 1 and 10: ");	
		scanf("%d", &num);
		
		if(num > 10 || num < 1)
		{
			--attempts;

			printf("You have entered an invalid entry");
			if(attempts == 0)
			{
				printf("! Goodbye!\n\n");
				break;
			} 
			else if (attempts > 1)
				printf(", %d attempts left, try again!\n\n", attempts);		
			
			else
				printf(", 1 attempt left, try again!\n\n");
			
			continue;			
		}
		
		else
		{
			int i = 0;
			printf("%d: ", num);
			
			for(;i < num; i++)
				printf("*");
						
			printf("\n\n");
			break;
		}		
	}
		
    return 0;
}


// EOF
