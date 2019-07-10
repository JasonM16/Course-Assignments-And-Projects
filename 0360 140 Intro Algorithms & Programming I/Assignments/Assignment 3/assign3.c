/*
* ASSIGNMENT	: Assignment 3 - Calling a Radio Station
* FILE	 		: assign3.c
* AUTHOR		: Jason Choquette
* ID			: 104337378
* DATE			: November 19/14
* DESCRIPTION	: This is my solution to the following programming competition
*				  problem:
				  
				  A local radio station is holding a phone-in contest, and 
				  deejay J-Z Phus is in charge of administering the contest.
				  He goes on the air at random times and announces things like
				  “The fifth caller will get a chance for the grand prize.” At
				  this point, the switchboard lights up with dozens of callers.
				  All these callers show up on a monitor in front of J-Z numbered
				  1, 2, 3, etc. J-Z could just pick caller number 5 at this 
				  point, but since he figures that everyone basically called in
				  at the same time, he has decided on a different method. He
				  picks a random number - say 7 - and then starts eliminating
				  every seventh caller. If he hits the end of the switchboard
				  while counting, he cycles back to the beginning, but once a 
				  caller is eliminated, their position is no longer used in the
				  count. After eliminating 4 callers, he moves down 7 more
				  positions and obtains his “fifth” caller. The figure below 
				  shows how this would work if J-Z's switchboard held 10 callers.
				  In this case, the caller in position 3 is selected as the 
				  “fifth” caller.
				  
				  Of course, the choice of “fifth” caller, the number of callers, 
				  and the use of the number 7 can change from call-in to call-in.
				  You are to write a general program to determine which caller 
				  is selected given all of the pertinent information.
			
				  Input
				  There will be multiple independent test cases. Each test case 
				  will consist of a single line containing 3 positive integers
				  n m k, where n is the number of callers on the switchboard, 
				  and m is the number of positions J-Z skips over each time
				  until he gets to the k th caller. The value of n will always 
				  be ≥ k. In the above example, n = 10; m = 7 and k = 5.
				  The maximum value for any of these values is 200. A line 
				  containing three zeros will terminate input.
				  
				  Output 
				  For each test case, output the position of the caller chosen
				  as the k th caller.

				  Sample Input
				  10 7 5
				  20 1 20
				  0 0 0

				  Sample Output
				  3
				  20	
*/


#include "./assign3.h"


// program entry
int main(void)
{
	SwitchBoard switchBoard;
	int n = 0; // The number of callers
	int m = 0; // Random number used to skip callers
	int k = 0; // The caller to choose in the switchboard		 

	while (1)
	{
		printf("Please enter the number of callers, a random number and the caller to choose.\n>> ");
		// get the number if callers, random number and chosen caller number
		scanf("%d %d %d", &n, &m, &k);

		// if the input is all 0's, quit the program
		if (!Valid(n, m, k)) break;
				
		// initialize the switchboard from caller 1 to n. Maximum of 200 callers		
		InitSwitchBoard(&switchBoard, n);		

		// print the chosen caller
		printf("\nChosen Caller: %d\n\n", GetCaller(&switchBoard, n, m, k));
	}

	printf("\n\nGoodbye!\n\n");

	return 0;
}





/******************************************************************************
FUNCTION		: InitSwitchBoard

DESCRIPTION		: This function initializes the switchBoard from caller 1 to n

INPUT			: Type			: SwitchBoard *
				: Description	: The array of callers
				
				: Type			: int
				: Description	: The number of callers
								
OUTPUT			: N/A
******************************************************************************/
void InitSwitchBoard(SwitchBoard *s, int n)
{
	int i = 0;

	for (; i < n; i++)
		(*s)[i] = (i + 1);
}






/******************************************************************************
FUNCTION		: MoveNext

DESCRIPTION		: This function moves the current position of the switchboard 
				  to the next valid caller. A valid caller is one that hasn't
				  been removed from the switchborad yet.

INPUT			: Type			: SwitchBoard *
				: Description	: The array of callers
				
				: Type			: int
				: Description	: The current index position of the array
								
OUTPUT			: N/A
******************************************************************************/
void MoveNext(SwitchBoard *s, int * currentPosition)
{	
	// if the current caller's place has been removed, move to the next position
	// and check if the position is valid recursively
	if ((*s)[*currentPosition] == 0)
	{
		*currentPosition += 1;
		MoveNext(s, currentPosition);
	}
	else
		*currentPosition += 1;			
}





