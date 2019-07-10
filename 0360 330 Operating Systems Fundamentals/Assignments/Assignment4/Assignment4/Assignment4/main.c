/*
* PROJECT		: Assignment 4
* FILE			: main.c
* AUTHOR		: Jason Choquette 104337378
* DATE			: Februrary 10, 2018
* DESCRIPTION	: Assume that a system has a 32-bit virtual address with a 4-KB 
				  page size. Write a C program that is passed a virtual address 
				  (in decimal) on the command line and have it output the page 
				  number and offset for the given address. 
				  
				  As an example, your program would run as follows:

					./a.out 19986
					and the program would output:
					The address 19986 contains:
					Page number = 4
					Offset = 3602

				  Writing this program will require using the appropriate data
				  type to store 32 bits. We encourage you to use unsigned data 
				  types as well. All calculations should be performed as fast 
				  as possible (i.e., nearly in real time). 
				  
				  For this purpose, the use of left/right shift and/or mask 
				  operators in C (or equivalent) is required.

				  Run your program with 5 different virtual addresses and show 
				  the results in your report.

				  2. Change your program to generate n random virtual addresses
				  between 0 and 232-1 and compute the page number and offset 
				  for each address – do not output anything on the console. 
				  
				  Run your program with n = 1,000,000 random addresses and 
				  compute the total CPU time. 
				  
				  In your report, show how you run it and comment on your 
				  results.
*/


#include "prototypes.h"



/******************************************************************************
FUNCTION		: main

DESCRIPTION		: This function is passed a virtual address 
				  (in decimal) on the command line and outputs the page 
				  number and offset for the given address. 

INPUT			: Type			: int
				: Description	: The number of arguments

				: Type			: char**
				: Description	: Program arguments (virtual address)

OUTPUT			: Type 			: int
				: Description	: The programs return value.
******************************************************************************/
int main(int argc, char ** argv)
{	
	unsigned int virtual_address = (unsigned int) atoll(argv[1]); 
	unsigned int page_number     = bitwiseDivision(virtual_address, PAGE_SIZE);
	unsigned int offset	         = bitwiseMod(virtual_address, PAGE_SIZE);

	printf("\nThe address %lu contains:\n", virtual_address);
	printf("Page number =  %lu\n", page_number);
	printf("Offset =  %lu\n\n", offset);

	// seed prng
	srand((unsigned int)time(NULL));	
	
	// begin timer 
	clock_t t1 = clock();
	int i;
	int n = 1000000;
	for (i = 0; i < n; i++)
	{
		virtual_address = rand(); // rand() range is 0 - 2^32 - 1
		bitwiseDivision(virtual_address, PAGE_SIZE);
		bitwiseMod(virtual_address, PAGE_SIZE);
	}	
	
	// calculate elapsed time
	t1 = clock() - t1;
	printf("It took me %d clicks (%f seconds) to generate 1,000,000 virtual addresses.\n\n\n", t1, 
		((float)t1) / CLOCKS_PER_SEC);
	
	return 0;
}