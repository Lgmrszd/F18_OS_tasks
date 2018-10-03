#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void *my_realloc(void *ptr, size_t size) {
    if (ptr == NULL) return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    void *dest = malloc(size);
    memcpy(dest, ptr, size);
    free(ptr);
    return dest;
}

int main() {
    char *src = calloc(1, 15);
    strcpy(src, "Hello World!");
    printf("Src: %s\n", src);
    char *dest = my_realloc(src, 2);
    printf("Dst: %s\n", dest);
    return 0;
}
