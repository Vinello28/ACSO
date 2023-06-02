/**
 * Created by Gabriele Vianello on 2/06/23.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t obj;
sem_t semaforo;
char buffer;

/**
 * Initialize the algorithm.
 */
void init(){
    sem_init(&semaforo, 0, 1);
}

/**
 * Final operations: deallocation, ecc.
 */
void end(){
    sem_destroy(&semaforo);
}

/**
 * Fill buffer with 'a' every two seconds for ten times
 */
void* producer(){
    for (int i = 0; i < 10; ++i) {
        pthread_mutex_lock(&obj);
        usleep(2000);
        buffer = 'a';
        sem_post(&semaforo);
        pthread_mutex_unlock(&obj);
    }
    return NULL;
}

/**
 * Print buffer's char in stdout for n times
 * @param n number of times the function prints buffer;
 */
void* consumer(int n){
    printf("\nSTART: %d", pthread_self());
    for (int i = 0; i < n; ++i) {
        sem_wait(&semaforo);
        pthread_mutex_lock(&obj);
        printf("\n%d : %c", pthread_self(), buffer);
        buffer = 'z';
        pthread_mutex_unlock(&obj);
    }
    return NULL;
}

int main(int argc, char** argv){
    init();

    pthread_t tp, tc1,tc2,tc3,tc4;
    printf("\nInsert a number: ");
    int n;
    scanf("%d\n", &n);
    pthread_create(&tp, NULL, &producer, NULL);
    pthread_create(&tc1, NULL, &consumer, (void*) n);
    pthread_create(&tc2, NULL, &consumer, (void*) n);
    pthread_create(&tc3, NULL, &consumer, (void*) n);
    pthread_create(&tc4, NULL, &consumer, (void*) n);

    pthread_join(tp, NULL);
    pthread_join(tc1, NULL);
    pthread_join(tc2, NULL);
    pthread_join(tc3, NULL);
    pthread_join(tc4, NULL);

    end();
    return 0;
}
