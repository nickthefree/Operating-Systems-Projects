/* Name: Nicholas Freeman
# Date: 02/5/2019 (the day you have lab) 
# Title: Lab5
# Description: This program solves the consumer producer problem using semaphores. 
*/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <fcntl.h>
#define NTHREADS 10

pthread_t threads[NTHREADS];

sem_t *mutex;

void* go(void* arg) {
    sem_wait(mutex); //entry section
    printf("Thread %d Entered Critical Section..\n", (int)arg); //critical section
    sleep(1);
    sem_post(mutex); //exit section
    return (NULL);
}

int main() {
    mutex = sem_open("Semaphore", O_CREAT, 0644, 1);
    static int i;
    for (i = 0; i < NTHREADS; i++)
	pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
    for (i = 0; i < NTHREADS; i++) {
	pthread_join(threads[i],NULL);
	printf("Thread %d returned \n", i);
    }

    printf("Main thread done.\n");
    sem_unlink("Semaphore");
    return 0;
}