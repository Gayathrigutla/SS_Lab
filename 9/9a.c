/*
============================================================================
Name : 9a.c
Author : Gutla Gayathri
Description : Write a program to print the following information about a given file.
              a. inode
Date: 30 Aug, 2024
============================================================================
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    struct stat fileStat;
    if (stat(argv[1], &fileStat) < 0) {
        return 1;
    }

    printf("Inode: %ld\n", (long)fileStat.st_ino);

    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/9$ cc 9a.c
gayathri@alahomora:~/Desktop/SS/9$ ./a.out example.txt 
Inode: 4854764
*/
