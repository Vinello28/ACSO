/**
 * Created by Gabriele Vianello on 31/05/23.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutexObj;
pthread_t t1,t2,t3,t4;

void* number(int x){
    pthread_mutex_lock(&mutexObj);
    printf("\nStarting %d", pthread_self());
    fflush(stdout);
    usleep(2000000);
    printf("\nNumber: %d", x);
    printf("\nEnding %d", pthread_self());
    pthread_mutex_unlock(&mutexObj);
    pthread_exit(NULL);
}

int main (int argc, char** argv){
    int in;
    printf("Type a number: ");
    scanf("%d", &in);

    pthread_create(&t1, NULL, &number, (void *) in);
    pthread_create(&t2, NULL, &number, (void *) in);
    pthread_create(&t3, NULL, &number, (void *) in);
    pthread_create(&t4, NULL, &number, (void *) in);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

}
