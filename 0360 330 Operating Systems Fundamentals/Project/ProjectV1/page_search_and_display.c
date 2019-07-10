/*
* PROJECT		: Course Project
* FILE			: page_search_and_display.c
* AUTHOR		: Jason Choquette 104337378
* DATE			: March 13, 2018
* DESCRIPTION	: This file contains the functions to search the tlb and page
*				  table for a given page. It also prints out the virtual
*				  addresses and offset, etc.
*/


#include "prototypes.h"





/******************************************************************************
FUNCTION		: find_page

DESCRIPTION		: This function searches the TLB for the page number (extracted
				  from the logical address). If the page is not in the TLB, then
				  the page table is searched. 
				  If not found in the page table, then a (hypothetical) page 
				  fault is raised, and then the backing store is searched.
				  Once found in the backing store, the page uses a FIFO replacement
				  into the tlb.

INPUT			: Type			: int
				: Description	: The logical address.

OUTPUT			: Type 			: void
				: Description	: N/A
******************************************************************************/
bool find_page(const int logical_address)
{  
	// obtain the page number and offset from the logical address
	const int page_number  = ((logical_address & ADDRESS_MASK) >> 8);
	const int offset       =  (logical_address & OFFSET_MASK);
	bool page_fault_raised = FALSE;
	bool page_found        = FALSE;
	int frame_number       = -1;

	// first try to get page from TLB
	search_tlb(page_number, &page_found, &frame_number);
	
	// if the frame number was not found in tlb, search the page_table...
	if(!page_found)
		search_page_table(page_number, &frame_number, &page_fault_raised);

	if(page_fault_raised)
	{
		read_from_store(page_number);             						                       					
		frame_number = first_available_frame - 1; // set the frameNumber to the current firstAvailableFrame index
		tlb_insert(page_number, frame_number);  
	}	
	
	// frame number and offset used to get the signed value stored at that address							
	const signed char value = physical_memory[frame_number][offset];  	
	printf("Virtual address: %d Physical address: %d Value: %d\n", logical_address, (frame_number << 8) | offset, value);
	return page_fault_raised;
}





/******************************************************************************
FUNCTION		: search_tlb

DESCRIPTION		: This function searches the simulated tlb for a page and frame.
				  If the page is found in the tlb, the tlb hit counter is 
				  increased and a flag is set to indicate that the page was
				  found in the tlb.

INPUT			: Type			: int
				: Description	: The logical address.

OUTPUT			: Type 			: void
				: Description	: N/A
******************************************************************************/
void search_tlb(const int page_number, bool * page_found, int * frame_number)
{
	
	for (int i = 0; i < TLB_SIZE; i++)
		if(tlb_page_number[i] == page_number)							
		{   
			*frame_number = tlb_frame_number[i];  						
			tlb_hits++;      
			*page_found = TRUE;
		}				
}





/******************************************************************************
FUNCTION		: search_page_table

DESCRIPTION		: This function the page table for a given page. If the page is 
				  found, the frame is updated.
				  If the page is not found, a page fault is raised.

INPUT			: Type			: int
				: Description	: The page number to find.

				: Type			: int *
				: Description	: The frame number.

				: Type			: bool *
				: Description	: The page fault flag.


OUTPUT			: Type 			: void
				: Description	: N/A
******************************************************************************/
void search_page_table(const int page_number, int * frame_number, bool * page_fault_raised)
{	
	for (int i = 0; i < first_available_page_table_number; i++)
		if(page_table_numbers[i] == page_number)	// if the page is found in those contents
			*frame_number = page_table_frames[i];	// extract the frame number 

	if(*frame_number == -1)                     						
	{
		*page_fault_raised = TRUE;
		page_faults++;   
	}	
}