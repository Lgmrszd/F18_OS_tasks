#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
// #include <types.h>

struct file_info {
    char name[255];
    int inode;
    int links;
};

int main() {
    DIR* tmpdir = opendir("tmp");
    if (tmpdir == NULL) {
        printf("tmp dir doesn't exists!\n");
        return 1;
    }
    struct dirent *dir_entry;
    int file_count = 0;
    while ((dir_entry = readdir(tmpdir)) != NULL) {
        if (dir_entry->d_type == DT_REG) {
            file_count++;
        }
    }
    closedir(tmpdir);

    tmpdir = opendir("tmp");
    struct file_info *files = malloc(sizeof(struct file_info)*file_count);
    for (int i=0; i<file_count;) {
        dir_entry = readdir(tmpdir);
        if (dir_entry->d_type == DT_REG) {
            files[i].inode = dir_entry->d_ino;
            files[i].links = -1;
            strcpy(files[i].name, dir_entry->d_name);
            for (int j=0; j<=i; j++) {
                if (files[j].inode == files[i].inode) {
                    files[j].links++;
                    files[i].links++;
                }
            }
            i++;
        }
    }
    for (int j=0; j<file_count; j++) {
        //printf("%s %d\n", files[j].name, files[j].links);
        if (files[j].links>1) {
            printf("File \"%s\" (inode %d) have filenames:", files[j].name, files[j].inode);
            for (int i=0; i<file_count; i++) {
                if (i != j && files[i].inode == files[j].inode) {
                    printf(" %s", files[i].name);
                    files[i].links = 0; // do not repeat output
                }           
            }
            files[j].links=0; // do not repeat output
            printf("\n");
        }
    }
    closedir(tmpdir);
}
