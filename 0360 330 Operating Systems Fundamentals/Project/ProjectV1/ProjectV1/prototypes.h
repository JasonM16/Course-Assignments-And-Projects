/*
* PROJECT		: Course Project
* FILE			: prototypes.h
* AUTHOR		: Jason Choquette 104337378
* DATE			: March 13, 2018
* DESCRIPTION	: Program prototypes and constants and header files.
*/




#ifndef _PROTOTYPES_H_
#define _PROTOTYPES_H_


#include <stdio.h>
#include <stdlib.h> // atoi


// Project Constants
#define FRAME_SIZE				256		// size of the frame
#define TOTAL_NUMBER_OF_FRAMES	256		// total number of frames in physical memory
#define ADDRESS_MASK			0xFFFF	// mask all but the address
#define OFFSET_MASK				0xFF	// mask all but the offset
#define TLB_SIZE				16		// size of the TLB
#define PAGE_SIZE				256		// size of the page table
#define MAX_BUFFER_SIZE			10		// max chars from input file



// global arrays
int physical_memory[TOTAL_NUMBER_OF_FRAMES][FRAME_SIZE];	
int tlb_page_number[TLB_SIZE];								
int tlb_frame_number[TLB_SIZE];								
int page_table_numbers[PAGE_SIZE];					
int page_table_frames[PAGE_SIZE];			



// global variables
int page_faults;											
int tlb_hits;												
int first_available_frame;									
int first_available_page_table_number;						
int number_of_tlb_entries;					



// global file pointers
const char * backing_store_name;
FILE       * backing_store;
FILE	   * address_file; 

typedef enum { FALSE, TRUE } bool;

// function prototypes
bool find_page(const int logical_address);
void read_from_store(const int page_number);
void tlb_insert(const int page_number, const int frame_number);
void search_tlb(const int page_number, bool * page_found, int * frame_number);
void search_page_table(const int page_number, int * frame_number, bool * page_fault_raised);
void print_main_results(int number_of_translated_addresses);
void process_addresses(FILE * address_file, int * number_of_translated_addresses);
bool valid_file_input(FILE * file, const char * file_name);

#endif _PROTOTYPES_H_