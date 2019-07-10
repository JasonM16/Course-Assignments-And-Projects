/*
* PROJECT		: Course Project
* FILE			: main.c
* AUTHOR		: Jason Choquette 104337378
* DATE			: March 13, 2018
* DESCRIPTION	: This file is the main driver of the project; along with 
*				  some utility functions.
*/


#include "prototypes.h"





/******************************************************************************
FUNCTION		: main

DESCRIPTION		: This function is passed a text file with virtual addresses 
				  (in decimal) on the command line and outputs the page 
				  number and offset for the given addresses. 

INPUT			: Type			: int
				: Description	: The number of arguments.

				: Type			: char**
				: Description	: Program arguments (virtual address file).

OUTPUT			: Type 			: int
				: Description	: The programs return value.
******************************************************************************/
int main(const int argc, char *argv[])
{
	
	
	backing_store_name = "BACKING_STORE.bin";
	int number_of_translated_addresses = 0;
	tlb_hits = 0;
	
	if (argc != 2)
	{
		fprintf(stderr,"Usage: ./a.out [input file]\n");
		return -1;
	}	
	
	if(!valid_file_input(backing_store = fopen(backing_store_name, "rb"), backing_store_name)) return -1;	
	if(!valid_file_input(address_file  = fopen(argv[1], "r"), argv[1])) return -1;	

	process_addresses(address_file, &number_of_translated_addresses);		
	print_main_results(number_of_translated_addresses);	
	
	// close the input file and backing store
	fclose(address_file);
	fclose(backing_store);
	
	return 0;
}





/******************************************************************************
FUNCTION		: valid_file_input

DESCRIPTION		: This function validates file input.

INPUT			: Type			: FILE *
				: Description	: The pointer to a file.

				: Type			: char*
				: Description	: The file name to print.

OUTPUT			: Type 			: bool
				: Description	: True if valid file pointer, false otherwise.
******************************************************************************/
bool valid_file_input(FILE * file, const char * file_name)
{
	if (file == NULL)
	{
		fprintf(stderr, "Error opening %s\n", file_name);
		return FALSE;
	}
	return TRUE;
}





/******************************************************************************
FUNCTION		: process_addresses

DESCRIPTION		: This function reads through a file of logical addresses and 
				  then searches for a page in a simulated tlb and page table.

INPUT			: Type			: char *
				: Description	: The logical addresses to be processed.

				: Type			: File *
				: Description	: The pointer to address file.

				: Type			: int *
				: Description	: A counter for the number of addresses translated.

OUTPUT			: Type 			: int
				: Description	: The programs return value.
******************************************************************************/
void process_addresses(FILE * address_file, int * number_of_translated_addresses)
{
	char address[MAX_BUFFER_SIZE];
	// read through the input file and output each logical address
	while ( fgets(address, MAX_BUFFER_SIZE, address_file) != NULL)
	{		
		// get the physical address and value stored at that address
		find_page(atoi(address));
		*number_of_translated_addresses += 1;  
	}
}





/******************************************************************************
FUNCTION		: print_main_results

DESCRIPTION		: This function simply prints the results of the translations
				  and some program statistics.

INPUT			: Type			: int
				: Description	: The number of addresses that have been
								  translated.

OUTPUT			: Type 			: void
				: Description	: N/A
******************************************************************************/
void print_main_results(const int number_of_translated_addresses)
{
	// calculate and print out the stats
	printf("Number of translated addresses = %d\n", number_of_translated_addresses);
	const double pf_rate  = page_faults / (double)number_of_translated_addresses;
	const double tlb_rate = tlb_hits    / (double)number_of_translated_addresses;
	
	printf("Page Faults     = %d\n",   page_faults);
	printf("Page Fault Rate = %.3f\n", pf_rate);
	printf("TLB Hits        = %d\n",   tlb_hits);
	printf("TLB Hit Rate    = %.3f\n", tlb_rate);
}