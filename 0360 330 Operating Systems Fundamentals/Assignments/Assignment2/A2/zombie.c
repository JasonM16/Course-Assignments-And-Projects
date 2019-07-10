/*
* PROJECT:     Assignment 2
* FILE:        zombie.c
* AUTHOR:      Jason Choquette 104337378
* DATE:        January 24, 2018
* DESCRIPTION: This file contains the definition for the createZombie
			   function.
*/

#include "zombie.h"




/******************************************************************************
FUNCTION		: createZombie

DESCRIPTION		: This function forks a child which immediately returns, becoming
				  a zombie process. The parent then prints a list of processes
				  showing the child has become a zombie.
				  The parent process then returns its own pid to the calling
				  program which will then kill this program (the parent of the
				  zombie process).

INPUT			: Type			: void
				: Description	: N/A

OUTPUT			: Type 			: int
				: Description	: The parent pid
******************************************************************************/
int createZombie(void)
{
	switch (fork())
	{
		case -1:
			perror("\nfork() failed.\n");
			exit(1);

		case 0:
			// immediately exit to become zombie while parent sleeps
			exit(0);

		default:
			sleep(1);
			printf("\n\nCurrent processes: \n\n");
			system("ps -l");
			printf("\n");
			printf("\nFound the following zombies: \n");
			system(" ps aux | awk '\"[Zz]\" ~ $8 { printf(\"PID = %d\", $2); }' ");
			printf("\n\n");
			sleep(1);
			return getpid();
	}
}