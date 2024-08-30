Name : 24.c
Author : Gutla Gayathri
Description : Write a program to create an orphan process.
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Fork a new process
    pid = fork();
    
    if (pid < 0) {
        perror("fork failed");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) running...\n", getpid());
        
        // Sleep for a while to allow the parent process to terminate
        sleep(10);
        
        printf("Child process (PID: %d) is now an orphan.\n", getpid());
        exit(0);
    } else {
        // Parent process
        printf("Parent process (PID: %d) will terminate...\n", getpid());
        
        // Exit the parent process immediately
        exit(0);
    }

    return EXIT_SUCCESS;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/24$ ./a.out
Parent process (PID: 175505) will terminate...
Child process (PID: 175506) running...
Child process (PID: 175506) is now an orphan.

*/
