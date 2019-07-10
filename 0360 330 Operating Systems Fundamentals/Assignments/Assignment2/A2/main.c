/*
* PROJECT:     Assignment 2
* FILE:        main.c
* AUTHOR:      Jason Choquette 104337378
* DATE:        January 24, 2018
* DESCRIPTION: Program entry.
*/


#include"zombie.h"


/******************************************************************************
FUNCTION		: main

DESCRIPTION		: This function calls an external program (the Parent) that
				  forks a child (the Child) which immediately exits and becomes
				  a zombie, upon which the parent’s pid gets returned to the 
				  this function. The return value of the parent function is the
				  pid of the parent. This pid is used in the kill system call 
				  to kill the parent. At each step of the process, a process 
				  table is printed to standard out.


INPUT			: Type			: void
				: Description	: N/A

OUTPUT			: Type 			: int
				: Description	: The exit code of the program.
******************************************************************************/
int main()
{
	pid_t	forkReturn;
	int		retCode;


	// call another C program to create a zombie
	// this main() function is the Parent process
	int parent = createZombie();

	// spawn a child process from this process
	forkReturn= fork();

	if (forkReturn == -1)
	{
		printf ("Error - fork failed!\n");
		exit (0);
	}
	else if (forkReturn == 0)  //   this is the CHILD
	{
		sleep(1);

		/* when the child wakes, have it terminate the PARENT */
		retCode = kill( parent, SIGKILL);
		if(retCode == 0)    // termination occured
		{
			printf("\n(CHILD)  : Parent has been terminated ...\n\n");
			sleep(1);
			system("ps -l");
			exit (0);
		}
		else
			printf("(CHILD)  : Unable to terminate parent\n");
		
		exit (0);
	}
	else					// this is the PARENT
	{
		system("ps -l");
		sleep(5);
	}
	exit (0);
}

