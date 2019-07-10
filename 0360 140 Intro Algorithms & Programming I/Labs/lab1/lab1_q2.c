/*
 * ASSIGNMENT   : LAB 1
 * FILE         : lab2_q2.c
 * AUTHOR       : Jason Choquette
 * ID		: 104337378       
 * DATE         : Sep 22/14
 * DESCRIPTION  : Read a positive integer num1 from the standard input device (scanf), and calculate the quotient and the
 * 		  remainder of num1 when divided by 3. Print the results along with the appropriate messages.
 */



#include <stdio.h>

// set a constant to avoid magic numbers!!
#define QUOT 3

int main(void)
{
  // declare and initialize the num1 variable	
  int num1 = 0;
  
  // ask the user for a positive integer
  printf("\nPlease enter a positive integer:  ");
  
  // store the integer
  scanf("%d", &num1);

  // print the quotient and the remainder of num1. 
  // just do simple evaluations inside the printf for terseness.
  // using the modulus operator for the remainder
  printf("\nThe quotient of %d/%d is: %d", num1, QUOT, num1 / QUOT);
  printf("\nThe remainder of %d/%d is: %d\n\n", num1, QUOT, num1 % QUOT);

  // ensure we can see the printed results 
  getchar();

  return 0;
}
