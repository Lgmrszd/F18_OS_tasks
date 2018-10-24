#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap_nums(int* x, int* y) {
    *x=*x^*y;
    *y=*x^*y;
    *x=*x^*y;
}


int main(int argc, char *argv[]) {
    int x;
    int y;
    scanf("%d", &x);
    scanf("%d", &y);
    swap_nums(&x, &y);
    printf("%d %d\n", x, y);
    return 0;
}
