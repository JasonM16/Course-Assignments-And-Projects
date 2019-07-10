/*
 * PROJECT			: Assignment6
 * FILE				: netserver.c
 * AUTHOR			: Jason Choquette, 104337378
 * LAST MODIFIED 	: Mar. 21/17
 * DESCRIPTION	 	: A simple tcp/ip client
*/




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>


// Globals
int r; // random number between 0 and 2
int client_sockfd;

void alarmHandler(int signal_number)
{
	r = rand() % 3;	

	// write random num to socket
	write(client_sockfd, &r, sizeof(int));	

	// reset alarm
	alarm(2);

	// reactivate signal handler for next time ...
	signal (signal_number, alarmHandler);
}





int main(int argc, char const *argv[])
{
	int server_sockfd;	
	int server_len;
	int client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	/* obtain a socket for the server */
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_port = htons(9734);
	server_len = sizeof(server_address);

	/* Binding socket to server address ...*/
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

	/* install a signal handler for SIGCHILD (sent when the child terminates) 
	   we want to ignore when a child terminates. Otherwise, the server will
	   terminate as well
	*/
	signal(SIGCHLD, SIG_IGN);

	/* Begin listening on socket for incoming message ... */
	listen(server_sockfd, 5);

	/* install a signal handler for SIGALRM. This is the signal by which the server will periodically send 
	   clients random numbers. */
	signal(SIGALRM, alarmHandler);
	

	printf("Waiting for connection ...\n");
	
	/*
   * for this server, run an endless loop that will
   * accept incoming requests from a remote client.
   * the server will fork a child copy of itself to handle the
   * request, and the parent will continue to listen for the
   * next request
   */
	while(1)
	{		
		client_len = sizeof(client_address);

		/* accept a packet from the client */
		client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, &client_len);
		printf("Waiting for connection ...\n");
		
		// fork request to child
		if(fork() == 0)
		{	
			// need to call seed for each client or all random ints will be same for all clients
			srand(time(NULL));
			// signal an alarm for the alarm handler
			alarm(3);
		}	
		else
			close(client_sockfd);
	}

	return 0;
}