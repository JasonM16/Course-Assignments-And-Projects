/*
 PROJECT		: Assignment 2
 FILE			: assignment2.c
 AUTHOR			: Jason Choquette, ID 104 337 378
 LAST MODIFIED	: Feb. 23, 2017
 DESCRIPTION	: This program enlarges a given P3 file.
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>


// used to define array size(s)
#define MAX_SIZE 4096

// represents a single pixel
typedef struct Pixel
{
	unsigned char red; // using usigned char since colors range from 0 to 255
	unsigned char green;
	unsigned char blue;
} Pixel;


// represents the Image of a .ppm file
typedef struct Image
{
	int 	width;
	int 	height;
	Pixel * pixel;

} Image;


// function prototype
void enlargeP3 (FILE *inFile, FILE *outFile);

int main(int argc, char *argv[])
{

	//Make sure the right number of arguments are supplied
	// per assignment requirements.
	if(argc != 3)
	{
		printf("usage: in-file.ppm out-file.ppm \n");
		return -1;
	}

	// open the files...
	FILE *inFile  = fopen(argv[1], "rb");
	FILE *outFile = fopen(argv[2], "wb");

	enlargeP3(inFile, outFile);

	// close the files...
	fclose(inFile);
	fclose(outFile);
	return 0;
}


/******************************************************************************
FUNCTION	: enlargeP3

DESCRIPTION	: This function enlarges a given ppm file and prints the result to 
			  a new ppm file.

INPUT		: Type			: FILE *
            : Description	: A pointer to the input file.

            : Type			: FILE *
            : Description	: A pointer to the output file.

OUTPUT		: Type 			: void
            : Description	: N/A
******************************************************************************/
void enlargeP3 (FILE *inFile, FILE *outFile)
{
	// variables
	char buff[MAX_SIZE], *fh;
	char colorBuffer[MAX_SIZE];
	Image image;
	int i;
	int j;
	int k;
	int status;
	unsigned int maxColors;
    pid_t pid;
    

    // ---------------------------- error handling ---------------------------
	fh = fgets(buff, MAX_SIZE, inFile);

	if((fh == NULL || strncmp(buff, "P3\n", 3) != 0))
		printf("Please provide a P3 .ppm file.");

	fh = fgets(buff, MAX_SIZE, inFile);

	//read in the width and height
	int read = sscanf(buff, "%u %u", &image.width, &image.height);

	//throw error if the width and height aren't in the file
	if(read < 2)
	{
		perror("File Unreadable. Please check the file format\n");
		return;
	}

	read = fscanf(inFile, "%u", &maxColors);
	
	//check that the right color format is used
	if(maxColors != 255 || read != 1)
	{
		perror("Please provide an 24-bit color file");
		return;
	}
	//-------------------------------------------------------------------------------------

	// allocate memory the the image pixels
	image.pixel = (Pixel *)malloc(sizeof(Pixel) * image.width * image.height);


	// get the color values from the in file and store them in the pixel struct
	for(i = 0; i < image.height * image.width; i++)
	{
		int colour;
		fscanf(inFile, "%d", &colour);
		image.pixel[i].red = colour;
		fscanf(inFile, "%d", &colour);
		image.pixel[i].green = colour;
		fscanf(inFile, "%d", &colour);
		image.pixel[i].blue = colour;
	}


	// this is the 4 x 4 array
	// fill a 2-d array....
	// this array will make it easier to build the new ppm file.
	Pixel pixelArray[image.height][image.width];
	i = 0;

	for(k = 0; k < image.height; k++)
	{
		for(j = 0; j < image.width; j++)
		{
			pixelArray[k][j] = image.pixel[i];
			i++;
		}

		j = 0;
	}


	int rows 	= image.height;
	int columns = image.width;

	// new dimensions will be image.width * 2 - 1 and image.height * 2 - 1
	// the -1 is because we only want new rows/columns in between existing
	// rows and columns.
	int newHeight = rows*2-1;
	int newWidth  = columns*2-1;


	// new rows and columns are offset by one
	int newColumn 	    = 1; 	
	int originalColumn 	= 0;	
	int newRow          = 1;	
	int originalRow     = 0;


	// temporary 2d pixel array
    Pixel temp[newHeight][newWidth];

	for (i = 0; i < rows; i++)
	{
		// new columns in between original columns
		for(j = 0; j < columns; j++)
		{
			if(originalRow == newHeight) break;	

			temp[originalRow][originalColumn].red   = pixelArray[i][j].red;
			temp[originalRow][originalColumn].green = pixelArray[i][j].green;
			temp[originalRow][originalColumn].blue  = pixelArray[i][j].blue;

			if(newColumn == newWidth) break;

			temp[originalRow][newColumn].red   = ((pixelArray[i][j].red   + pixelArray[i][j+1].red)   /2);
			temp[originalRow][newColumn].green = ((pixelArray[i][j].green + pixelArray[i][j+1].green) /2);
			temp[originalRow][newColumn].blue  = ((pixelArray[i][j].blue  + pixelArray[i][j+1].blue)  /2);

			originalColumn 	+= 2;
			newColumn 		+= 2;			
		}

		originalColumn = 0;
    	newColumn 	   = 1;    	
    	originalRow   += 2;
    	newRow 		  += 2;
    }

    
	// print ppm specifications to file.
	fprintf(outFile, "P3\n");	
	fprintf(outFile, "%u %u\n%u\n", newWidth, newHeight, maxColors);

	// flush outfile
	fflush(outFile);
	
	// ensure buffers are clear
	strcpy(buff, "");
	strcpy(colorBuffer, "");


	// final loop to calculate and print out new rows. 
	for (i = 0; i < newHeight; i++) 
	{		
		// Create a new process to calculate and print the next row
		if ((pid = fork()) < 0)
		{
			perror("fork could net be executed.\n");
		 	exit(1);
		}
		if (pid != 0)
		{
			
			fprintf(outFile, "%s", buff); // parent prints final row
		}
		
		else if (pid == 0)
		{

			

			if(i % 2 == 0)
			{				
				for(j = 0; j < newWidth; j++)
				{				
					sprintf(colorBuffer,"%d",temp[i][j].red); 
					strcat(buff, colorBuffer);
					strcat(buff, " ");
					strcpy(colorBuffer, "");

					sprintf(colorBuffer,"%d",temp[i][j].green); 
					strcat(buff, colorBuffer);
					strcat(buff, " ");
					strcpy(colorBuffer, "");

					sprintf(colorBuffer,"%d",temp[i][j].blue); 
					strcat(buff, colorBuffer);
					strcat(buff, " ");
					strcpy(colorBuffer, "");			
				}

				strcat(buff, "\n");


				for(j = 0; j < newWidth; j++)
				{				
					sprintf(colorBuffer,"%d",((temp[i][j].red + temp[i+2][j].red)/2)); 
					strcat(buff, colorBuffer);
					strcat(buff, " ");
					strcpy(colorBuffer, "");

					sprintf(colorBuffer,"%d",((temp[i][j].green + temp[i+2][j].green)/2)); 
					strcat(buff, colorBuffer);
					strcat(buff, " ");
					strcpy(colorBuffer, "");

					sprintf(colorBuffer,"%d",((temp[i][j].blue + temp[i+2][j].blue)/2)); 
					strcat(buff, colorBuffer);
					strcat(buff, " ");
					strcpy(colorBuffer, "");			
				}		

				strcat(buff, "\n");				
			}

			fprintf(outFile, "%s", buff);		
			
			if(i == rows -2 )
			{
				printf("%d %s\n", i, buff);
				break;
			} 
			// exit process successfully...
			exit(0);			
		}
		
		
		// wait for the current child process before continuing.
		if (wait(&status) != pid)
			perror("wait error");
	}				
}