/******************************************************************************
FUNCTION		: GetCaller

DESCRIPTION		: This function employs an algorithm to determine a kth caller
				  from n callers in a switchboard. Callers are skipped based on
				  a randomly assigned number.

INPUT			: Type			: SwitchBoard *
				: Description	: The array of callers
				
				: Type			: int
				: Description	: The number of callers
				
				: Type			: int
				: Description	: Random number used to skip callers
				
				: Type			: int
				: Description	: The caller to choose in the switchboard
								
OUTPUT			: Type			: int
				: Description	: The chosen caller
******************************************************************************/
int GetCaller(SwitchBoard *s, int n, int m, int k)
{
	int count   = 1; // the current round of callers	
	int counter = 0; // keeps track of the callers counted from 1 to m
	int caller  = 1; // the current caller
	int removed = 0; // flag used to check if a caller has been removed	
	int start   = 1; // starting position in the switchboard
	int end     = 0; // determines the end position in the switchboard 
	
	// need to skip at least m + 1 callers based on algorithm implementation	
	if (m == 1)
		m = 2;
	
	// If the caller to pick is greater than the number of callers, a caller will
	// not be chosen on each iteration. It will basically take 2 runs to choose
	// the mth caller. Uses a slightly different algorithm.
	if (m >= n)
		GetCaller2(s, n, m, k);

	while (count <= k)
	{
		// go through all of the callers on each count
		for (caller = 0; caller < n;)
		{
			// find the next open position and move to it			
			MoveNext(s, &caller);

			// per above, we've moved to the next valid caller so increment
			// the counter
			counter++;

			// if the current caller is the last caller in the switchboard, 
			// 'continue' will break out the loop and since caller is not less
			// than n, n will reset to 0, basically restarting at the beginning
			// of the switchboard
			if (caller == n)
				continue;
			
			// if the current caller is in the position to be eliminated, 
			// remove the caller in that position
			if (counter == m)
			{
				end = caller;
				
				// if we have looped through all the remaining callers and we 
				// landed on the caller we started with, we have landed on the 
				// kth caller. This will happen naturally in certain situations
				// on the first run so make sure its after the first run.
				if (start == end && count > 2)
					return caller;
				
				// 'remove' the current caller
				(*s)[caller-1] = removed;
				// reset the counter since we just removed the mth caller
				counter = 0;			

				// set the start to the current position
				start = caller;

				// move the start position to the next valid caller
				MoveNext(s, &start);				
			}
		}

		// we have gone through all of the callers on this run
		count++;
	}

	return caller;
}





/******************************************************************************
FUNCTION		: GetCaller2

DESCRIPTION		: This function employs an algorithm to determine a kth caller
				  from n callers in a switchboard. Callers are skipped based on
				  a randomly assigned number. This 'overload' assumes m >= n.
				  Employs a slightly different algorithm than base function.

INPUT			: Type			: SwitchBoard *
				: Description	: The array of callers
				
				: Type			: int
				: Description	: The number of callers
				
				: Type			: int
				: Description	: Random number used to skip callers
				
				: Type			: int
				: Description	: The caller to choose in the switchboard
								
OUTPUT			: Type			: int
				: Description	: The chosen caller
******************************************************************************/
int GetCaller2(SwitchBoard *s, int n, int m, int k)
{
	int count   = 1; // the current round of callers	
	int counter = 0; // keeps track of the callers counted from 1 to m
	int caller  = 1; // the current caller
	int removed = 0; // flag used to check if a caller has been removed	
	int start   = 1; // starting position in the switchboard
	int end     = 0; // determines the end position in the switchboard 
	
	// need to skip at least m + 1 callers based on algorithm implementation	
	if (m == 1)
		m = 2;	

	while (count <= k)
	{
		// go through all of the callers on each count
		for (caller = 0; caller < n;)
		{
			// find the next open position and move to it			
			MoveNext(s, &caller);

			// per above, we've moved to the next valid caller so increment
			// the counter
			counter++;

			// if the current caller is the last caller in the switchboard, 
			// 'continue' will break out the loop and since caller is not less
			// than n, n will reset to 0, basically restarting at the beginning
			// of the switchboard
			if (caller == n)
				continue;

			// if the current caller is in the position to be eliminated, 
			// remove the caller in that position
			if (counter == m)
			{
				end = caller;

				// if we have looped through all the remaining callers and we 
				// landed on the caller we started with, we have landed on the 
				// kth caller. This will happen naturally in certain situations
				// on the first run so make sure its after the first run.
				if (start == end && count > 2)
					return caller;
				
				
				// 'remove' the current caller
				(*s)[caller-1] = removed;
				
				// reset the counter since we just removed the mth caller
				counter = 0;			

				// set the start to the current position
				start = caller;

				// move the start position to the next valid caller
				MoveNext(s, &start);

				// we have gone through all of the callers on this run
				count++;
				////////// This is the main difference in algorithms ///////////
				
			}
		}	
	}

	return caller;
}





/******************************************************************************
FUNCTION		: Valid

DESCRIPTION		: This function 

INPUT			: Type			: int
				: Description	: The number of callers
				
				: Type			: int
				: Description	: Random number used to skip callers
				
				: Type			: int
				: Description	: The caller to choose in the switchboard
								
OUTPUT			: N/A
******************************************************************************/
bool Valid(int n, int m, int k)
{
	return n != 0 && m != 0 && k != 0;
}




// EOF
