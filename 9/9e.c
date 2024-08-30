/*
============================================================================
Name : 9e.c
Author : Gutla Gayathri
Description : Write a program to print the following information about a given file.
              e. size
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

    printf("Size: %ld bytes\n", (long)fileStat.st_size);

    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/9$ cc 9e.c
gayathri@alahomora:~/Desktop/SS/9$ ./a.out example.txt 
Size: 3 bytes
gayathri@alahomora:~/Desktop/SS/9$ cat example.txt 
Hi
*/

