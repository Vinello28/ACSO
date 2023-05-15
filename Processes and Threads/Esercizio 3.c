//
// Created by Gabriele Vianello on 15/05/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int flag = 1;

void sigusr1_handler(int sig){
    printf("OUT: Signal SIGUSR1 received\n");
}

void sigusr2_handler(int sig){
    exit(1);
}

int main(){
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);

    while(flag){
        printf("waiting signals...");
        sleep(1);
    }
    printf("Process terminated\n");
    return 0;
}