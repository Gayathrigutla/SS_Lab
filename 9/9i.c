/*
============================================================================
Name : 9i.c
Author : Gutla Gayathri
Description : Write a program to print the following information about a given file.
              i. time of last modification
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

    printf("Time of last modification: %s", ctime(&fileStat.st_mtime));

    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/9$ cc 9i.c
gayathri@alahomora:~/Desktop/SS/9$ ./a.out example.txt 
Time of last modification: Fri Aug 30 17:09:24 2024
*/
