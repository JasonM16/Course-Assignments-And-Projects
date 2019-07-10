/*
* ASSIGNMENT	: Lab 4
* FILE	 		: lab4_q2.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: October 20/14
* DESCRIPTION	: Write a program that can read two integers n and m between 1
				  and 100, such that n < m. Then display the following sequences:
				  s1. n n+1 n+2 ... m
				  s2. all odd numbers between n and m
				  s3. all multiples of 5 between n and m
				  s4. all numbers from m down to n

				  Examples:
				  Please enter an integer value for n and m (n < m): 4 3
				  Invalid input. Goodbye.

				  Please enter an integer value for n and m (n < m): 6 16
				  6 7 8 9 10 11 12 13 14 15 16
				  7 9 11 13 15
				  10 15
				  16 15 14 13 12 11 10 9 8 7 6
*/


#include <stdio.h> // printf, scanf


// program entry
int main (void)
{	
	int n = 0;
	int m = 0;
	
	while (1)
	{		
		printf("Please enter an integer value for n and m (n < m): ");	
		scanf("%d %d", &n, &m);
		
		if(n > m)
		{
			printf("Invalid input. Goodbye.");
			break;
		}	
				
		else
		{				
			int i = n;
					
			for(;i <= m; i++)
				printf("%d ", i);
						
			printf("\n");
						
			// print odds
			i = n;
			// if i is even
			// make it odd
			if (i % 2 == 0) i += 1;
			
			for(; i <= m; i += 2)
				printf("%d ", i);			
						
			printf("\n");
						
			// print multiples of 5
			i = n;
			// find the first multiple of 5
			// this will loop at most 4 times
			while(i % 5 != 0)
				i++;
						
			// i is now a multiple of 5 so we can increment by 5
			// and be guaranteed to print multiples of 5
			for(; i <= m; i += 5)
				printf("%d ", i);			
						
			printf("\n");
			
			i = m;
			for(; i >= n; i--)
				printf("%d ", i);			
						
			printf("\n\n");
			break;
		}		
	}
		
    return 0;
}


// EOF
