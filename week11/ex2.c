#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    setvbuf(stdout, NULL, _IOLBF, 0);
    char *str_data = "Hello\n";
    int n = strlen(str_data);
    printf("%c", *str_data);
    for (int i=1; i<n; i++) {
        sleep(1);
        printf("%c", str_data[i]);
    }
    return 0;
}
