//Nicholas Freeman
//Lab 10--COEN 177L

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 10000
//Function to XOR contents of buffer
char *XOR(char *buffer1, char *buffer2){
    char *output[BUFFER_SIZE];
    int i = 0;
    for(i = 0; i < BUFFER_SIZE; i++)
	output[i] = (char)(buffer1[i] ^ buffer2[i]);
    return output;
}

int main(int argc, char *argv[]){
    //Standard error message if user does not provide appropriate file names
    if(argc < 3){
	printf("Please provide enough file names!.\n");
	exit(1);
    }

    //create two buffers of size 10000
    char *buffer1[BUFFER_SIZE];
    char *buffer2[BUFFER_SIZE];
    char *buffer3[BUFFER_SIZE];
    //Open files and destinations
    FILE *f1;
    FILE *f2;
    f1 = fopen(argv[1], "rb");
    f2 = fopen(argv[2], "rb");
    fflush(stdout);
    //write contents of first file
    while(fread(buffer1, 1, BUFFER_SIZE, f1)){
	fread(buffer2, 1, BUFFER_SIZE, f2);
	strcpy(buffer3, XOR(buffer1, buffer2));
	fwrite(buffer3, 1, BUFFER_SIZE, stdout);//Output buffer3 contents to stdout
	fprintf(stdout, buffer3);
	fflush(stdout);
    }
    

    //Write contents of second file
    /*while(fread(buffer2, 1, BUFFER_SIZE, f2)){
	strcpy(buffer3, buffer2);//Write buffer2 to buffer3
	fwrite(buffer3, 1, BUFFER_SIZE, stdout);//Output buffer3 contents to stdout
	fprintf(stdout, buffer3);
	fflush(stdout);
    }*/
    
    fclose(f1);
    fclose(f2);

    return 0;
    
}