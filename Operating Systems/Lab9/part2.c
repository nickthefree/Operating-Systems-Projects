#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 10000

int main(int argc, char *argv[]){
    int buff = atoi(argv[2]);
    char *buffer[buff];
    
    FILE *f1;
    f1 = fopen(argv[1], "rb");
    
    while(fread(buffer, 1, buff, f1))
	  //printf("newline\n");
      
    fclose(f1);

    return 0;
}