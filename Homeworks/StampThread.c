/**
 * Created by Gabriele Vianello on 31/05/23.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* Stamp(char *v){
    int i;

    for(i = 0; i<10; i++){
        printf("%s\n", v);
        fflush(stdout);
        usleep(1000000);
    }
    pthread_exit(NULL);
}

int main(int argc, char** argv){
    char str[14] = {"Hello World!"};
    pthread_t t;
    pthread_create(&t, NULL, &Stamp, (void *) str);
    pthread_join(t, NULL);
    return 0;
}