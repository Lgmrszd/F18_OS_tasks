#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 1024

int main(int argc, char **argv) {
    int flags = O_RDWR | O_CREAT;
    int file_count = argc-1;
    int start_i = 1;
    int *files;
    if (argc > 1 && !strcmp(argv[1], "-a")) {
        flags |= O_APPEND;
        file_count -= 1;
        start_i = 2;
    } else {
        flags |= O_TRUNC;
    }
    if (file_count > 0) {
        files = malloc(sizeof(int) * file_count);
        for (int i = start_i; i < argc; i++) {
            files[i-start_i] = open(argv[i], flags, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
        }
    }
    int nread;
    char *buf = malloc(sizeof(char) * BUFSIZE);
    while (fgets(buf, BUFSIZE, stdin)) {
        printf("%s", buf);
        for (int i=0; i < file_count; i++) {
            write(files[i], buf, strlen(buf));
        }
    }
    
    return 0;
}
