 /**
  * Created by Vinello28 on 26/05/2023.
  */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


 int main (int argc, char** argv){
     pid_t pid;

     printf("---- PRINT PID ----\n");
     pid = fork();
     printf("Child PID: %d\n", (int)getpid());
     printf("Father PID: %d", (int) getppid());

     return 0;
 }
