/*
* PROJECT:     Assignment 1
* FILE:        fileUtilities.c
* AUTHOR:      Jason Choquette 104337378
* DATE:        January 15, 2018
* DESCRIPTION: This file contains function definitions for getFileName and
			   getFilePointer.
*/

#include "protoypes.h"

/******************************************************************************
FUNCTION		: getFileName

DESCRIPTION		: This function prompts the user for input and validates the 
			      user input.

INPUT			: Type			: char *
				: Description	: describes either an "input" or "output" file
								  type.

OUTPUT			: Type 			: char *
				: Description	: returns a formatted file name.
******************************************************************************/
char * getFileName(char * fileType)
{
	char buffer[MAX_BUFFER];

	// prompt the user to enter a file name
	printf("Please enter the name of the %s file: \n", fileType);
	char * fileName = fgets(buffer, sizeof(buffer), stdin);

	// ensure user does not enter an empty string
	while (fileName == NULL || strcmp(fileName, "") == 0)
	{
		fileName = fgets(buffer, sizeof(buffer), stdin);		
		printf("Invalid filename. Please ensure you entered correct filename. /n");
	}

	// return file name without newline character	
	return strtok(buffer, "\n"); 
}




/******************************************************************************
FUNCTION		: getFilePointer

DESCRIPTION		: This function contains all of the logic to perform a file copy.

INPUT			: Type			: const char *
				: Description	: N/A

OUTPUT			: Type 			: FILE *
				: Description	: N/A
******************************************************************************/
FILE * getFilePointer(const char * fileName, int fileType)
{	
	char buffer[MAX_BUFFER];
	FILE* fp = NULL;

	// format current file location
	strncpy_s(buffer, MAX_BUFFER, "../", 3);
	strcat_s(buffer, MAX_BUFFER, fileName);		

	// for input file type
	if (fileType == INPUT)
	{
		// if input file doesn't exist, abort program...
		if (!(fp = fopen(buffer, "r")))
		{
			printf("Source file does not exist. Aborting...");
			fp = NULL;
		}			
	}			
	// for output file type
	else if (fileType == OUTPUT)
	{
		// if the output file exists, abort program...
		if (fp = fopen(buffer, "r"))
		{
			printf("Destination file already exists. Aborting...");
			fp = NULL;
		}
		else
			fp = fopen(buffer, "w");				
	}		

	return fp;
}