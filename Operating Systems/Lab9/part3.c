#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct information{
    int buff;
    int num;
    int namelength;
    char OGname[20];
    char copyName[20];

} info;
    
int main(int argc, char *argv[]){
    int buff2 = atoi(argv[2]);
    //create structure to hold information to pass to thread
    printf("%d", info.buff);
    info.buff = atoi(argv[2]);
    info.num = 0;
    info.namelength = atoi(argv[1]);
    strcpy(info.OGname, argv[1]);
    strcpy(info.copyName, "copy  .txt");
    
    //info->buffer = (char *) malloc((buff2) * sizeof(char));
    
    if(info.num < 10){
	info.copyName[4] = '0';
	info.copyName[5] = (info.num) + '0';
    }
    
    else{
	info.copyName[4] = (info.num/10) + '0';
	info.copyName[5] = (info.num%10) + '0';
    }
    
    int buff = atoi(argv[2]);
    char buffer[info.buff];
    int a = strlen(argv[1]);
    char name[a];
    strcpy(name, argv[1]);
    
    FILE *f1, *f2;
    f1 = fopen(info.OGname, "rb");
    f2 = fopen(info.copyName, "wb");
    
    while(fread(buffer, 1, info.buff, f1)){
	  //printf("newline\n");
	  fwrite(buffer, 1, info.buff, f2);
    }
    
    fclose(f1);
    fclose(f2);
    return 0;
}

    /*if(i < 10){
	  c[4] = (i/10) + '0';
	  c[4] = (i%10) + '0';
    }
    */