/*
* PROJECT		: Course Project
* FILE			: tlb_insert.c
* AUTHOR		: Jason Choquette 104337378
* DATE			: March 13, 2018
* DESCRIPTION	: This file contains the function to read from a simulated
*				  hard drive back-up.
*/


#include "prototypes.h"





/******************************************************************************
FUNCTION		: tlb_insert

DESCRIPTION		: This function represents an insertion of a page and frame 
				  number into a simulated tlb.

INPUT			: Type			: int
				: Description	: The page number.

				: Type			: int
				: Description	: The frame number.

OUTPUT			: Type 			: void
				: Description	: N/A
******************************************************************************/
void tlb_insert(const int page_number, const int frame_number)
{    
	int i;
	
	// if it's already in the TLB, break
	for (i = 0; i < number_of_tlb_entries; i++)
		if(tlb_page_number[i] == page_number) 
			break;    
	
	// if the number of entries is equal to the index
	if (i == number_of_tlb_entries)
	{
		if (number_of_tlb_entries < TLB_SIZE)
		{   
			// the TLB still has room in it
			tlb_page_number[number_of_tlb_entries]  = page_number;    	// insert the page and frame onto the end of the array
			tlb_frame_number[number_of_tlb_entries] = frame_number;
		}

		// otherwise move everything over by 1
		else
		{
			for (i = 0; i < TLB_SIZE - 1; i++)
			{
				tlb_page_number[i]  = tlb_page_number[i + 1];
				tlb_frame_number[i] = tlb_frame_number[i + 1];
			}

			// and insert the page and frame on the end
			tlb_page_number[number_of_tlb_entries-1]  = page_number;	
			tlb_frame_number[number_of_tlb_entries-1] = frame_number;
		}        
	}			
	else
	{
		// iterate through up to one less than the number of entries
		for (; i < number_of_tlb_entries - 1; i++)      
		{
			// move everything over in the arrays
			tlb_page_number[i]  = tlb_page_number[i + 1];				
			tlb_frame_number[i] = tlb_frame_number[i + 1];
		}

		// if there is still room in the array, put the page and frame on the end
		if (number_of_tlb_entries < TLB_SIZE)							
		{
			tlb_page_number[number_of_tlb_entries]  = page_number;
			tlb_frame_number[number_of_tlb_entries] = frame_number;
		}

		// otherwise put the page and frame on the number of entries - 1
		else															
		{
			tlb_page_number[number_of_tlb_entries-1]  = page_number;
			tlb_frame_number[number_of_tlb_entries-1] = frame_number;
		}
	}

	// if there is still room in the arrays, increment the number of entries
	if (number_of_tlb_entries < TLB_SIZE)								
		number_of_tlb_entries++;    
}