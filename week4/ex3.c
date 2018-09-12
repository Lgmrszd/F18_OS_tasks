#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define prompt "==> "
#define maxsize 200

int print_prompt() {
    printf(prompt);
}

int main() {
    char *inp = malloc(sizeof(char)*(maxsize+1));
    int work = 1;
    while (work) {
        print_prompt();
        fgets(inp, maxsize, stdin);
        inp[strlen(inp)-1] = 0;
        if (strcmp(inp, "exit") == 0) {
            work = 0;
        } else {
            system(inp);
            //printf("|%s|\n", inp);
        }
    }
    return 0;
}
