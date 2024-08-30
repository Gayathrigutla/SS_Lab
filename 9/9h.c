/*
============================================================================
Name : 9h.c
Author : Gutla Gayathri
Description : Write a program to print the following information about a given file.
              h. time of last access
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

    printf("Time of last access: %s", ctime(&fileStat.st_atime));

    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/9$ cc 9h.c
gayathri@alahomora:~/Desktop/SS/9$ ./a.out example.txt 
Time of last access: Fri Aug 30 17:09:28 2024
*/
