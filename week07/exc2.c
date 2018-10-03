#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = calloc(n, sizeof(int));
    printf("%d", *arr);
    int j = n;
    while (*(arr+j) = --j);
    for (j = 1; j < n; j++) printf(" %d", *(arr+j));
    printf("\n");
    free(arr);
    return 0;
}
