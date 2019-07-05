#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define BUFF_SIZE 10000

int main(int argc, char *argv[]){
    char *buffer[BUFF_SIZE];
   
    FILE *f1;
    f1 = fopen(argv[1], "rb");
    
    while(fread(buffer, 1, BUFF_SIZE, f1))
	  //printf("newline\n");
      
    fclose(f1);

    
    return 0;
}