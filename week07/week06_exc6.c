#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <wait.h>

#define N 5

int c1_p[2];

void parent_func(int pid1, int pid2) {
    int c2_stat;
    printf("PA: I am gonna tell my first child that id of my second child is %d\n", pid2);
    write(c1_p[1], &pid2, sizeof(int));
    printf("PA: Now I will wait until something happens to my second child\n");
    waitpid(pid2, &c2_stat, WUNTRACED);
    if (WIFSTOPPED(c2_stat)) {
        printf("PA: My second child has stopped!\n");
    } else {
        printf("PA: something happened to my second child!\n");
    }
    printf("== End of Act 2 ==\n");
}

void child1_func() {
    int pid2;
    read(c1_p[0], &pid2, sizeof(int));
    printf("C1: I was born! I can see the beauty of this world!\n");
    printf("C1: Parent told me that id of my subling is %d\n", pid2);
    sleep(4);
    printf("C1: I am gonna tell my subling to stop\n");
    kill(pid2, SIGSTOP);
}

void child2_func() {
    printf("C2: I was born! I can see the beauty of this world!\n"); 
    while (1) {
        printf("C2: What a wonderful world!\n");
        sleep(1);
    }
}

int main() {
    printf("Dramatis personae:\n");
    printf("PA as Parent\n");
    printf("C1 as Child 1\n");
    printf("C2 as Child 2\n");
    printf("== Act 2 ==\n");
    printf("-- PA hanging around in CPU --\n");
    pipe(c1_p);
    int pid1 = fork();
    if (pid1 == -1) {
        printf("PA: I am childless!\n== End of Act 2 ==\n");
        return 1;
    } else if (pid1 == 0) {
        child1_func();
    } else {
        int pid2 = fork();
        if (pid2 == -1) {
            printf("PA: I am childless!\n== End of Act 2 ==\n");
            return 1;
        } else if (pid2 == 0) {
            child2_func();
        } else {
            parent_func(pid1, pid2);
        }
    }
    return 0;
}
