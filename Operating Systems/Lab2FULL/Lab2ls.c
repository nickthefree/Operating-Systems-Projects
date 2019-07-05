/* Name: Nicholas Freeman 

   Date: 1/15/2019  

   Title: Lab2 -- Programming in C and use of Systems Calls

   Description: This program computes the same program as Step 1, except the child process runs the ls command 
   and the parent process waits until the child process is finished to terminate.
*/
#include <stdio.h>      /* printf, stderr */

#include <sys/types.h>  /* pid_t */

#include <unistd.h>     /* fork */

#include <stdlib.h>     /* atoi */

#include <errno.h>      /* errno */ 

int main(int argc, char *argv[]) {

    pid_t  pid;

    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay

    printf("\n Before forking.\n");

    pid = fork();

    if (pid == -1) {

        fprintf(stderr, "can't fork, error %d\n", errno);

    }

   

    else if(pid == 0)

    {

        execlp("/bin/ls", "ls", NULL);

    }

    else

    {

        wait(NULL);

        printf("Child Complete");

        exit(0);

    }

    return 0;

}