#include <stdio.h>
#include <pthread.h>
#define N 10


pthread_t _threads[N];

void *routine(void *arg) {
        printf("Text in thread number  >> %d !!!\n", *((int *) arg));
    pthread_exit(NULL);
}


int main() {
    for (int i = 0; i < N; i++) {
        printf("Creating thread number ++ %d\n", i);
        pthread_create(&_threads[i], NULL, routine, (void*) &i);
        printf("Created thread number  == %d\n", i);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(_threads[i], NULL);
    }
}
