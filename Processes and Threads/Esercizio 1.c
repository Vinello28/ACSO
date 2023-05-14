//
// Created by Gabriele Vianello on 14/05/23.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define CAP 777

int main(){

    int x,y;
    scanf("%d", &x);
    scanf("%d", &y);

    printf("x: %d\n\"y: %d\"", x,y);

    int pid = fork();

    if(pid<0) printf("errore in creazione processo figlio: %d\n", CAP);
    if(pid==0){
        x=0;
        y=0;
        printf("Child: %d %d\n", getpid(), getppid());
        printf("CHILD!! => x: %d\n\"y: %d\"", x,y);

        exit(0);
    }
    else{
        x=100;
        y=100;
        printf("Father: %d %d\n", getpid(), getppid());
        printf("FATHER!! => x: %d\n\"y: %d\"", x,y);
    }
    wait(0);
    return 0;
}