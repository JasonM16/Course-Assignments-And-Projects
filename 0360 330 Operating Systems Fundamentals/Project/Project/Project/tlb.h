#ifndef TLB_H		

#define TLB_H


#include "Constants.h"
#include "Addresses.h"


typedef struct
{
	page_t  page_num;
	frame_t frame_num;
	bool    valid;
} tlb_entry;


typedef struct
{
	tlb_entry    tlb_entry[TLB_SIZE];
	unsigned int next_tlb_ptr;
} tlb_t;


#endif

