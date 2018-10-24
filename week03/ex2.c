#include <stdio.h>
#include <stdlib.h>

void swap_nums(int* x, int* y) {
    *x=*x^*y;
    *y=*x^*y;
    *x=*x^*y;
}

void bubble_sort(int *arr, int size){
    for (int i = size-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
           if (arr[j] > arr[j+1]) {
               swap_nums(&arr[j], &arr[j+1]);
           }
        }
    }
}

void print_array(int *arr, int size){
    if (size>=1) printf("%d", arr[0]);
    for (int i=1; i<size; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main(){
    int *arr;
    int size;
    printf("Enter arr size: ");
    scanf("%d", &size);
    arr = malloc(sizeof(int) * size);
    printf("Enter %d elements: ", size);
    for (int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    print_array(arr, size);
    bubble_sort(arr, size);
    print_array(arr, size);
    return 0;
}

