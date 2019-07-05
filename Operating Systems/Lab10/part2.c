//Nicholas Freeman
//Lab 10--COEN 177L

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 10000
//XOR content of two buffers


char *XOR(char *buffer1, char *buffer2){
    char *output[BUFFER_SIZE];
    int i = 0;
    for(i = 0; i < BUFFER_SIZE; i++)
	output[i] = (char)(buffer1[i] ^ buffer2[i]);
    return output;
}



//Copy function to make code more modular.
void Compare(char *buffer1[BUFFER_SIZE], char *buffer2[BUFFER_SIZE], FILE *f1, FILE *f2, FILE* temp){
    char *tmp[BUFFER_SIZE];
    while(fread(buffer1, 1, BUFFER_SIZE, f1)){
	fread(buffer2, 1, BUFFER_SIZE, f2);
	strcpy(tmp, XOR(buffer1, buffer2));//Write XOR buffer1 and buffer2 to buffer2
	fwrite(tmp, 1, BUFFER_SIZE, temp);//Output buffer2 contents to temp1
	//Print buffer contents to stdout
	//Flush stdout
    }
}


void CopyOut(char *buffer1[BUFFER_SIZE], char *buffer2[BUFFER_SIZE], FILE *f1){
    char *tmp[BUFFER_SIZE];
    while(fread(buffer1, 1, BUFFER_SIZE, f1)){
	strcpy(buffer2, buffer1);
	fwrite(buffer2, 1, BUFFER_SIZE, stdout);//Output buffer3 contents to stdout
	fprintf(stdout, buffer2);
	fflush(stdout);
    }
}


int main(int argc, char *argv[]){
    //Standard error message if user does not provide appropriate file names
    if(argc <= 2){
	printf("Please provide enough file names!.\n");
	exit(1);
    }
    if(argc > 11) {//if we have more than 10 inputs return an error to user
	printf("Too many file inputs!\n");
	exit(1);
    }

    //create buffers of size 10000
    char *buffer1[BUFFER_SIZE];
    char *buffer2[BUFFER_SIZE];
    char *buffer3[BUFFER_SIZE];

    
    //Open files and destinations
    FILE *temp1;
    temp1 = fopen("temp1.txt", "w+b");
    FILE *temp2;
    temp2 = fopen("temp2.txt", "w+b");

    FILE *f1;
    f1 = fopen(argv[1], "rb");

    //Nested if statements to XOR up to 10 different input files
    /*if(argc >= 2){
	FILE *f1;
	f1 = fopen(argv[1], "rb");
	fclose(f1);*/
    
	if(argc >= 3){
	    FILE *f2;
	    f2 = fopen(argv[2], "rb");
	    Compare(buffer2, buffer3, f1, f2, temp1); //Compare f1 and f2 and put new file in temp1
	    fclose(f2);
	    fseek(temp1, 0, SEEK_SET);
	    if(argc == 3)//If these are our only files, put temp1 into stdout
		CopyOut(buffer1, buffer2, temp1);
		
	    
	    if(argc >= 4){
		FILE *f3;
		f3 = fopen(argv[3], "rb");
		Compare(buffer2, buffer3, f3, temp1, temp2);//temp2 holds new XOR file
		fseek(temp2, 0, SEEK_SET);
		fclose(f3);
		remove("temp1.txt");
		fclose(temp1);
		if(argc == 4)//If there are only 4 arguments
		    CopyOut(buffer1, buffer2, temp2);//Put temp2 into stdout
		
		if(argc >= 5){
		    FILE *temp3 = fopen("temp3.txt", "w+b");
		    FILE *f4;
		    f4 = fopen(argv[4], "rb");
		    Compare(buffer2, buffer3, f4, temp2, temp3);//temp1 holds new XOR file
		    fseek(temp3, 0, SEEK_SET);
		    fclose(f4);
		    remove("temp2.txt");
		    fclose(temp2);
		    
		    if(argc == 5)
			CopyOut(buffer2, buffer3, temp3);
		    
		    
		    if(argc >= 6){
			FILE *temp4 = fopen("temp4.txt", "w+b");
			FILE *f5;
			f5 = fopen(argv[5], "rb");
			Compare(buffer2, buffer3, f5, temp3, temp4);
			fseek(temp4, 0, SEEK_SET);
			fclose(f5);
			remove("temp3.txt");
			fclose(temp3);

			
			if(argc == 6)
			    CopyOut(buffer2, buffer3, temp4);
			
			if(argc >= 7){
			    FILE *f6;
			    FILE *temp5 = fopen("temp5.txt", "w+b");
			    f6 = fopen(argv[6], "rb");
			    Compare(buffer2, buffer3, f6, temp4, temp5); //copies data from first file to stdout.
			    fclose(f6);
			    remove("temp4.txt");
			    fclose(temp4);
			    fseek(temp5, 0, SEEK_SET);
			    
			    if(argc == 7)
				CopyOut(buffer2, buffer3, temp5);
			    
			    if(argc >= 8){
				FILE *temp6 = fopen("temp6.txt", "w+b");
				FILE *f7;
				f7 = fopen(argv[7], "rb");
				Compare(buffer2, buffer3, f7, temp5, temp6); //Copies data from second file to stdout.
				fclose(f7);
				remove("temp5.txt");
				fclose(temp5);
				fseek(temp6, 0, SEEK_SET);
				
				if(argc == 8)
				    CopyOut(buffer2, buffer3, temp6);
				
				if(argc >= 9){
				    FILE *temp7 = fopen("temp7.txt", "w+b");
				    FILE *f8;
				    f8 = fopen(argv[8], "rb");
				    Compare(buffer2, buffer3, f8, temp6, temp7);
				    fclose(f8);
				    remove("temp6.txt");
				    fclose(temp6);
				    fseek(temp7, 0, SEEK_SET);
				    
				    if(argc == 9)
					CopyOut(buffer2, buffer3, temp7);
				    
				    if(argc >= 10){
					FILE *temp8 = fopen("temp8.txt", "w+b");
					FILE *f9;
					f9 = fopen(argv[9], "rb");
					Compare(buffer2, buffer3, f9, temp7, temp8);
					fseek(temp8, 0, SEEK_SET);
					remove("temp7.txt");
					fclose(temp7);
					fclose(f9);
					if(argc == 10)
					    CopyOut(buffer2, buffer3, temp8);
					
					if(argc >= 11){
					    FILE *temp9 = fopen("temp9.txt", "w+b");
					    FILE *f10;
					    f10 = fopen(argv[10], "rb");
					    Compare(buffer2, buffer3, f10, temp8, temp9);
					    remove("temp8.txt");
					    fclose(temp8);
					    fclose(f10);
					    fseek(temp9, 0, SEEK_SET);
					    
					    if(argc == 11){
						CopyOut(buffer2, buffer3, temp9);
						remove("temp9.txt");
						fclose(temp9);
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}


    return 0;
    
}