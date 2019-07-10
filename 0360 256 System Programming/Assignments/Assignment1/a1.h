/*
 PROJECT		: Assignment 1
 FILE			: a1.h
 AUTHOR			: Jason Choquette, ID 104 337 378
 LAST MODIFIED	: Feb. 5, 2017
 DESCRIPTION	: Header file for assignment 1.
*/



// project dependencies and references
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


// used to define array size(s)
#define MAX_SIZE 256

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
	int width;
	int height;
	Pixel * pixel;

} Image;


// function prototypes
void convert(int, int);
void setHeader(int, char *, Image *);
