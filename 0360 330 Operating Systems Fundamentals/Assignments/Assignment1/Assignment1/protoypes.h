/*
* PROJECT:     Assignment 1
* FILE:        prototypes.h
* AUTHOR:      Jason Choquette 104337378
* DATE:        January 15, 2018
* DESCRIPTION: Contains prototypes, defintions and constants for the program.
*/

#pragma once

// header libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// constants
#define INPUT  0
#define OUTPUT 1
#define TRUE 1
#define FALSE 0
#define MAX_BUFFER 256

// function prototypes
void copyContents(FILE **, FILE **);
char * getFileName(char *);
FILE * getFilePointer(const char *, int);
int run();
