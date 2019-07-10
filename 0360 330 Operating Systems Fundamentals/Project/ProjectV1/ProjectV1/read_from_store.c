/*
* PROJECT		: Course Project
* FILE			: read_from_store.c
* AUTHOR		: Jason Choquette 104337378
* DATE			: March 13, 2018
* DESCRIPTION	: This file contains the function to read from a simulated
*				  hard drive back-up.
*/


#include "prototypes.h"





/******************************************************************************
FUNCTION		: read_from_store

DESCRIPTION		: This function simulates a read on a hard disk for paging.
				  A page is stored on the drive and is requested to be brought
				  into memory. The location of the page is known and therefore,
				  a seek is used to find the page.
				  The page table is updated with the new page number and frame.

INPUT			: Type			: int
				: Description	: The page number.

OUTPUT			: Type 			: void
				: Description	: N/A
******************************************************************************/
void read_from_store(const int page_number)
{
	// the buffer containing reads from backing store
	signed char buffer[PAGE_SIZE];	

	// first seek to byte PAGE_SIZE in the backing store
	// SEEK_SET in fseek() seeks from the beginning of the file
	if ( fseek(backing_store, page_number * PAGE_SIZE, SEEK_SET) != 0 )
		fprintf(stderr, "Error seeking in backing store\n");
	
	
	// now read PAGE_SIZE bytes from the backing store to the buffer
	if ( fread(buffer, sizeof(signed char), PAGE_SIZE, backing_store) == 0)
		fprintf(stderr, "Error reading from backing store\n");

	for(int i = 0; i < PAGE_SIZE; i++)
		physical_memory[first_available_frame][i] = buffer[i];    
	
	// and then load the frame number into the page table in the first available frame
	page_table_numbers[first_available_page_table_number] = page_number;
	page_table_frames[first_available_page_table_number] = first_available_frame;
	
	// increment the counters that track the next available frames
	first_available_frame++;
	first_available_page_table_number++;
}