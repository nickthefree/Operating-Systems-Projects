/* Name: Nicholas Freeman 

   Date: 1/15/2019  

   Title: Lab2 -- Programming in C and use of Systems Calls

   Description: This program runs two processes and shows how the PCB switches between processes based on time.
   The user also inputs delay. compiles without errors or warnings, make a copy of the source file then go to step 3.
*/
#include <pthread.h>

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

    if (pid){

        // Parent process

        for (i=0;i<100;i++) {

            printf("\t \t \t Parent Process %d \n",i);

            usleep(n);

        }

    }

    else{

        // Child process

        for (i=0;i<100;i++) {

            printf("Child process %d\n",i);

            usleep(n);

        }

    }

    return 0;

}