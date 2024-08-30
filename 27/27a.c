/*
Name : 27a.c
Author : Gutla Gayathri
Description : 27. Write a program to execute ls -Rl by the following system calls
              a. execl
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Using execl
    printf("Using execl:\n");
    execl("/bin/ls", "ls", "-Rl", NULL);
    perror("execl failed"); // If execl returns, it must have failed

    return EXIT_SUCCESS;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/27$ cc 27a.c
gayathri@alahomora:~/Desktop/SS/27$ ./a.out
Using execl:
.:
total 40
-rw-rw-r-- 1 gayathri gayathri   522 Aug 31 00:41 27a.c
-rw-rw-r-- 1 gayathri gayathri   524 Aug 31 00:41 27b.c
-rw-rw-r-- 1 gayathri gayathri  1325 Aug 31 00:38 27.c
-rw-rw-r-- 1 gayathri gayathri   544 Aug 31 00:42 27c.c
-rw-rw-r-- 1 gayathri gayathri   587 Aug 31 00:42 27d.c
-rw-rw-r-- 1 gayathri gayathri   572 Aug 31 00:42 27e.c
-rwxrwxr-x 1 gayathri gayathri 16040 Aug 31 00:42 a.out

*/
