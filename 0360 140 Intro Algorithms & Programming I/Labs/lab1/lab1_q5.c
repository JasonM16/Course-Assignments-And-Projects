/*
 * ASSIGNMENT	: LAB 1
 * FILE		: lab1_q5.c
 * AUTHOR	: Jason Choquette	
 * DATE		: Sep 22/14
 * DESCRIPTION	: Read three integers from the standard input device and print their sum and average (rounded to 2
 *		  decimal places).
 * */

#include <stdio.h>


int main(void)
{
  // declare and initialize variables to store user input.
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;

  printf("\n\nPlease enter three integers: ");
 
  // store usre's input into the variables
  scanf("%d %d %d", &num1, &num2, &num3);
 
  // store the sum of the variables in another variable
  float sum = num1 + num2 + num3;

  // print the sum
  printf("\nTheir sum is: %.f\n", sum);

  // print the average
  printf("Their average is: %.2f\n\n", sum / 3);

  getchar();

  return 0;
}
