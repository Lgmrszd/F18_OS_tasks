#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#define N 10

int main() {
    struct rusage *usage = malloc(sizeof(struct rusage));
    const int size = 10*1024*1024;
    for (int i = 0; i < N; i++) {
        unsigned char *dat = malloc(size);
        memset(dat, 0, size);
        getrusage(RUSAGE_SELF, usage);
        printf("Usage: %ld\n", usage->ru_maxrss);
        sleep(1);
    }
    return 0;
}
