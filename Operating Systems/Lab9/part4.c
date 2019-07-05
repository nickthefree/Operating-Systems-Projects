#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define NTHREADS 2

//pthread_mutex_t lock;
//create structure to hold information to pass to thread

struct information{
    int buff;
    int num;
    int namelength;
    char OGname[20];
    char copyName[20];

} info;

void copy(void *i);

int main(int argc, char *argv[]){
    int buff2 = atoi(argv[2]);
    //printf("%d\n", info.buff);
    info.buff = atoi(argv[2]);
    info.num = 0;
    info.namelength = atoi(argv[1]);
    strcpy(info.OGname, argv[1]);
    strcpy(info.copyName, "copy  .txt");
    int max = atoi(argv[3]);
    int i = 0;
    int nothing = 0;
    pthread_t threads[max];

    for (i = 0; i < max; i++){
        pthread_create(&threads[i], NULL, copy, (void *)(int)nothing);
    }
    for (i = 0; i < max; i++) {
        pthread_join(threads[i], NULL);
	    printf("Thread %d returned \n", i);
    }
    
    //pthread_mutex_destroy(&lock);

    return 0;  
}

void copy(void *nada){
    //critical section
    //pthread_mutex_lock(&lock);
    char buffer[info.buff];
    //Character Arithmetic 
    if(info.num < 10){
	info.copyName[4] = '0';
	info.copyName[5] = (info.num) + '0';
    }
    else{
	info.copyName[4] = (info.num/10) + '0';
	info.copyName[5] = (info.num%10) + '0';
    }
    
    FILE *f1, *f2;
    f1 = fopen(info.OGname, "rb");
    f2 = fopen(info.copyName, "wb");
    
    while(fread(buffer, 1, info.buff, f1)){
	  //printf("newline\n");
	  fwrite(buffer, 1, info.buff, f2);
    }
    info.num += 1;
    
    fclose(f1);
    fclose(f2);
    //end critical section
    //pthread_mutex_unlock(&lock);
}

/*
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
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i],NULL);
	    printf("Thread %d returned \n", i);
    }
    printf("Main thread done.\n");
}

void *go(void *arg) {
    printf("Hello from thread %d with thread ID %d \n", (int)arg, (int)pthread_self());
    return (NULL);
}
*/