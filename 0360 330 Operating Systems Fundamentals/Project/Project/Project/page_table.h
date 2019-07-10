#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H


//typedef unsigned int page_table_t;

typedef unsigned int physical_memory_t;

typedef unsigned int value_t;

typedef unsigned int address_value_list_t;

typedef struct
{
	page_t page_num;
} page_table_t;

#endif
