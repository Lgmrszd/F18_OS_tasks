#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define N 40000
#define MAX 15
#define buff_size 8


pthread_t prod_t;
pthread_t cons_t;

int buffer[buff_size];
int start=0;
int count=0;

void *prod_r(void *arg) {
    int i;
    int prod_c = 0;
    while (prod_c < N) {
        if (count < buff_size) {
            i = rand() & MAX;
            buffer[(start + count) % buff_size] = i;
            count++;
            printf("sended %d\n", i);
            prod_c++;
//            usleep(1000000);
        }
    }
    pthread_exit(NULL);
}

void *cons_r(void *arg) {
    int i;
    int cons_c = 0;
    usleep(500000);
    while (cons_c < N) {
        if (count > 0) {
            i = buffer[start];
            start++;
            start = start % buff_size;
            count--;
            printf("received %d\n", i);
            cons_c++;
//            usleep(1000000);
        }
    }
    pthread_exit(NULL);
}


int main() {
    srand(time(NULL));
    pthread_create(&prod_t, NULL, prod_r, NULL);
    pthread_create(&cons_t, NULL, cons_r, NULL);
    pthread_join(prod_t, NULL);
    pthread_join(cons_t, NULL);
}
