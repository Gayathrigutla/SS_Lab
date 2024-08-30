/*
============================================================================
Name : 9b.c
Author : Gutla Gayathri
Description : Write a program to print the following information about a given file.
              b. number of hard links 
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

    printf("Number of hard links: %ld\n", (long)fileStat.st_nlink);
  
    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/9$ ./a.out example.txt 
Number of hard links: 1
*/
