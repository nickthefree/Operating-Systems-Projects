#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 1024
#define NTHREADS 4

int step_i = 0; 

void *go(void *);
pthread_t threads[NTHREADS];

void matrixMultiply();
void matrixMultiplyT(void* arg);

float a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE] = 0.0;

int main() {
    static int n;
    for (n = 0; n < NTHREADS; n++)  
        pthread_create(&threads[n], NULL, matrixMultiplyT, (void *)(size_t)n);
    printf("Main thread done.\n");
    
}

void *go(void *arg) {
    printf("Hello from thread %d with thread ID %d \n", (int)arg, (int)pthread_self());
    return (NULL);
}


void matrixMultiply(){
    unsigned i, j, k;
    for (i = 0; i < SIZE; i++)
	for (j = 0; j < SIZE; j ++)
	    for (k = 0; k < SIZE; k++)
		c[i][j] += a[i][k]*b[k][j];
}

void matrixMultiplyT(void* arg) 
{ 
    
    unsigned i, j, k;
    for (i = step_i; i < step_i; i++)
	for (j = 0; j < SIZE; j ++)
	    for (k = 0; k < SIZE; k++)
		c[i][j] += a[i][k]*b[k][j];
} 