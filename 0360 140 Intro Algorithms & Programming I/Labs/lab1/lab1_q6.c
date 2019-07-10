/*
 * ASSIGNMENT	: LAB 1
 * FILE		: lab1_q6.c
 * AUTHOR	: Jason Choquette	
 * DATE		: Sep 22/14
 * DESCRIPTION	: Read integer x from the input and calculate the following functions:
		  f(x) = -2x+5
		  g(x) = x 3 +2x-4
		  h(x) = (3x+2) / (2x-4)
 * */

#include <stdio.h>
#include <math.h> // use the library's 'pow' function

int main(void)
{
  // declare and initialize variable to store user input.
  int x = 0;
  printf("\n\nPlease enter a value for integer x: ");

  // store user's input
  scanf("%d", &x);

  // define and calculate function 1 
  int func1 = -2 * x + 5;
  
  // define and calculate function 2
  int func2 = (pow(x, 3) + 2 * x - 4); // 'pow' defined in <math.h>
  
  // define and calculate function 3
  float func3 = ((3 * (float) x) + 2) / ((2 * (float) x) - 4);

  // print the results of each of the functions
  printf("\n\tf(%d) = -2(%d) + 5\t\t = %d\n", x, x, func1);
  printf("\tg(%d) = (%d)^3 + 2(%d) - 4\t\t = %d\n", x, x, x, func2);
  printf("\th(%d) = (3(%d)+2) / (2(%d)-4)\t = %.2f\n\n", x, x, x, func3);

  getchar();

  return 0;
}
