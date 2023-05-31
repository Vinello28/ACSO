/**
 * Created by Gabriele Vianello on 31/05/23.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    int status;

    for (int i = 0; i < 10; i++) {
        child_pid = fork();

        if (child_pid == 0) {
            if (getpid() % 2 == 0) exit(0);
            else exit(1);
        }
    }

    for (int i = 0; i < 10; i++) {
        pid_t pid = wait(&status);

        if (WIFEXITED(status) && WEXITSTATUS(status) == 1) {
            printf("Error in child process with PID: %d\n", pid);
        }
    }

    return 0;
}
