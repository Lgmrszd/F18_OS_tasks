#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define N 5

int tries = 3;

void listener(int sig) {
    if (tries == 0){
        printf("\nAborting!\n");
        exit(1);
    }
    printf("\nWARNING: Interrupting important tasks. Do you really wabt to do it? (%d tries remain)\n", tries);
    tries--;
}

int main() {
    srand(time(NULL));
    signal(SIGINT, listener);
    const char *verb[] = {"Starting up", "Booting", "Repairing", "Loading", "Checking"};
    const char *adje[] = {"master", "radiant", "silent", "harmonic", "fast"};
    const char *noun[] = {"solar array", "particle reshaper", "cosmic ray", "orbiter", "bit"};
    while (1) {
        int v, a, n, w;
        v = rand() % N;
        a = rand() % N;
        n = rand() % N;
        w = rand() % 11;
        printf("[ %s %s %s ] ... ", verb[v], adje[a], noun[n]);
        fflush(stdout);
        usleep(w*200000);
        printf("Complete!\n");
    }
    return 0;
}
