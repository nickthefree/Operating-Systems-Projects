#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 
#include <sys/types.h> 
#include <sys/ipc.h>
int main(){
      char producer1[10] = "Producer 1";
      printf("%d\n", strlen(producer1));
      return 0;
}