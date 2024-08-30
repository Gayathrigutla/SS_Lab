/*
============================================================================
Name : 9c.c
Author : Gutla Gayathri
Description : Write a program to print the following information about a given file.
              c. uid
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

    printf("UID: %d\n", fileStat.st_uid);
  
    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/9$ cc 9c.c
gayathri@alahomora:~/Desktop/SS/9$ ./a.out example.txt 
UID: 1000
*/
