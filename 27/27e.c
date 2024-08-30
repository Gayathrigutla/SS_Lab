/*
Name : 27e.c
Author : Gutla Gayathri
Description : 27. Write a program to execute ls -Rl by the following system calls
             
              e. execvp
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  

    // Using execvp
    printf("Using execvp:\n");
    char *args_p[] = {"ls", "-Rl", NULL};
    execvp("ls", args_p);
    perror("execvp failed"); // If execvp returns, it must have failed

    return EXIT_SUCCESS;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/27$ ./a.out
Using execvp:
.:
total 40
-rw-rw-r-- 1 gayathri gayathri  1027 Aug 31 00:42 27a.c
-rw-rw-r-- 1 gayathri gayathri   985 Aug 31 00:43 27b.c
-rw-rw-r-- 1 gayathri gayathri  1325 Aug 31 00:42 27.c
-rw-rw-r-- 1 gayathri gayathri  1005 Aug 31 00:43 27c.c
-rw-rw-r-- 1 gayathri gayathri  1047 Aug 31 00:43 27d.c
-rw-rw-r-- 1 gayathri gayathri   572 Aug 31 00:42 27e.c
-rwxrwxr-x 1 gayathri gayathri 16096 Aug 31 00:44 a.out

*/
