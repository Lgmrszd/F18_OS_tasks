#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *foo(void *i) {
        int a = *((int *) i);
        printf("%d\n", a);
            free(i);
}

int main() {
        pthread_t thread;
            for ( int i = 0; i < 10; ++i ) {
                        int *arg = malloc(sizeof(*arg));
                                if ( arg == NULL ) {
                                                fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
                                                            exit(EXIT_FAILURE);
                                                                    }

                                        *arg = i;
                                                pthread_create(&thread, 0, foo, arg);
                                                    }

                /*  Wait for threads, etc  */

                return 0;
}
