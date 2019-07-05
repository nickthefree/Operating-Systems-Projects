/* Name: Nicholas Freeman
# Date: 01/22/2019 
# Title: Lab3 
# Description: This program creates two producers and one consumer process. The producer processes write to the buffer
and the consumer process reads what's written on the buffer.
*/ 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h> 
#include <sys/types.h> 
#include <sys/ipc.h>
// main
int main(int argc,char *argv[]){
   int  fds[2];
   char buff[60];
   int count;
   int i;
   pipe(fds);
   if (fork()==0){//upstream(input)
       printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
       close(fds[0]);
       char producer1[12] = "Producer 1\n";
       for(i=0;i<10;i++){
           write(fds[1],producer1,strlen(producer1));
       }
       exit(0);
   }
   else if(fork()==0){//upstream 2
       printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
       close(fds[0]);
       char producer2[12] = "Producer 2\n";
       for(i=0;i<10;i++){
           write(fds[1],producer2,strlen(producer2));
       }
       exit(0);
    }
   else{
      close(fds[1]);
      while((count=read(fds[0],buff,60))>0){
           for(i=0;i<count;i++){
               write(1,buff+i,1);
	  }
      }
      close(fds[0]);
      wait(0);
      wait(0);
   }
return 0;
}
