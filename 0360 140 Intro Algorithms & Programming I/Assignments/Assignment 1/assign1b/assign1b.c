/*
 * ASSIGNMENT	: Assignment 1
 * FILE	 		: assign1b.c
 * AUTHOR		: Jason Choquette
 * ID			: 104337378
 * DATE			: October 01/14
 * DESCRIPTION	: 
 
taken from:
 
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1846 

- accessed 09/30/14				  
				  
There are lots of number games for children. These games are pretty easy to 
play but not so easy to make. We will discuss about an interesting game here. 

Each player will be given N positive integer. (S)He can make a big integer by 
appending those integers after one another. Such as if there are 4 integers as 
123, 124, 56, 90 then the following integers can be made – 1231245690, 
1241235690, 5612312490, 9012312456, 9056124123 etc. In fact 24 such integers 
can be made. But one thing is sure that 9056124123 is the largest possible 
integer which can be made.

You may think that it’s very easy to find out the answer but will it be easy 
for a child who has just got the idea of number?

Input

Each input starts with a positive integer N (≤ 50). In next lines there are N 
positive integers. Input is terminated by N = 0, which should not be processed.

Output

For each input set, you have to print the largest possible integer which can 
be made by appending all the N integers.				  
 
_________________________________________________________
Sample Input					Output for Sample Input
_________________________________________________________
4
123 124 56 90					9056124123 	  
5
123 124 56 90 9					99056124123
5
9 9 9 9 9						99999
0
_________________________________________________________

*/




#include <stdio.h>   // printf, scanf, getchar
#include <stdbool.h> // bool, true, false
#include <math.h>    // floor
#include <string.h>  // strcat


// define the maximum N as 50
#define N 50


// a struct to contain both a number value and the numbers corresponding 
// digits stored in an array
typedef struct
{	
	// the integer representation of a number
	int value;
	
	// used to store the individual digits of the number value	
	int digits[12]; // fix the array size to 12. there will not be any more 
					// than 12 digits in an integer
} number;


// function prototype declaration
number * Sort(number *, int);


// program entry
int main(void)
{	
	// used to store exponential values of ten. this array will be used when 
	// assigning a divisor to a number to extract the individual digits based
	// on the numbers length. i.e. 123 has a length of 3. therefore, to access
	// the divisor for 123, use ten_to_the[3 - 1] (zero-indexed) which will be
	// 100, which is the correct divisor for a number with a length of 3 
	// such as 123     	
	int ten_to_the [] = 
	{
	  1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 
	  100000000, 1000000000
	};
	
	// an array of struct type 'number' (see above)
	number numbers[N];
	
	// store the modulus of a number
	int remainder = 0;
	
	// store the divisor of a number
	int divisor = 0;
	
	// store the size (length) of an integer
	int size = 0;
	
	// store the value of an integer
	int value = 0;
	
	// counters
	int i = 0;
	int j = 0;
	
	// the number of inputs (integers) that the user is going to enter
	int input_size = 0;

	// this is an array of integers I used to test the time constraints of the
	// algorithm. there are 50 elements in an ascending order (worst-case). 
	int time_test [N] = 
	{  
	    2,    3,    5,    7,    11,   13,   17,   19,   23,   29,
	    31,   37,   41,   43,   47,   53,   59,   61,   67,   71,
	    71,   79,   83,   89,   97,   101,  103,  107,  109,  113,
	    127,  131,  137,  139,  149,  151,  157,  163,  167,  173,
	    179,  181,  191,  193,  197,  199,  211,  223,  229,  229
	};

	// loop forever. Exit sequence will be initiated on input by user
	while (true)
	{
		scanf("%d", &input_size);
		
		// if they enter 0, quit the program
		if (input_size == 0) break;

		// reset all of the memory in case the number has a smaller length than
		// the previous number. Avoids any possible ambiguity in numbers and
		// their lengths
		for (i = 0; i < input_size; i++)
		{
			memset(numbers[i].digits, -1, (sizeof(numbers[i].digits)));
		}

		for (i = 0; i < input_size; i++)
		{
			// get the numbers
			scanf("%d", &numbers[i].value);			
			value = numbers[i].value;
									
			// get the size of the integer to know which divisor to use
			size = floor(log10(abs(numbers[i].value))) + 1;
			
			// we can accept numbers with different lengths. In order to 
			// extract the digits we need the proper divisor.
			divisor = ten_to_the[size - 1];

			// this loop will break down each number's value into its 
			// individual decimal place components
			for (j = 0; j < size; j++)
			{ 	
				// per above, the divisor is currently set to the proper place
				// value. Example: the number 54321 has a length of 5 digits so 
				// its divisor is set to 10000. 
				// in order to get the first digit, take the value and divide 
				// it by the divisor: 54321 / 10000 = 5 with a remainder of
				// 4321 
				numbers[i].digits[j] = value / divisor;
				
				// store the remainder of 4321 in the remainder variable
				remainder = value % divisor;
				
				// set the remainder as the new value 
				value = remainder;
				
				// move the decimal place down one place. i.e. 1000
				divisor /= 10;
				
				// with the divisor now set one less decimal place and a new
				// value as the remaining digits, the algorithm continues until
				// all the digits have been extracted 
			}
		}

		// call the sort function and store the results in a new array 
		number * sortedNumbers = Sort(numbers, input_size);

		// this string is used to store the final number 
		// it is initialized to an empty string strcat will not throw an 
		// exception when trying to append to an uninitialized string.
		char number_as_string[200] = { '\0' };

		// used to store the current number's string representation in the loop
		char num[10];

		
		for (i = 0; i < input_size; i++)
		{
			// convert int to char
			sprintf(num, "%d", sortedNumbers[i].value);
			
			// concatenate the numbers using strcat from using the string.h
			// library
			strcat(number_as_string, num);
		}
		
		// print the final concatenated number
		printf("\n%s\n\n", number_as_string);					
	}	

	// ensure the user can see the printed output
	getchar();

	return 0;
}





