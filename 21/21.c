/*
============================================================================
Name : 21.c
Author : Gutla Gayathri
Description : Write a program, call fork and print the parent and child process id.
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Fork the process
    pid = fork();

    if (pid < 0) {
        // Error occurred
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process ID: %d\n", getpid());
        printf("Parent Process ID in Child: %d\n", getppid());
    } else {
        // Parent process
        printf("Parent Process ID: %d\n", getpid());
        printf("Child Process ID in Parent: %d\n", pid);
    }

    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/21$ cc 21.c
gayathri@alahomora:~/Desktop/SS/21$ ./a.out
Parent Process ID: 175064
Child Process ID in Parent: 175065
Child Process ID: 175065
Parent Process ID in Child: 1437
*/
