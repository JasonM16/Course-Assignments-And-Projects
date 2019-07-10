/*
* ASSIGNMENT	: Lab 4
* FILE	 		: lab4_q4.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: October 20/14
* DESCRIPTION	: Write a program that can read an integer n between 1 and 10
				  and generates the following art:
	
				  Example:

				  Please enter an integer between 1 and 10: 6
				  * * * * * *
				  * * * * * *
				  * * * * * *
				  * * * * * *
				  * * * * * *
				  * * * * * *
				  *
				  **
				  ***
				  ****
				  *****
				  ******
*/


#include <stdio.h> // printf, scanf


// program entry
int main (void)
{
	int n = 0;
	int i = 0;
	int j = 0;
		
	printf("Please enter an integer n between 1 and 10: ");
	scanf("%d", &n);

	for(; i < n; i++)
	{
		for(; j < n; j++)
			printf("*");
				
		j = 0;
		printf("\n");		
	}	

	printf("\n");
	i = 1;
	j = 0;	

	for(; i <= n; i++)
	{
		for(; j < i; j++)
			printf("*");
				
		j = 0;
		printf("\n");		
	}	
	
	printf("\n\n");

    return 0;
}


// EOF
