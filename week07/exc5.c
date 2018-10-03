#include <stdio.h>
#include <stdlib.h>
int main() {
    char **s;
    char foo[] = "Hello World";
    /* You cannot assign (char*) to '*s' since 's' is undefined and points to nowhere
     * You need to allocate memory for 's' first
     */
    s = malloc(sizeof(char*));
    *s = foo;
    printf("*s is %s\n", *s); // 's' is char** (points to pointer to first char of string), '*s' is "string"
    s[0] = foo;
    printf("s[0] is %s\n",s[0]);
    return(0);
}
