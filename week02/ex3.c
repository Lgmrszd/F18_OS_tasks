#include <stdio.h>
#define bg " "
#define fg "*"


void rsu_triangle(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=(n-i); j++) {
            printf(bg);
        }
        for (int j=1; j<=2*i-1; j++) {
            printf(fg);
        }
        for (int j=1; j<=(n-i); j++) {
            printf(bg);
        }
        printf("\n");
    }
}


void usage(char* name)
{
    printf("Usage: %s N\nPrints triangle of N height\n", name);
    return;
}

int main(int argc, char *argv[]) {
    int n;
    if (argc == 2) {
        int res = sscanf(argv[1], "%d", &n);
        if (res == 0) usage(argv[0]);
        else rsu_triangle(n);
    } else usage(argv[0]);
    return 0;
}
