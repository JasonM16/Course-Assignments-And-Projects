/*

* ASSIGNMENT	: Lab 5
* FILE	 		: lab5_q4.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: October 27/14
* DESCRIPTION	: This function takes as input two parameters: the first
				  parameter is a positive integer L (length of a side), and the
				  second parameter a char type indicating the symbol s to
				  be used. The function draws an L x L square of s. 

				  Example:
				  Please enter a positive integer for L: 6

				  Please enter a symbol (single char): *

				  ******
				  ******
				  ******
				  ******
				  ******
				  ******
*/


#include <stdio.h> // printf, scanf, getchar
#include <string.h>


// function prototypes
void DrawSquare(int, char);
void DrawBorder(int, char);
void DrawBorders(int, char);
void DrawCircle(int, char);

// program entry
int main (void)
{
	int length = 0;
	char symbol = '*';
		
	printf("Please enter a positive integer for L: ");
	scanf("%d", &length);
	
	printf("\nPlease enter a symbol (single char): ");
	symbol = getchar();
	symbol = getchar();
	 
	printf("\n\n");
	
	DrawSquare(length, symbol);
	DrawBorder(length, symbol);
	DrawBorders(length, symbol);
	//DrawCircle(length, symbol);


	return 0;
}



void DrawSquare(int length, char symbol)
{
	int i = 0;
	int j = 0;
	
	for(; i < length; i++)
	{
		for(; j < length; j++)
		{
			printf("%c ", symbol);
		}	
		
		j = 0;
		printf("\n");
	}
	
	printf("\n\n");
}





void DrawBorder(int length, char symbol)
{
	int i = 0;
	int j = 0;
	int height = length;
	
	
	// first and last run will fill an entire line
	for(; i < length; i++)
	{
		printf("%c ", symbol);
	}
	
	printf("\n");	
	height--;
	i = 0;
	
	while(height > 1)
	{
		// print the first character on left, skip length - 2, then print the character again
		printf("%c ", symbol);
				
		for(; i < length - 2; i++)
		{
			printf("  ");
		}
		
		printf("%c\n", symbol);
		
		height--;
		i = 0;
	}	
	
	i = 0;
	
	for(; i < length; i++)
	{
		printf("%c ", symbol);
	}
	
	
	printf("\n\n");
}





void DrawBorders(int length, char symbol)
{
	int i = 0;
	int j = 0;
	int min_square = 3;
	char x = 'x';
	
	length = 7;
		
	int height = length;
	
	
	// has to be minus 2 on each side in order to look correct. Ensure length > 5 before running
	// first and last run will fill an entire line
	for(; i < length; i++)
	{
		printf("%c ", symbol);
	}
	
	printf("\n");	
	height--;
	i = 0;
	
	while(height > 1)
	{
		// print the first character on left, skip length - 2, then print the character again
		printf("%c ", symbol);
				
		for(; i < length - 2; i++)
		{
			printf("  ");
		}
		
		printf("%c\n", symbol);
		
		height--;
		i = 0;
	}	
	
	i = 0;
	
	for(; i < length; i++)
	{
		printf("%c ", symbol);
	}
	
	
	printf("\n\n");
	
	
	for(; i < length; i++)
	{
		
	
	}
		
	for(; i < min_square; i++)
	{
		printf("%c ", symbol);			
	}
	i = 0;
	printf("\n");
	printf("%c ", symbol);			
	printf("%c ", x);			
	printf("%c ", symbol);			
	printf("\n");
	
	for(; i < 3; i++)
	{
		printf("%c ", symbol);			
	}
	i = 0;
	
	

	
	/*
	
	// first and last run will fill an entire line
	for(; i < length; i++)
	{
		printf("%s ", symbol);
	}
	
	printf("\n");	
	height--;
	i = 0;
	
	while(height > 1)
	{
		// print the first character on left, skip length - 2, then print the character again
		printf("%s ", symbol);
				
		for(; i < length - 2; i++)
		{
			printf("  ");
		}
		
		printf("%s\n", symbol);
		
		height--;
		i = 0;
	}	
	
	i = 0;
	
	for(; i < length; i++)
	{
		printf("%s ", symbol);
	}
	
	*/
	printf("\n\n");
}


void DrawCircle(int length, char symbol)
{
    int i = 0;
    int j = 0;
	     
    for(i=-length;i<length;i++)
    {
        for(j=-length;j<length;j++)
        {
            if(i*i+j*j<length*length)
                printf("%c", symbol);
            else
                printf(" ");
                 
        }
        printf("\n");
    }
}


// EOF
