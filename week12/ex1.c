#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define N 20

int main() {
    int fd_in, fd_out;
    char *data = malloc(sizeof(char) * (N+1));
    
    fd_in = open("/dev/random", O_RDONLY);
    read(fd_in, data, N);
    data[N]=0;
    printf("%s\n", data);
    fd_out = open("ex1.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    write(fd_out, data, N+1);
    return 0;
}
