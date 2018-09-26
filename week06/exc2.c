#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_BUFF_SIZE 80

int main () {
    char *src = "Hello! 345";
    char *dst = malloc(MAX_BUFF_SIZE);
    int my_pipe[2];
    pipe(my_pipe);
    int chpid = fork();
    if (chpid == -1) {
        return -1;
    } else if (chpid == 0) {
        write(my_pipe[1], src, MAX_BUFF_SIZE);
        printf("Sended to pipe: %s\n", src);
    } else {    
        read(my_pipe[0], dst, MAX_BUFF_SIZE);
        printf("Received from pipe: %s\n", dst);
    }
    return 0;
}
