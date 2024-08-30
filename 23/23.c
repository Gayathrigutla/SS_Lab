/*
============================================================================
Name : 23.c
Author : Gutla Gayathri
Description : Write a program to create a Zombie state of the running program.
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
        printf("Child process (PID: %d) exiting...\n", getpid());
        // Exit immediately, child process will become a zombie
        exit(0);
    } else {
        // Parent process
        printf("Parent process (PID: %d) sleeping to create a zombie...\n", getpid());
        // Sleep to allow the child to exit and become a zombie
        sleep(10); // Adjust the sleep time as needed
        
        // Optional: Wait for the child to exit and clean up
        // This will remove the zombie status
        wait(NULL);
        
        printf("Parent process (PID: %d) cleaned up child process.\n", getpid());
    }

    return EXIT_SUCCESS;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/23$ ./a.out
Parent process (PID: 175341) sleeping to create a zombie...
Child process (PID: 175342) exiting...
Parent process (PID: 175341) cleaned up child process.

*/
