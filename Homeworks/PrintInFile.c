/**
 * Created by Gabriele Vianello on 31/05/23.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char file[20];

    printf("Insert file name: ");
    scanf("%s", file);

    int file_descriptor = open(file, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (file_descriptor == -1) {
        printf("Error in file opening.");
        return 404;
    }

    pid_t pid = fork();

    if (pid == 0) {
        ssize_t byte_written = write(file_descriptor, "hello", strlen("hello"));
        if (byte_written == -1) {
            printf("Error in write");
            return 1;
        }
        close(file_descriptor);
        exit(0);
    } else if (pid > 0) {
        wait(NULL);
        ssize_t byte_written = write(file_descriptor, "world", strlen("world"));
        if (byte_written == -1) {
            printf("Error in write");
            close(file_descriptor);
            return 1;
        }
        close(file_descriptor);
    } else {
        printf("Error in fork");
        close(file_descriptor);
        return 1;
    }

    return 0;
}
