/*
 * ASSIGNMENT	: LAB 1
 * FILE		: lab1_q4.c
 * AUTHOR	: Jason Choquette	
 * DATE		: Sep 22/14
 * DESCRIPTION	: Read a float number (with any number of decimal digits), round it to the precision of only two decimal
 *		  points and print the result: (use the specifier %.2f in printf, is there another way to round?)
 *		  - will have to link libraries during compilatoin. Use cc lab1_q4.c -lm (-lm = 'library math')
 **/

#include <stdio.h>
#include <math.h> // for the library's 'roundf' function.

int main(void)
{
  // declare and store a floating point number
  float num1 = 0.0; 
  printf("\n\nPlease enter a number with decimal values: ");

  // store the user's input
  scanf("%f", &num1);
 
  // print out the the user's input rounded to two decimal places using <math.h> library's 'roundf' function
  printf("The rounded value to 2 decimal places is: %.2f\n\n", roundf(num1 * 100) / 100);

  getchar();

  return 0;
}
