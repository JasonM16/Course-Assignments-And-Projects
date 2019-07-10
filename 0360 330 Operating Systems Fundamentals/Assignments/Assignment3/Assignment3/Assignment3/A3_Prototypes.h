/*
* PROJECT		: Assignment 3
* FILE			: A3_Prototypes.h
* AUTHOR		: Jason Choquette 104337378
* DATE			: Feb. 4, 2018
* DESCRIPTION	: Function prototypes, Constants and header definitions for
				  Assignment
*/



#ifndef _A3_PROTOTYPES
#define _A3_PROTOTYPES

#include <stdio.h>		// printf()
#include <conio.h>		// _getch()
#include <windows.h>	// Mutex functions
#include <math.h>		// sqrt()
#include <time.h>		// timer
#include <omp.h>		// parallelism library

#define NUMBER_OF_SLAVES 40
#define NUMBER_OF_POINTS 1000000

HANDLE ghMutex;
DWORD hit_count;

double randomDouble();
double calculatePi(DWORD);

#endif  _A3_PROTOTYPES
