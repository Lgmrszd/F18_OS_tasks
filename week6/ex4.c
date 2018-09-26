#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define N 5

int tries = 4;

void listener_kill(int sig) {
    if (tries == 0){
        printf("\nExiting\n");
        exit(0);
    }
    printf("SIGKILL received, %d tries remain\n", tries);
    tries--;
}

void listener_int(int sig) {
    if (tries == 0){
        printf("\nExiting\n");
        exit(0);
    }
    printf("SIGINT received, %d tries remain\n", tries);
    tries--;
}

void listener_stop(int sig) {
    if (tries == 0){
        printf("\nExiting\n");
        exit(0);
    }
    printf("SIGSTOP received, %d tries remain\n", tries);
    tries--;
}

void listener_usr1(int sig) {
    if (tries == 0){
        printf("\nExiting\n");
        exit(0);
    }
    printf("SIGUSR1 received, %d tries remain\n", tries);
    tries--;
}

int main() {
    srand(time(NULL));
    signal(SIGKILL, listener_kill);
    signal(SIGINT, listener_int);
    signal(SIGSTOP, listener_stop);
    signal(SIGUSR1, listener_usr1);
    while (1) {
        usleep(1000000);
        printf("Working\n");
    }
    return 0;
}
