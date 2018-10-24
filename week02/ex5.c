#include <stdio.h>
#include <string.h>
#define bg " "
#define fg "*"


void bottom_triangle(int n) {
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


void top_triangle(int n) {
    for (int i=n; i>=1; i--) {
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

void left_triangle(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            printf(fg);
        }
        for (int j=1; j<=(n-i); j++) {
            printf(bg);
        }
        printf("\n");
    }
    for (int i=n-1; i>=1; i--) {
        for (int j=1; j<=i; j++) {
            printf(fg);
        }
        for (int j=1; j<=(n-i); j++) {
            printf(bg);
        }
        printf("\n");
    }
}

void right_triangle(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=(n-i); j++) {
            printf(bg);
        }
        for (int j=1; j<=i; j++) {
            printf(fg);
        }
        printf("\n");
    }
    for (int i=n-1; i>=1; i--) {
        for (int j=1; j<=(n-i); j++) {
            printf(bg);
        }
        for (int j=1; j<=i; j++) {
            printf(fg);
        }
        printf("\n");
    }
}

void cross(int n) {
    for (int i=n; i>=2; i--) {
        for (int j=1; j<=(n-i); j++) {
            printf(bg);
        }
        printf(fg);
        for (int j=1; j<=2*i-3; j++) {
            printf(bg);
        }
        printf(fg);
        for (int j=1; j<=(n-i); j++) {
            printf(bg);
        }
        printf("\n");
    }
    if (n != 0) {
        for (int j=1; j<=n-1; j++) {
            printf(bg);
        }
        printf(fg);
        for (int j=1; j<=n-1; j++) {
            printf(bg);
        }
        printf("\n");
    }
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=(n-i); j++) {
            printf(bg);
        }
        printf(fg);
        for (int j=1; j<=2*i-3; j++) {
            printf(bg);
        }
        printf(fg);
        for (int j=1; j<=(n-i); j++) {
            printf(bg);
        }
        printf("\n");
    }
}

void usage(char *name) {
    printf("usage: \t%s N [PATTERN]\n\t%s -p\nPrints PATTERN (default is 1) with N parameter\n\t-p\tShow patterns list\nAnything else will print this message\n", name, name);
    return;
}


int main(int argc, char *argv[]) {
    void patterns() {
        printf("1: bottom triangle (height N)\n");
        printf(" * \n");
        printf("***\n");
        printf("2: top triangle (height N)\n");
        printf("***\n");
        printf(" * \n");
        printf("3: left triangle (width N)\n");
        printf("* \n");
        printf("**\n");
        printf("* \n");
        printf("4: right triangle (width N)\n");
        printf(" *\n");
        printf("**\n");
        printf(" *\n");
        printf("5: cross (width & height 2N-1)\n");
        printf("* *\n");
        printf(" * \n");
        printf("* *\n");
        return;
    }
    if (argc == 2) {
        int n;
        if (!strcmp(argv[1], "-p")) patterns();
        else {
            int res = sscanf(argv[1], "%d", &n);
            if (res == 0) usage(argv[0]);
            else bottom_triangle(n);
        }
    } else if (argc == 3) {
        int n;
        int p;
        int res = sscanf(argv[1], "%d", &n) && sscanf(argv[2], "%d", &p);
        if (res == 0) usage(argv[0]);
        else {
            switch (p) {
            case 1: bottom_triangle(n);
            break;
            case 2: top_triangle(n);
            break;
            case 3: left_triangle(n);
            break;
            case 4: right_triangle(n);
            break;
            case 5: cross(n);
            break;
            default: printf("Error: %d is not a valid pattern.\nUse \"%s -p\" for list of valid patterns\n", p, argv[0]);
            }
        }
    } else usage(argv[0]);
    return 0;
}
