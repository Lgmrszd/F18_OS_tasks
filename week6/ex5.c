#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define N 5

int tries = 4;

void listener_term(int sig) {
    printf("CH: I don't feel so good...\n");
    printf("-- CH then dies --\n");
    exit(0);
}

int main() {
    printf("Dramatis personae:\n");
    printf("CH as Child\n");
    printf("PA as Parent\n");
    printf("== Act 1 ==\n");
    printf("-- PA hanging around in CPU --\n");
    int pid = fork();
    if (pid == -1) {
        printf("PA: I am childless!\n== End of Act 1 ==\n");
        return 1;
    } else if (pid == 0) {
        printf("CH: I was born! I can see the beauty of this world!\n");
        signal(SIGTERM, listener_term);
        while (1) {
            printf("CH: The world is so nice!\n");
            sleep(1);
        }
    } else {
        printf("PA: My child was born!\n");
        sleep(4);
        printf("PA: Thats cool so I am surely not gonna make something terrible\n");
        printf("-- PA then proceeds to kill CH --\n");
        kill(pid, SIGTERM);
        printf("PA: Nothing happened and everything is ok\n");
        sleep(1);
        printf("== End of Act 1 ==\n");
    }
    return 0;
}
