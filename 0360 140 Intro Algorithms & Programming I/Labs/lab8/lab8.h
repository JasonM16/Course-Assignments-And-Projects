/*
* ASSIGNMENT	: Lab 8
* FILE	 		: lab8.h
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: November 18/14
* DESCRIPTION	: This file contains all the program dependencies, constants and
				  function prototypes for the program. For more details about
				  the functions, see lab8.c
*/


// program dependencies
#include <stdio.h>  // printf, scanf, NULL
#include <time.h>   // time
#include <stdlib.h> // rand, srand

// Constants
#define MAX 10

// type definitions
typedef int ARRAY[MAX];

// function prototypes
int  BinarySearch(ARRAY *a, int size, int key); 
void BubbleSort(ARRAY *a, int size, int order); 
void Compare(ARRAY *a, int j, int comparer);
int  GetNumber(int min, int max);
void InitArray(ARRAY  *a, int size, int n);
void PopulateArray(ARRAY *a, int size);
void PrintArray(ARRAY *a, int size);
void RunMenu(void);
void Swap(ARRAY *a, int j);
