/*
* PROJECT		: Assignment 4
* FILE			: calculations.c
* AUTHOR		: Jason Choquette 104337378
* DATE			: Februrary 10, 2018
* DESCRIPTION	: This file contains real-time implementations of division and
				  modulus.
*/


#include "prototypes.h"


/******************************************************************************
FUNCTION		: bitwiseDivision

DESCRIPTION		: This function performs the division operation (inline assembly).

INPUT			: Type			: unsigned int
				: Description	: dividend

				: Type			: unsigned int
				: Description	: divisor

OUTPUT			: Type 			: unsigned int
				: Description	: The result of the division operation.

SOURCE			: https://stackoverflow.com/questions/2776211/how-can-i-multiply-and-divide-using-only-bit-shifting-and-adding/19780781#19780781
******************************************************************************/
unsigned int bitwiseDivision(unsigned int dividend, unsigned int divisor)
{
	unsigned int quot;
	__asm {
		mov  eax, [dividend];// quot = dividend
		mov  ecx, [divisor]; // divisor
		mov  edx, 32;        // bits_left
		mov  ebx, 0;         // rem
	$div_loop:
		add  eax, eax;       // (rem:quot) << 1
		adc  ebx, ebx;       //  ...
		cmp  ebx, ecx;       // rem >= divisor ?
		jb  $quot_bit_is_0;  // if (rem < divisor)
	$quot_bit_is_1:          // 
		sub  ebx, ecx;       // rem = rem - divisor
		add  eax, 1;         // quot++
	$quot_bit_is_0:
		dec  edx;            // bits_left--
		jnz  $div_loop;      // while (bits_left)
		mov[quot], eax;      // quot
	}
	return quot;
}






/******************************************************************************
FUNCTION		: bitwiseMod

DESCRIPTION		: This function performs the mod operation.

INPUT			: Type			: unsigned int
				: Description	: The dividend.

				: Type			: unsigned int
				: Description	: The divisor.

OUTPUT			: Type 			: unsigned int
				: Description	: The result of the mod operation.
******************************************************************************/
unsigned int bitwiseMod(unsigned int dividend, unsigned int divisor)
{
	return dividend & (divisor - 1);
}