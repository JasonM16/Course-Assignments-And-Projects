/*
* ASSIGNMENT	: Lab 6
* FILE	 		: lab6.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: November 09/14
* DESCRIPTION	: This program will display an option menu to the user to calculate
				  three different types of functions. The functions are as follows:
				  
				  ComputeFactorial
				  This is a non-recursive function that accepts an integer n as 
				  input parameter and computes and returns n!

				  ComputeFibonacci
				  This is a non-recursive function that accepts an integer n as 
				  input parameter and computes and returns the Fibonacci value of it.

				  SumOdd
				  This function accepts an integer n as input and computes and 
				  returns the total of all odd numbers within the range of 1..n 
				  (including n itself if n is odd).		  

				  Sample output of the program:

				  ACTION LIST MENU
				  ----------------
				  1. Compute Factorial of n (n!)
				  2. Compute Fibonacci of n
				  3. Compute SumOdd of n
				  4. Exit


				  Please select one action from the above list? 5
				  Your entry was invalid!
				  Please select one action from the above list? 1
				  The factorial of 6 (6!) = 720
				  Please select one action from the above list? 2
				  The Fibonacci of 6 = 8
				  Please select one action from the above list? 3
				  The total of odd numbers between 1 and 6 = 9
				  Please select one action from the above list? 4
				  Goodbye!
*/


// contains library dependencies and function prototypes
#include "lab6.h" 


// program entry
int main(void)
{
	// invoke MenuController
	MenuController();

	return 0;
}





/******************************************************************************
FUNCTION		: MenuController

DESCRIPTION		: This function displays an options menu and then routes the 
				  requested option from the user to the proper function.

INPUT			: N/A
				
OUTPUT			: N/A
******************************************************************************/
void MenuController(void)
{	
	while (1)
	{
		printf("\n\nACTION LIST MENU\n");
		printf("----------------\n\n");
		printf("1. Compute Factorial of n (n!)\n");
		printf("2. Compute Fibonacci of n\n");
		printf("3. Compute SumOdd of n m\n");
		printf("4. Exit\n\n");

		// test input
		int choice = GetNumber(1, 4);

		if (choice == 4)
		{
			printf("\n\nGoodbye!\n\n");
			break;
		}

		int n = 0;		
		
		switch (choice)
		{
			case 1:
				printf("\nPlease enter a value for factorial (value less than 27): ");
				n = GetNumber(0, 26);								
				printf("\nThe factorial of %d (%d!) = ", n, n);
				PrintfCommas(ComputeFactorial(n));
				printf("\n\n");
				break;

			case 2:
				printf("\nPlease enter a value for fibonacci: ");
				scanf("%d", &n);				
				printf("\nThe Fibonacci of %d = ", n);
				PrintfCommas(ComputeFibonacci(n));
				printf("\n\n");
				break;

			case 3:				
				printf("\nPlease enter a range of values to find the sum of the odd digits: ");
				int m = 0;
				scanf("%d %d", &n, &m);				
				printf("\nThe sum of odd numbers between %d and %d = ", n, m);
				PrintfCommas(SumOdd(n, m));
				printf("\n\n");
				break;

			default:
				printf("\n\nOuch! Unkown error has occurred! Exiting program...\n\n");
				break;
		}
	}
}





/******************************************************************************
FUNCTION		: ComputeFactorial

DESCRIPTION		: This function computes the factorial for the input parameter

INPUT			: Type			: int
				: Description	: the factorial to compute
				
OUTPUT			: Type 			: unsigned long long (64-bit. allows for greater factorials) 
				: Description	: the computed factorial
******************************************************************************/
unsigned long long ComputeFactorial(int n)
{
	// use unsigned long to be able to cumpute and store larger factorials
	unsigned long long fac = 1;
	int i = n;

	for (; i >= 1; i--)
	{
		fac *= i;
	}

	return fac;
}





/******************************************************************************
FUNCTION		: ComputeFibonacci

DESCRIPTION		: This function 

INPUT			: Type			: int
				: Description	: n
				
OUTPUT			: Type 			: int
				: Description	: the nth digit of the fibonacci sequence
******************************************************************************/
int ComputeFibonacci(int n)
{	
	int i      = 0;	
	int fib    = 0;
	int first  = 0;
	int second = 1;	

	for (; i <= n; i++)
	{
		if (i <= 1)
			fib = i;

		else
		{
			fib = first + second;
			first = second;
			second = fib;
		}
	}

	return fib;
}





/******************************************************************************
FUNCTION		: SumOdd

DESCRIPTION		: This function calculates and resturn the sum of odd numbers
				  within a given range. The range is given as parameters to 
				  the function.

INPUT			: Type			: int
				: Description	: the first number in the range
				
				: Type			: int
				: Description	: the second number in the range
				
OUTPUT			: Type 			: int
				: Description	: the sum of the odd integers
******************************************************************************/
int SumOdd(int n, int m)
{
	int sum  = 0;
	int i    = 0;
	int temp = 0;

	// make sure the first number is lower than the second number
	if (n > m)
	{
		temp = n;
		n = m;
		m = temp;
	}

	// if n is even start at the next digit
	if (n % 2 == 0)
	{
		n++;
	}

	// loop through all the numbers from n to m
	for (i = n; i <= m; i += 2)
	{
		sum += i;
	}

	return sum;
}




/******************************************************************************
FUNCTION		: GetNumber

DESCRIPTION		: This function returns the sum of integers from 1 to n:
				  Ex: 1 + ... + (n - 2) + (n -1) + n

INPUT			: Type			: int
				: Description	: n
				
OUTPUT			: Type 			: int
				: Description	: the sum of the integers
******************************************************************************/
int GetNumber(int min, int max)
{
	int valid      = 0;
	int user_input = 0;

	do
	{		
		scanf("%d", &user_input);
		if (user_input < min || user_input > max)
		{
			printf("\n%d is not a valid number, please select a number between %d and %d!\n\n"
				, user_input, min, max);
			continue;
		}

		valid = 1;

	} while (!valid);

	return user_input;
}





/******************************************************************************
FUNCTION		: PrintfComma

DESCRIPTION		: This function prints out a number with commas in the thousandths
				  places. i.e. 123456789654321 prints out as 123,456,789,654,321

INPUT			: Type			: unsigned long long 
				: Description	: the number to be printed
				
OUTPUT			: N/A
******************************************************************************/
void PrintfCommas (unsigned long long n) 
{
    if (n < 1000) 
    {
        printf ("%llu", n);
        return;
    }
    
    PrintfCommas (n/1000);
    printf (",%03llu", n%1000);
}

