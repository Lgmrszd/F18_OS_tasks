#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main () {
    char *src = "Hello! 345";
    int buffsize = (strlen(src)+1) * sizeof(char);
    char *dst = malloc(buffsize);
    int my_pipe[2];
    int i = pipe(my_pipe);
    write(my_pipe[1], src, buffsize);
    printf("Sended to pipe: %s\n", src);
    read(my_pipe[0], dst, buffsize);
    printf("Received from pipe: %s\n", dst);
    return 0;
}
