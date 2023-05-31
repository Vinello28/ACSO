/**
 * Created by Gabriele Vianello on 31/05/23.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char** argv){
    pid_t pid;
    char* arg[] = {"./SecondaryExec", "hello", "world", NULL};
    pid=fork();

    if(pid == 0){
        printf("\nChild pid %d\n", (int) getpid());
        execvp("./SecondaryExec.c", arg);
    }else printf("\nParent pid %d\n", (int) getpid());

}