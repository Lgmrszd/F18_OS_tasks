#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main() {
    int fd_in, fd_out;
    void *fm_in, *fm_out;
    size_t f_in_size;
    struct stat stat_in;
    
    fd_in = open("ex1.txt", O_RDONLY);
    fstat(fd_in, &stat_in);
    f_in_size = stat_in.st_size;
    fm_in = mmap(NULL, f_in_size, PROT_READ, MAP_SHARED, fd_in, 0);

    fd_out = open("ex1.memcpy.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    lseek(fd_out, f_in_size, SEEK_SET);
    write(fd_out, "", 1);
    fm_out = mmap(NULL, f_in_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd_out, 0);
    memcpy(fm_out, fm_in, f_in_size);
    return 0;
}
