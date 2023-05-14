//
// Created by Gabriele Vianello on 14/05/23.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define CAP 777

int main(){
    int children[10];
    for(int i = 0; i<10; i++){
        int pid=fork();
        if(pid<0)return 1;
        if(pid>0)children[i]=pid;
        if(pid==0)exit(i%2==0? 0:1); //lambda func
    }

    for(int i=0; i<10; i++){
        int status;
        waitpid(children[i], &status,0);
        if(WEXITSTATUS(status)==0)printf("[%d] terminated with no errors\n", children[i]);
        else printf("[%d] CAP error\n",children[i]);
    }

    return 0;
}