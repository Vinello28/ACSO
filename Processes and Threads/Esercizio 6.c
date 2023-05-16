//
// Created by Gabriele Vianello on 16/05/23.
//

#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct node{
    char value;
    struct node* next;
}node_t;

node_t* list;
sem_t semaphore;

void PushFront(char value){
    node_t* new = (node_t*) malloc(sizeof(node_t));
    new->value=value;
    new->next=list;

    list = new;
}

char PopFront(node_t* list){
    if(list==NULL)return NULL;
    node_t* first = list;
    char retval = first->value;
    list = first->next;
    free(first);
    return retval;
}

void* Producer(void* args){
    char character = 'a';
    for(int i = 0; i<10; i++){
        PushFront(character+i);
        sem_post(&semaphore);
        sleep(2);
    }
    pthread_exit(NULL);
}

void* Consumer(void* args){
    int n = (int) args;
    for(int i = 0; i<n; i++){
        sem_wait(&semaphore);
        node_t* node = (node_t *) PopFront(list);
        printf("TID[%lu]  %c\n", pthread_self(), node->value);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t t0, t1, t2, t3, t4;

    sem_init(&semaphore, 0, 0);
    if(pthread_create(&t0, NULL, Producer, NULL) != 0)return 1;
    if(pthread_create(&t1, NULL, Consumer, (void*)5) != 0)return 1;
    if(pthread_create(&t2, NULL, Consumer, (void*)1) != 0)return 1;
    if(pthread_create(&t3, NULL, Consumer, (void*)2) != 0)return 1;
    if(pthread_create(&t4, NULL, Consumer, (void*)2) != 0)return 1;

    pthread_join(t0, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    sem_destroy(&semaphore);
    return 0;
}