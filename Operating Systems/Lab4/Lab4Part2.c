/*Name: Nicholas Freeman
# Date: 01/29/2019 (the day you have lab) 
# Title: Lab4  
# Description: This program computes the thread IDs, without joining at the end
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREADS 10

void *go(void *);
pthread_t threads[NTHREADS];

int main() {
    static int i;
    for (i = 0; i < NTHREADS; i++)  
        pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
    printf("Main thread done.\n");
}

void *go(void *arg) {
    printf("Hello from thread %d with thread ID %d \n", (int)arg, (int)pthread_self());
    return (NULL);
}
