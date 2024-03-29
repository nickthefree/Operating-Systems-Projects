/*Name: Nicholas Freeman
# Date: 01/29/2019 (the day you have lab) 
# Title: Lab4
# Description: This program computes the multiplication of two matrices using multiple threads
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

#define NTHREADS 1024

#define SIZE 1024

int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE], d[SIZE][SIZE] = {0};

bool is_result_correct();

void matrixMultiply();

void matrixMultiplyT();

pthread_t threads[NTHREADS];

void printm();

int fill();

int main(){
    static int i;
    fill();
    for (i = 0; i < NTHREADS; i++)  
        pthread_create(&threads[i], NULL, matrixMultiplyT, (void *)(size_t)i);
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i],NULL);
	    printf("Thread %d returned \n", i);
    }
    matrixMultiply();
    printf("Print 1 if correct, 0 if incorrect: %d\n", is_result_correct());
    //printm();
    printf("Main thread done.\n");
}
//Original Multiplication function
void matrixMultiply(){
unsigned i, j, k;
for (i = 0; i < SIZE; i ++)
    for (j = 0; j < SIZE; j ++)
	for (k = 0; k < SIZE; k++)
	    c[i][j] += a[i][k] * b[k][j];
}
//Thread multiplication function
void matrixMultiplyT(int l){

unsigned i, j, k;

for(j = 0; j < SIZE; j ++)
    for (k = 0; k < SIZE; k++)
	d[l][j] += a[l][k] * b[k][j];
}
//Function to tell whether or not matrix is correct
bool is_result_correct(){
    int i, j;
    
    for (i = 0; i < SIZE; i++)
	for (j=0; j <SIZE; j++)
	    if (c[i][j] != d[i][j])
		return false;
	    
    return true;
}
//Function that fills matrices with integers of random values from 0-5
int fill(){
    for (int i = 0; i < SIZE; i++) { 
	for (int j = 0; j < SIZE; j++) { 
	    a[i][j] = rand() % 6; 
	    b[i][j] = rand() % 6; 
	} 
    } 
}
//Function used solely for debugging
void printm(){
    for(int i = 0; i < SIZE; i++){
	for(int j = 0; j < SIZE; j++){
	    printf("%d ", a[i][j]);
	}
	printf("\n");
    }
    printf("\n\n\n");
    for(int i = 0; i < SIZE; i++){
	for(int j = 0; j < SIZE; j++){
	    printf("%d ", b[i][j]);
	}
	printf("\n");
    }
    printf("\n\n\n");
    for(int i = 0; i < SIZE; i++){
	for(int j = 0; j < SIZE; j++){
	    printf("%d ", c[i][j]);
	}
	printf("\n");
    }
    printf("\n\n\n");
    for(int i = 0; i < SIZE; i++){
	for(int j = 0; j < SIZE; j++){
	    printf("%d ", d[i][j]);
	}
	printf("\n");
    }
}