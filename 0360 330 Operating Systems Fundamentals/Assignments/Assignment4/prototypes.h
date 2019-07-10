/*
* PROJECT		: Assignment 4
* FILE			: prototypes.h
* AUTHOR		: Jason Choquette 104337378
* DATE			: Februrary 1, 2018
* DESCRIPTION	: Program prototypes and constants and header files.
*/


#ifndef _A4_PROTOTYPES
#define _A4_PROTOTYPES

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_BUFFER 40
#define PAGE_SIZE 4096


unsigned int bitwiseMod(unsigned int integrand, unsigned int divisor);
unsigned int bitwiseDivision(unsigned int dividend, unsigned int divisor);

#endif _A4_PROTOTYPES