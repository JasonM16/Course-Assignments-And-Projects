


#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>
#include <limits.h>

#define NUMBER_OF_PAGES	256		// Total number of pages in virtual memory space.
#define NUMBER_FRAMES	256		// Total number of frames in physical memory space. 
#define PAGE_SIZE		256		// Number of bytes in a page/frame.
#define	TLB_SIZE	    16		// Number of entries in the TLB.
#define OFFSET_BITS		8		// Number of bits required to address a byte in a page
#define OFFSET_MASK		0xFF    // Bit mask to extract the offset from logical address.
const char backing_store[] = "BACKING_STORE.bin"; // Simulates hard drive or other backing device.

 typedef enum { FALSE, TRUE } bool;

#endif

