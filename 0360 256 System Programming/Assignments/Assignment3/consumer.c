/*
    FILE            : consumer.c
    AUTHOR          : Jason Choquette, 104 337 378
    LAST MODIFIED   : March 11, 2017
    DESCRIPTION     : This program reads an integer value from a 
                      file then decreases the value by 3 and writes
                      the the modified value back to the file. Once
                      the file has been written to and a statement 
                      has been printed to the user, a child is forked
                      and the child creates a new system call to a bash
                      script.                        
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char * args[])
{
    char * fileName = "./storage";
    int num = 0;
    int status;

    FILE* file = fopen (fileName, "r");

    if(file == NULL)
        perror("Error opening file %s. Exiting program.\n", fileName); exit(1);

    fscanf(file, "%d", &num);
    fclose(file);
    num -= 3;
    printf("from consumer: current total is %d\n", num);
    file = fopen (fileName, "w");
    fprintf (file, "%d",num);
    fclose(file);

    if(fork() == 0)
    {
    	// this is thie printing a new user prompt in the terminal on the first hit!!
        execl("./producer", "producer", (char *) NULL);        
        /* exec*()-functions do not return on success, so we only get here in case of error. */
        perror("execl() failed");
    }
    else
        wait(&status);

    return 0;
}