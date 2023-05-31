/**
 * Created by Gabriele Vianello on 27/05/23.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){
    int x, y;
    printf("Inserire il primo numero: ");
    scanf("%d", &x);
    printf("\n\nInserire il secondo numero: ");
    scanf("%d", &y);
    pid_t pid = fork();
    if(pid == 0){
        x = x+y;
        y = y+10;
        printf(" %d ", x);
        printf(" %d ", y);
    }
    else{
        wait((int *) pid);
        printf("\n %d ", x);
        printf(" %d ", y);
    }
}