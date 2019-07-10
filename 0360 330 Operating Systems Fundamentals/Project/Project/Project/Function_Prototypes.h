
#ifndef FUNCTION_PROTOTYPES
#define FUNCTION_PROTOTYPES



/* see function 3 in Lec14c-Project 5 Data Structures Exercise Handout */
#include "Addresses.h"
#include "tlb.h"
#include "page_table.h"


/* Purpose: read a list of logical addresses from an input file. */
int logical_address_loader(char * file_name, logical_address_t logical_address_list[1000]);


int extract_logical_address(logical_address_t logical_address, int * page_number, int * offset);


/* see function 3 in Lec14c-Project 5 Data Structures Exercise Handout */
int search_TLB(page_t p_num, tlb_t tlb, bool *is_tlb_hit, frame_t *f_num);


/* see function 4 in Lec14c-Project 5 Data Structures Exercise Handout */
int search_page_table(page_t p_num, page_table_t p_table, bool *is_page_fault, frame_t *f_num);


/*
* see function 5 in Lec14c-Project 5 Data Structures Exercise Handout
* Attention: The prototype has been changed by adding frame_number as
* an input parameter.
*/
int page_fault_handler(page_t p_num, frame_t frame_num, physical_memory_t *physical_mem, page_table_t *p_table, tlb_t *tlb);


/* see function 6 in Lec14c-Project 5 Data Structures Exercise Handout */
physical_address_t create_physical_address(frame_t f_num, offset_t off, physical_address_t *physical_addr);


/* see function 7 in Lec14c-Project 5 Data Structures Exercise Handout */
int read_physical_memory (physical_address_t p_addr, physical_memory_t physical_mem, value_t *value);

/* see function 8 in Lec14c-Project 5 Data Structures Exercise Handout */
void update_address_value_list(logical_address_t l_addr, physical_address_t p_addr, value_t value, address_value_list_t *addr_value_list);


/* see function 9 in Lec14c-Project 5 Data Structures Exercise Handout */
void output_address_value_list(const char *output_file_name, address_value_list_t addr_value_list);

/* see also Lec16a-Project 5 LRU Implementation Draft.pdf */
int TLB_replacement_LRU(page_t p_num, frame_t f_num, tlb_t *tlb);

/*
* Get a page number from a logical address.
* Input: a logical address.
* Output: a page number
*/
int get_page_num(logical_address_t l_addr, page_t *p_num);

/*
* Get a page number from a logical address.
* Input: a logical address.
* Output: an offset
*/
int get_offset(logical_address_t l_addr, offset_t *off);


int init_tlb(tlb_t *tlb);
int diplay_tlb(tlb_t tlb);
int TLB_replacement_FIFO(page_t page_num, frame_t frame_num, tlb_t* tlb);


#endif