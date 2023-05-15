//
// Created by Gabriele Vianello on 15/05/23.
//

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"

void* MyTask(void* arg){
    long int a = (long int) arg;
    printf("THREAD: execution started\n");
    printf("THREAD: argument-> %ld\n", a);
    printf("THREAD: pid-> %d  |  tid-> %ld\n", getpid(), pthread_self());
    printf("THREAD: terminated\n");
    pthread_exit((void*)456);
}

int main(int argc, char *argv[]){
    pthread_t tid;
    int status;
    long int argument;
    long int retval;

    printf("MAIN: pid-> %d  |  tid-> %ld\n", getpid(), pthread_self());
    printf("MAIN: creating new thread %ld\n", tid);

    argument = 123;
    status = pthread_create(&tid, NULL, MyTask, (void*) argument);

    if(status!=0){
        printf("MAIN: thread not created\n");
        exit(1);
    }

    pthread_join( tid, (void*)&retval);
    printf ("MAIN: thread returned %ld\n", &retval);
    printf( "MAIN: thread terminated\n" );
    exit (0);
    return 0;
}
#pragma clang diagnostic pop