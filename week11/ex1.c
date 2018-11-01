#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
//#include <sys/stat.h>

int main() {
    char *str_data = "This is a nice day\n";
    int str_size = strlen(str_data);
    int fd;
    void *fm;
    fd = open("ex1.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    lseek(fd, str_size, SEEK_SET);
    write(fd, "", 1);
    fm = mmap(NULL, str_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    memcpy(fm, str_data, str_size);
    return 0;
}
