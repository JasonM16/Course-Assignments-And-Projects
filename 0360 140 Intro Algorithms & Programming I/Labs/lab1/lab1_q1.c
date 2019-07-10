/*
 * ASSIGNMENT	: LAB 1
 * FILE		: lab1_q1.c
 * AUTHOR	: Jason Choquette	
 * DATE		: Sep 22/14
 * DESCRIPTION	: This file will ask the user for their name and then
 * 		  will output a message with the user's name.
 * */

#include <stdio.h>


int main(void)
{
  // ask the user for their name
  printf("\n\nWhat is your first name? ");
  
  char name[30]; // used to store the user's name

  // get the user's name and store it
  scanf("%s", name);

  // print a message with the user's name
  printf("Hello %s, how are you?\n", name);
  printf("I hope you feel 100%% today!\n\n\n");

  getchar();

  return 0;
}