/******************************************************************************
 FUNCTION		: Sort

 DESCRIPTION	: This function sorts an incoming list of numbers by descending
 				  values. Basically, a basic implementation of bubble sort. 
 				   
 INPUT			: Type 			: number[]  
				: Description	: this is an array of struct type 'number' 
				  (for definition - see above), which holds the numbers to 
				  sort.

				: Type			: int
				: Description	: this is the number of array elements. Used 
				  for loop constructs in function.
 
 OUTPUT			: Type 			: number[]  
				: Description	: the sorted array of numbers.
******************************************************************************/
number * Sort(number * numbers, int size)
{
	// counters
	int i = 0;
	int j = 0;	
	// temp variable for swapping numbers in the array
	number temp;		
	
	// this outer for loop will index the number array
	for (i = 0; i < size; ++i)
	{
		// this loop will index the following number in the numbers array.
		// although this is not as efficient as a divide and conquor tehcnique,
		// it is good enough for this problem since N will always be less <= 50
		for (j = i + 1; j < size; ++j)
		{
			// index fixed at zero because we always want to look at the first
			// digits for equality
			if (numbers[i].digits[0] <= numbers[j].digits[0]) 				
			{
				// if those digits are equal, enter this if statement so we 
				// can look at just the actual values
				if (numbers[i].digits[i] == numbers[j].digits[i])
				{
					// compare the values. we know they start with the same
					// digit so just compare the numbers and sort based on 
					// their values
					if (numbers[i].value < numbers[j].value)
					{
						// swap 'em!
						temp = numbers[i];
						numbers[i] = numbers[j];
						numbers[j] = temp;
					}
				}
				// the first digits were not equal so we know we can just do
				// a normal swap
				else
				{
					// swap 'em!
					temp = numbers[i];
					numbers[i] = numbers[j];
					numbers[j] = temp;
				}
			}
					
			// notice how we only need to check for <= in first if. 
			// This is a catch-all: if the current number at index i > current 
			// number at index i + 1, then its in its proper place.
		}		
	}

	return numbers;
} 


// EOF