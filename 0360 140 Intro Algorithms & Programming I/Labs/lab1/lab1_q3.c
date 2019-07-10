/*
 * ASSIGNMENT   : LAB 1
 * FILE         : lab2_q3.c
 * AUTHOR       : Jason Choquette
 * ID           : 104337378       
 * DATE         : Sep 22/14
 * DESCRIPTION  : Print my timetable for this class' lecture, using tabs and spaces for a cleaner interface.
 */


#include <stdio.h>


int main(void)
{
  // define a seperator to avoid typing
  char * sep = "+---------------------------------------+\n";
  // since each lecture is at the same time, just store in a variable
  char * time = "\t5:30 pm\t\t6:50 pm\n";
  printf("\n\n cs140,  F2014,  lecture schedule:\n");
  printf("%s",sep);
  printf(" Day\t\tStart time\tEnd time\n");
  printf("%s",sep);
  printf(" Monday\t%s", time);
  printf(" Wednesday%s", time);
  printf("%s", sep);
  printf("\n\n");
  return 0;
}
