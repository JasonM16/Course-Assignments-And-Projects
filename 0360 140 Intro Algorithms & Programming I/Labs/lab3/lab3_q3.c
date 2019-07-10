/*
 * ASSIGNMENT	: Lab 3
 * FILE	 		: lab3_q3.c
 * AUTHOR		: Jason Choquette
 * ID			: 104337378
 * DATE			: October 06/14
 * DESCRIPTION	: This program will read in a four or five digit integer 
				  number and determine whether it is a palindrome number or
				  not. (a palindrome is a number or text phrase 
				  that reads the same backward as forward such as 12521). 

				  Example:

				  Please enter a 4 or 5 digit integer palindrome: 1551
				  1551 is a palindrome!

				  Please enter a 4 or 5 digit integer palindrome: 11112
				  11112 is not a palindrome! 

				  Please enter a 4 or 5 digit integer palindrome: 151151
				  Your entry is invalid!!! 
 */


#include <stdio.h>   // printf, scanf
#include <math.h>    // floor
#include <stdbool.h> // True, False, bool


// define a maximum number of digits for the number to be tested 
// - (for aray length)
#define MAX_SIZE 5


// function prototype declarations
bool isPalindrome(int[], int);
bool digitsAreEqual (int num1, int num2);
int * makeIntArray (int, const int);


// program entry
int main (void)
{
	int number = 0;
	
	printf("\n\nPlease enter a 4 or 5 digit integer palindrome: ");

	// input
	scanf("%d", &number);

	// get the length of the digit
	int length = floor(log10(abs(number))) + 1;
        
	// make sure the length is between 4 and 5 per requirements	
    if (length < 10 && length > 3)
    {
    	int * numbers = makeIntArray(number, length);
    
    	printf("%d is ", number);        
        
		// this if statement will call a method and return true or false if
			// the number is or isn't a palindrome
			// if it is, print 'is a palidrome'
			if (isPalindrome(numbers, length))
			{
				printf("a palindrome!");    
			}
			// if it isn't, print this message instead
			else
			{
				printf("not a palindrome!");    
			}       
		}
		// if the number was not the correct length/format, print invalid message
		else
		{
	   		printf("Your entry is invalid!!!");     
		}
     
	printf("\n\n");

	return 0;
}





/******************************************************************************
FUNCTION		: isPalindrome

DESCRIPTION		: This function checks a number (integer) to determine whether
				  or not the number is a palindrome

INPUT			: Type 			: int[]
				: Description	: the number as an array of digits 

				: Type			: int
				: Description	: the length of the array of digits

OUTPUT			: Type			: bool
				: Description	: true if the number is a palindrome, false 
				                  otherwise
******************************************************************************/
bool isPalindrome (int numbers[], int length)
{
    bool is_palindrome = true;
	int start = 0;
	int end = length - 1;	
	
	for(; start <= length / 2; start++, end--)
	{			
		// if the two corresponding digits are not equal, return false
		if(!digitsAreEqual(numbers[start], numbers[end]))
		{
			is_palindrome = false;
			break;
		} 		
	}	

	return is_palindrome;
}





/******************************************************************************
FUNCTION		: digitsAreEqual

DESCRIPTION		: Compare two numbers for equality

INPUT			: Type 			: int
				: Description	: first number to be compared

				: Type			: int
				: Description	: second number to be compared

OUTPUT			: Type			: bool
				: Description	: true if numbers are equal, false otherwise
******************************************************************************/
bool digitsAreEqual (int num1, int num2)
{
	return num1 == num2;
}





/******************************************************************************
FUNCTION		: makeIntArray

DESCRIPTION		: This function converts an integer to an array of integers 
				 (the digits) representing the original number

INPUT			: Type 			: int
				: Description	: the number to be converted to an array

				: Type			: int
				: Description	: the array of digits to print

OUTPUT			: Type:			: int[]
				: Description   : an array of integers
******************************************************************************/
int * makeIntArray (int number, const int length)
{
	// used to store exponential values of ten. this array will be used when 
	// assigning a divisor to a number to extract the individual digits based
	// on the numbers length. i.e. 123 has a length of 3. therefore, to access
	// the divisor for 123, use ten_to_the[3 - 1] (zero-indexed) which will be
	// 100, which is the correct divisor for a number with a length of 3 
	// such as 123     	
	int ten_to_the [] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 
						  10000000, 100000000 };
	
	// store the modulus of a number
	int remainder = 0;
	
	// store the divisor of a number
	int divisor = 0;
		
	// used to store the new array of digits for the incoming number variable
	static int numArray[MAX_SIZE];
	
	// counter
	int i = 0;
	
	// we can accept numbers with different lengths. In order to 
	// extract the digits we need the proper divisor.
	divisor = ten_to_the[length - 1];

	// this loop will break down each number's value into its 
	// individual decimal place components
	for (; i < length; i++)
	{ 	
		// per above, the divisor is currently set to the proper place
		// value. Example: the number 54321 has a length of 5 digits so 
		// its divisor is set to 10000. 
		// in order to get the first digit, take the value and divide 
		// it by the divisor: 54321 / 10000 = 5 with a remainder of
		// 4321 
		numArray[i] = number / divisor;
		
		// store the remainder of 4321 in the remainder variable
		remainder = number % divisor;
		
		// set the remainder as the new value 
		number = remainder;
		
		// move the decimal place down one place. i.e. 1000
		divisor /= 10;
		
		// with the divisor now set one less decimal place and a new
		// value as the remaining digits, the algorithm continues until
		// all the digits have been extracted 
	}
	
	return numArray;
}


// EOF