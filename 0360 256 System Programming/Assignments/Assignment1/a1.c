/*
 PROJECT		: Assignment 1
 FILE			: a1.c
 AUTHOR			: Jason Choquette, ID 104 337 378
 LAST MODIFIED	: Feb. 5, 2017
 DESCRIPTION	: This program converts a P3 file to a P6 file.
*/


#include "a1.h"


int main(int argc, char *argv[])
{		
	// open and create P3 and P6 files, respectively
	int fd1 = open("./ppmtext.ppm", O_RDONLY);
	int fd2 = open("./ppmbinary.ppm", O_CREAT | O_RDWR | O_TRUNC , 0644);	
	
	// translate P3 to P6 
	convert(fd1, fd2);	
	
	// close files
	close(fd1);
	close(fd2);
	return 0;
}





/******************************************************************************
FUNCTION		: convert

DESCRIPTION		: This function reads the contents of a P3 file and converts
				  those contents to the required P6 format. Once converted, the
				  function writes the image data to the output (P6) file.
				
INPUT			: Type			: int
                : Description	: the file descriptor of input (P3) file.
                
                : Type			: int
                : Description	: the file descriptor of the output (P6) file.                               

OUTPUT			: Type 			: void
                : Description	: N/A
******************************************************************************/
void convert(int fd1, int fd2)
{
	char buffer[MAX_SIZE];
	char rowData[MAX_SIZE];
	char * token;
	char * color; 
	Image image;	
	int i;
	int colorValue;		

	// get the contents of the input file
	read(fd1, buffer, MAX_SIZE);
		
	// set header info of output (P6) file.	
	setHeader(fd2, buffer, &image);

	// grab first row of image data from buffer
	token = strtok(NULL, "\n");
	
	// go through each subsequent row, storing into row data buffer
	for(i = 0; i < image.height; i++)
	{
		strcat(rowData, token);
		strcat(rowData, " "); 
		token = strtok(NULL, "\n");
	}
	
	// create an image buffer to store pixel data
	image.pixel = (Pixel *)malloc(sizeof(Pixel) * image.width * image.height);
	
	token = strtok(rowData, "\n");
	color = strtok(token, " ");
	
	// set each pixel value of the image struct
	for (i = 0; i < image.width * image.height; i++)
	{
		if (color == NULL) break;		

		colorValue = atoi(color);
		image.pixel[i].red = colorValue;
		
		color = strtok(NULL, " ");
		colorValue = atoi(color);
		image.pixel[i].green = colorValue;		

		color = strtok(NULL, " ");
		colorValue = atoi(color);		
		image.pixel[i].blue = colorValue; 		

		color = strtok(NULL, " ");		
	}
	
	// write image data to otput file
	write(fd2, image.pixel, image.width * 3 * image.height);	
}




/******************************************************************************
FUNCTION		: setHeader

DESCRIPTION		: This function sets initial file contents. Representative of a
				  typical p6 file (excluding a comment block - per requirements).

INPUT			: Type			: int
                : Description	: the file descriptor of the output (P6) file.
                
                : Type			: char *
                : Description	: buffer containing .ppm header info.
                
                : Type			: Image *
                : Description	: a pointer to the image struct.                     

OUTPUT			: Type 			: void
                : Description	: N/A
******************************************************************************/
void setHeader(int fd, char * buff, Image * image)
{
	int length;
	char * token;
	char writeWidth[3]  = {'\0'};
	char writeHeight[3] = {'\0'};
	char writeColors[3] = {'\0'};	
	
	// write the standard first line of p6 file.
	token = strtok(buff, "\n");		
	write(fd, "P6\n", 3);
	
	// write width to file and set image width of image struct
	token = strtok(NULL, " ");				
	image->width = atoi(token);	
	strcat(writeWidth, token);
	strcat(writeWidth, " ");
	length = strlen(writeWidth);
	write(fd, writeWidth, length);
	
	
	// write height to file and set image height of image struct
	token = strtok(NULL, "\n");	
	image->height = atoi(token);			
	strcat(writeHeight, token);
	strcat(writeHeight, "\n");
	length = strlen(writeHeight);
	write(fd, writeHeight, length);
	
	
	// write max colors to file
	token = strtok(NULL, "\n");	
	strcat(writeColors, token);
	strcat(writeColors, "\n");
	length = strlen(writeColors);		
	write(fd, writeColors, length);	
}



