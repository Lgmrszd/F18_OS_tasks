#include <stdio.h>
#include <pthread.h>
#define N 10


pthread_t _threads[10];

void *routine(void *arg) {
        printf("Text in thread number  >> %d !!!\n", *((int *) arg));
    pthread_exit(NULL);
}


int main() {
    for (int i = 0; i < N; i++) {
        printf("Creating thread number ++ %d\n", i);
        pthread_create(&_threads[0], NULL, routine, (void*) &i);
        pthread_join(_threads[0], NULL);
        printf("Created thread number  == %d\n", i);
    }
}