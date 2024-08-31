/*
Name : 26a.c
Author : Gutla Gayathri
Description : Write a program to execute an executable program.
a. use some executable program
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No name provided!\n");
        return 1;
    }
    printf("Hello, %s!\n", argv[1]);
    return 0;
}
