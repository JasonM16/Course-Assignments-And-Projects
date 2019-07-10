/*
 * PROJECT:     Assignment 1
 * FILE:        main.c
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 15, 2018
 * DESCRIPTION: Program entry
 */


#include "protoypes.h"


int main() { return run(); }




/******************************************************************************
FUNCTION		: run

DESCRIPTION		: This function contains all of the logic to perform a file copy.

INPUT			: Type			: void
				: Description	: N/A

OUTPUT			: Type 			: int
				: Description	: exit code
******************************************************************************/
int run()
{
	// input and output filenames 
	char * fileName;
	// pointer to reference the file names
	char * f;
	// File pointers for input/output files
	FILE * fpInput = NULL;
	FILE * fpOutput = NULL;	

	// allocate memory 
	if (((f = (char *)malloc(MAX_BUFFER)) == NULL))
	{
		printf("Error allocating memory. Aborting.../n");
		return -1;
	}		
	
	// get input file name
	fileName = getFileName("input");
	// copy input file name
	strncpy_s(f,256, fileName, MAX_BUFFER);	

	// get input file pointer
	if (!(fpInput = getFilePointer(f, INPUT))) return -1;

	// reset/clear memory
	memset(f, 0, MAX_BUFFER);

	// get output file name
	fileName = getFileName("output");
	// copy output file name
	strncpy_s(f, 256, fileName, MAX_BUFFER);	

	// get input file pointer
	if (!(fpOutput = getFilePointer(f, OUTPUT))) return -1;

	// release memory pointer
	free(f);

	// copy contents from input file to output file
	copyContents(&fpInput, &fpOutput);
	
	// release file pointers
	fclose(fpInput);
	fclose(fpOutput);

	printf("File copied successfully.\n");
	return 0;
}