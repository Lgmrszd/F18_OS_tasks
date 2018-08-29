#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 256



int main() {
    char* src = (char*) malloc(sizeof(char) * (maxsize+1));
    char* dst = (char*) malloc(sizeof(char) * (maxsize+1));
    int str_len;
    fgets(src, maxsize, stdin);
    str_len = (int) strlen(src)-1;
    *(src+str_len) = 0;
    *(dst+str_len) = 0;
    dst = dst + str_len;
    while (*--dst = *src++);
    dst++;
    printf("%s\n", dst);
    return 0;
}
