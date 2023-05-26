 /**
  * Created by Vinello28 on 26/05/2023.
  */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


 int main (){
     printf("---- PRINT PID ----\n");
     int pidP = getpid();
     int pidS = fork();
     printf("PID father: %d\n PID son: %d", pidP, pidS);
     if(pidS == -1)printf("ERROR: in creating another process");
     wait(&pidS);
     return 0;
 }
