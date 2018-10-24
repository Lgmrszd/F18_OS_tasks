#include <stdio.h>
#include <unistd.h>

int main() {
    int n = 100;
    int fork_pid;
    fork_pid = fork();
    if (fork_pid == 0) {
        printf("Hello from child! [%d - %d]\n", fork_pid, n);
    } else if (fork_pid > 0) {
        printf("Hello from parent! [%d - %d]\n", fork_pid, n);
    } else {
        printf("Fork error");
        return fork_pid;
    }
    return 0;
}
