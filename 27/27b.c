/*
Name : 27b.c
Author : Gutla Gayathri
Description : 27. Write a program to execute ls -Rl by the following system calls
              b. execlp
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    // Using execlp
    printf("Using execlp:\n");
    execlp("ls", "ls", "-Rl", NULL);
    perror("execlp failed"); // If execlp returns, it must have failed

    return EXIT_SUCCESS;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/27$ ./a.out
Using execlp:
.:
total 40
-rw-rw-r-- 1 gayathri gayathri  1027 Aug 31 00:42 27a.c
-rw-rw-r-- 1 gayathri gayathri   524 Aug 31 00:41 27b.c
-rw-rw-r-- 1 gayathri gayathri  1325 Aug 31 00:42 27.c
-rw-rw-r-- 1 gayathri gayathri   544 Aug 31 00:42 27c.c
-rw-rw-r-- 1 gayathri gayathri   587 Aug 31 00:42 27d.c
-rw-rw-r-- 1 gayathri gayathri   572 Aug 31 00:42 27e.c
-rwxrwxr-x 1 gayathri gayathri 16048 Aug 31 00:42 a.out

*/
