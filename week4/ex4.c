#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

#define maxsize 200

int status = 0;

//typedef struct {
//    pid_t pid;
//    int in_background;
//} job;
//
//job *jobs;

pid_t bg_job;

void print_prompt() {
    printf("=[%d]=\n==> ", status);
}


void wait_bg() {
    if (bg_job == 0) {
        printf("no bg job running\n");
    } else {
        printf("Resuming job with pid %d\n", bg_job);
        bg_job = 0;
        waitpid(bg_job, &status, WUNTRACED);
    }
}


int runcmd(char **args, int argc) {
    pid_t pid = fork();
    int should_bg = (*args[argc-1] == '&');
    if (should_bg) {
        args[argc-1] = NULL;
    }
    if (pid == 0) {
        int run_status = execvp(args[0], args);
        if (run_status == -1) {
            printf("%s: command not found\n", args[0]);
            exit(1);
        }
    } else if (pid < 0) {

    } else {
        if (should_bg && bg_job) {
            should_bg = 0;
            printf("Sorry, only 1 background job supported\n");
        }
        if (should_bg) {
            printf("Running %d in background, use \"fg\" to return and wait for it\n");
            bg_job = pid;
        } else {
            waitpid(pid, &status, WUNTRACED);
        }
    }
}

int run(char **args, int argc, int *control) {
    if (argc == 0) {
        return 0;
    }
    if (strcmp(args[0], "exit") == 0) {
        *control = 0;
    } else if (strcmp(args[0], "fg") == 0) {
        wait_bg();
    } else {
        return runcmd(args, argc);
    }
    return 0;
}

char **split(char *input, char sep, int *count) {
    *count = 0;
    int i;
    int is_word = 0;
    for (i = 0; i < strlen(input); i++) {
        if (is_word) {
            if ( *(input+i) == sep) {
                is_word = 0;
                (*count)++;
            }
        } else {
            if ( *(input+i) != sep) {
                is_word = 1;
            }
        }
    }
    if (is_word && (strlen(input) != 0)) (*count)++;
    char **words = malloc(sizeof(char *) * (*count+1));

    int wordsize = 0;
    int wordstart = 0;
    is_word = 0;
    *count = 0;
    for (i = 0; i < strlen(input); i++) {
        if (is_word) {
            if ( *(input+i) == sep) {
                is_word = 0;
                (*count)++;
                wordsize = i- wordstart;
                char *word = malloc(sizeof(char) * (wordsize+1));
                strncpy(word, input+wordstart, (size_t) wordsize);
                *(words + *count-1) = word;
            }
        } else {
            if ( *(input+i) != sep) {
                is_word = 1;
                wordstart = i;
            }
        }
    }
    if (is_word && (strlen(input) != 0)) {
        (*count)++;
        wordsize = i- wordstart;
        char *word = malloc(sizeof(char) * (wordsize+1));
        strncpy(word, input+wordstart, (size_t) wordsize);
        *(words + *count-1) = word;
    }
    *(words + *count) = NULL;
    return words;
}

int main() {
    bg_job = 0;
    char *inp = malloc(sizeof(char)*(maxsize+1));
    char **myargs;
    int myargc = 0;
    int work = 1;
    while (work) {
        print_prompt();
        fgets(inp, maxsize, stdin);
        inp[strlen(inp)-1] = 0;
        myargs = split(inp, ' ', &myargc);
        run(myargs, myargc, &work);
    }
    return 0;
}
