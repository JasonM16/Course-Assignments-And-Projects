/*
* ASSIGNMENT	: Assignment 3
* FILE	 		: assign3.h
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: November 19/14
* DESCRIPTION	: This file contains all the program dependencies, constants and
				  function prototypes for the program. For more details about 
				  the functions, see assign3.c
*/


// program dependencies
#include <stdio.h>   // printf, scanf
#include <stdbool.h> // bool

// Constants
#define MAX_SIZE 200

// type definitions

// this type will be used to represent a switchboard of callers.
typedef int SwitchBoard[MAX_SIZE]; 


// function prototypes
void InitSwitchBoard(SwitchBoard *s, int n);
void MoveNext(SwitchBoard *s, int * currentPosition);
int GetCaller(SwitchBoard *s, int n, int m, int k);
int GetCaller2(SwitchBoard *s, int n, int m, int k);
bool Valid(int n, int m, int k);




