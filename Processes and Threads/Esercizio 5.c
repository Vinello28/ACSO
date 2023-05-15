//
// Created by Gabriele Vianello on 15/05/23.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* foo(void* args){
    int n = (int) args;
    pthread_mutex_lock(&mutex);
    printf("Starting TID: %lu\n", pthread_self());
    sleep(2);
    printf("Stopping TID: %lu\n", pthread_self());
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(int argc, char** argv){
    pthread_t t1, t2, t3, t4;
    if(pthread_create(&t1, NULL, foo, (void*) 1)){
        return 1;
    }
    if(pthread_create(&t2, NULL, foo, (void*) 1)){
        return 1;
    }
    if(pthread_create(&t3, NULL, foo, (void*) 1)){
        return 1;
    }
    if(pthread_create(&t4, NULL, foo, (void*) 1)){
        return 1;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);


}
#pragma clang diagnostic pop