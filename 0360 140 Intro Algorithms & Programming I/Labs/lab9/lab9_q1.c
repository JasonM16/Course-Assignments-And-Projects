/*
* ASSIGNMENT	: Lab 9
* FILE	 		: lab9_q1.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: November 20/14
* DESCRIPTION	: This program prints different direct, indirect and address
*				  values for a single integer and a pointer to the integer. 
*/


// program dependencies
#include <stdio.h> // printf


// program entry
int main()
{
	int a = 7; // declare and assign the value '7' to an integer variable with the name 'a'
	int *aPtr; // declare a variable of type pointer to integer
	aPtr = &a; // assign the address of the variable 'a' to the pointer

	printf("\n&a : %p", &a);		  // this is the address of the integer variable 'a'
	printf("\naPtr : %p", aPtr);	  // this is the value of 'aPtr', which holds the memory address of 'a'
	printf("\n&aPtr : %p", &aPtr);	  // this is the memory address of 'aPtr'
	printf("\na : %d", a);			  // this is the value of 'a', 7
	printf("\n*aPtr : %d", *aPtr);	  // this is the value at the location pointed by 'aPtr' (the value of 'a')
	printf("\n*&aPtr : %p", *&aPtr);  // this is the value at the memory address of 'aPtr' (the address of 'a')
	printf("\n&*aPtr : %p", &*aPtr);  // this is the the memory address of the location pointed by 'aPtr' (the address of 'a')
	printf("\n*&a : %d\n\n", *&a);	  // this is the value at the memory address of 'a' (the value of 'a')
	//printf("%d", &*a); 			  // this gives an error. this is trying to access the address of a value
									  // (the address of 7)

	return 0;
}



// EOF
