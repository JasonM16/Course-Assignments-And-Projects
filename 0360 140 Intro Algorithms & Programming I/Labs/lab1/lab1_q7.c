/*
 * ASSIGNMENT	: LAB 1
 * FILE		: lab1_q7.c
 * AUTHOR	: Jason Choquette	
 * DATE		: Sep 22/14
 * DESCRIPTION	: The following formula is to convert the temperature from (C)elsius to (F)ahrenheit.
 *		  F = 1.8 C + 32
 *		  The code will prompt the user to enter the temperature in Celsius and then convert and prints its
 *		  equivalent in Fahrenheit.
 *		  Next, it will prompt the user to enter temperature in Fahrenheit then convert and prints its equivalent
 *		  in Celsius.
 * */


#include <stdio.h>

int main(void)
{
  // store and initialize celcius and fahrenheit variables
  float celc = 0.0;
  float far = 0.0;

  printf("\n\nPlease enter a temperature in Celcius: ");

  // store the celcius temperature
  scanf("%f", &celc);

  // print the conversion from celcius to fahrenheit
  printf("%.2f Celcius = %.2f Farhenheit\n\n", celc, 1.8 * celc + 32);
  
  printf("Please enter a temperature in Farhenheit: ");

  // store the fahrenheit temperature 
  scanf("%f", &far);
 
  // print the conversion from fahrenheit to celcius 
  printf("%.2f Farhenheit = %.2f Celcius\n\n", far, (far - 32) / 1.8);

  getchar();

  return 0;
}
