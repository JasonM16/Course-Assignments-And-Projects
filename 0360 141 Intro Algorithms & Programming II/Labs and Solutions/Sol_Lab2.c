
/*
   Lab 2: Solution
   Writtten by: Ziad Kobti and Quazi Rahman
   Updated: Jan. 2013.

*/

/* includes */
#include<stdio.h>
#include<string.h>

#define _QUIT_ 0
#define _INFINITY_ 999999

/* Specifics for the interactive/dynamic menu */
const char *MENU[] = {
                        "Recursive Sum",
                        "Recursive Factorial",
                        "Recursive Fibonacci",
                        "Recursive Gcd",
                        "Recursive Power"};

const int MENU_COUNT = 14;

/* prototypes */
int GetInput(const char* msg, int min, int max);
int GetMenuItem();

/* Recursive Versions */
int SumR(int n);
int FactorialR(int n);
int FibonacciR(int n);
int GcdR(int x, int y);
long PowerR(int a, int b);


/* main program function */
int main()
{
   int key;                   // stores the input from the user
   do                         // Main program loop
   {
      key = GetMenuItem("Lab 1");      // Retreive a valid input selection from the user

      if (key != _QUIT_)
      {
         switch(key)
         {
            case 1:
               printf("Answer: %d\n", SumR(GetInput("Enter a positive Integer: ", 1, _INFINITY_)));
               break;
            case 2:
               printf("Answer: %d\n", FactorialR(GetInput("Enter a positive Integer: ", 1, _INFINITY_)));
               break;
            case 3:
               printf("Answer: %d\n", FibonacciR(GetInput("Enter a positive Integer: ", 1, _INFINITY_)));
               break;
            case 4:
               printf("Answer: %d\n", GcdR(GetInput("Enter a positive Integer x: ", 1, _INFINITY_),
                                    GetInput("Enter a non-negative Integer y: ", 0, _INFINITY_)));
               break;
            case 5:
               printf("Answer: %ld\n", PowerR(GetInput("Enter a positive Integer a: ", 0, _INFINITY_),
                                    GetInput("Enter a positive Integer b: ", 0, _INFINITY_)));
               break;
         }
      }
   }while(key != _QUIT_);

   printf("Goodbye!\n");
   return 0;                       // exit main (normal = 0)
}

/* Prompts the user and retrieves a valid input
   INPUT: the user supplies the valid prompt and range (min and max)
   OUTPUT: returns a valid user selection
*/
int GetInput(const char* msg, int min, int max)
{
   int n = 0;
   do {
      printf(msg);
      scanf("%d", &n);

      if(n >= min && n <= max)
         return n;
      else
         printf("*Invalid Input* ");

   }while(1);

   //return -1;
}

int GetMenuItem(const char *menu_title)
{
   int i;

   printf("\n%s\n", menu_title);
   for (i=0; i<strlen(menu_title); i++)
   {
      printf("-");
   }
   printf("\n");

   for (i=0; i<MENU_COUNT; i++)
   {
      printf("%3d - %s\n", i+1, MENU[i]);
   }
   printf("%3d - QUIT\n", _QUIT_);

   return GetInput("Please enter a selection: ", 0, MENU_COUNT);
}


/* Recursive Versions */

/* Compute the sum of the first n positive integers-Recursive
   INPUT: a positive integer n
   OUTPUT: returns the sum of 1+2+3+..+n
*/
int SumR(int n)
{
   if (n <= 1)             // base case
   {
      return 1;
   }
   else                 // recursive call
   {
      return SumR(n-1) + n;
   }
}

/* Compute the factorial for n
   INPUT: a positive integer n
   OUTPUT: returns the of n! = n*(n-1)*(n-2)*....*2*1
*/
int FactorialR(int n)
{
   if (n <= 1)             // base case
   {
      return 1;
   }
   else                 // recursive call
   {
      return n * FactorialR(n-1);
   }
}

/* Compute the fibonacci number for n-Recursive
   INPUT: a positive integer n
   OUTPUT: returns the value of the fibonacci series: 1,1,2,3,5,...((n-1)+(n-2))
*/
int FibonacciR(int n)
{
   if (n <= 2)             // base case
   {
      return 1;
   }
   else                 // recursive call
   {
      return FibonacciR(n-1) + FibonacciR(n-2);
   }
}

/* Compute the greatest commond divisor (gcd) for x and y-Recursive
   INPUT: integers x and y (y > 0)
   OUTPUT: returns the gcd as follows: gcd(x, y) = x, if y=0  OR  gcd(x, y) = gcd(y, x MOD y), if y > 0
*/
int GcdR(int x, int y)
{
   if (y == 0)             // base case
   {
      return x;
   }
   else                 // recursive call
   {
      return GcdR(y, x%y);
   }
}

/* Compute power(a,b) - Recursive
   INPUT: integers a (base) and b (exponent) - ASSUME b is POSITIVE
   OUTPUT: returns the value of a raised to the power of b
*/
long PowerR(int a, int b)
{
   if (b == 0)
   {
      return 1;
   }
   else
   {
      return a * PowerR(a, b-1);
   }
}




/* SAMPLE OUTPUT:

Lab 2
-----
  1 - int SumR(int n);
  2 - int FactorialR(int n);
  3 - int FibonacciR(int n);
  4 - int GcdR(int x, int y);
  5 - double PowerR(int a, int b);
  0 - QUIT
Please enter a selection: 1
Enter a positive Integer: 5
Answer: 15

Lab 2
-----
  1 - int SumR(int n);
  2 - int FactorialR(int n);
  3 - int FibonacciR(int n);
  4 - int GcdR(int x, int y);
  5 - double PowerR(int a, int b);
  0 - QUIT
Please enter a selection: 32
*Invalid Input* Please enter a selection: 0
Goodbye!

*/


