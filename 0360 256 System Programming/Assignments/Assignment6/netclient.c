/*
 * PROJECT			: Assignment6
 * FILE				: netclient.c
 * AUTHOR			: Jason Choquette, 104337378
 * LAST MODIFIED 	: Mar. 21/17
 * DESCRIPTION	 	: A simple tcp/ip client
*/






#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>




void printPattern(int);
void pattern0(void);
void pattern1(void);
void pattern2(void);


int main (int argc, char * args[])
{
	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;	
	int num;


	 /* get a socket for communications */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;	
	address.sin_addr.s_addr = inet_addr(args[1]);
	address.sin_port = htons(9734);
	len = sizeof(address);

	/* attempt a connection to server */
	result = connect(sockfd, (struct sockaddr *) &address, len);

	if(result == -1)
	{
		perror("Error: netclient.");
		exit(1);
	}

	/* keep connection open */
	while(1)
	{
		int s;

		/* obtain an integer from the server */
		if(s = read(sockfd, &num, sizeof(int)) > 0)
		{
			printf("n = %d\n", num); 
			printPattern(num);		
		}
		else
		{
			printf("\nGoodbye!\n");		// server shutdown...		
			exit(0);
		}

	}

	// close socket connection and free resources
	close(sockfd);	
	exit(0);
}


void printPattern(int pattern)
{
	switch(pattern)
	{
		case 0:
			pattern0();
		break;

		case 1:
			pattern1();
		break;

		case 2:
			pattern2();
		break;

		default:
		break;
	}
}


void pattern0()
{
	printf("      ********     \n");
	printf("     **********    \n");
	printf("    ************   \n");
	printf("     **********    \n");
	printf("      ********     \n");
	printf("\n");
	
}

void pattern1()
{
	printf("    ************   \n");
	printf("    ************   \n");
	printf("    ************   \n");
	printf("    ************   \n");
	printf("    ************   \n");
	printf("\n");
	
}

void pattern2()
{
	printf("          *          \n");
	printf("         ***         \n");
	printf("        *****        \n");
	printf("       *******       \n");
	printf("        *****        \n");
	printf("         ***         \n");
	printf("          *          \n");
	printf("\n");
	
}