/*
* PROJECT:     Assignment 1
* FILE:        copyFileContents.c
* AUTHOR:      Jason Choquette 104337378
* DATE:        January 15, 2018
* DESCRIPTION: This file contins the definition for the copyContents
			   function.
*/


#include "protoypes.h"


/******************************************************************************
FUNCTION		: copyContents

DESCRIPTION		: This function contains all of the logic to perform a file copy.

INPUT			: Type			: FILE **
				: Description	: pointer to the input FILE *

OUTPUT			: Type 			: FILE **
				: Description	: pointer to the output FILE *
******************************************************************************/
void copyContents(FILE ** in, FILE ** out)
{	
	char c = fgetc(*in);
	while (c != EOF)
	{
		fputc(c, *out);
		c = fgetc(*in);
	}
}