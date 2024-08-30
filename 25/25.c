Name : 25.c
Author : Gutla Gayathri
Description : 25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pids[3];
    pid_t pid;
    int status;

    // Create three child processes
    for (int i = 0; i < 3; i++) {
        pid = fork();
        if (pid < 0) {
            perror("fork failed");
            return EXIT_FAILURE;
        } else if (pid == 0) {
            // Child process
            printf("Child %d (PID: %d) is running...\n", i + 1, getpid());
            sleep(2 * (i + 1)); // Sleep to simulate work
            printf("Child %d (PID: %d) is exiting...\n", i + 1, getpid());
            exit(i + 1); // Exit with a status code
        } else {
            // Parent process
            pids[i] = pid; // Store the child's PID
        }
    }

    // Parent process: wait for a specific child
    int child_to_wait_for = 2; // Specify which child to wait for (e.g., third child)
    pid_t child_pid = pids[child_to_wait_for - 1]; // Get the PID of the child to wait for

    printf("Parent (PID: %d) waiting for child %d (PID: %d)...\n", getpid(), child_to_wait_for, child_pid);

    if (waitpid(child_pid, &status, 0) > 0) {
        if (WIFEXITED(status)) {
            printf("Child %d (PID: %d) exited with status %d\n", child_to_wait_for, child_pid, WEXITSTATUS(status));
        } else {
            printf("Child %d (PID: %d) did not exit normally\n", child_to_wait_for, child_pid);
        }
    } else {
        perror("waitpid failed");
    }

    // Optionally, wait for the remaining children
    for (int i = 0; i < 3; i++) {
        if (pids[i] != child_pid) {
            waitpid(pids[i], NULL, 0);
        }
    }

    return EXIT_SUCCESS;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/25$ ./a.out
Parent (PID: 175602) waiting for child 2 (PID: 175604)...
Child 1 (PID: 175603) is running...
Child 2 (PID: 175604) is running...
Child 3 (PID: 175605) is running...
Child 1 (PID: 175603) is exiting...
Child 2 (PID: 175604) is exiting...
Child 2 (PID: 175604) exited with status 2
Child 3 (PID: 175605) is exiting...

*/
