#include <unistd.h>
#include <stdlib.h>

int main() {
    const int size = 10*1024*1024;
    for (int i = 0; i < 10; i++) {
        unsigned char *dat = malloc(size);
        for (int j = 0; j < size; j++) {
            *(dat+j) = 0;
        }
        sleep(1);
    }
    return 0;
}
