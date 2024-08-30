/*
============================================================================
Name : 22.c
Author : Gutla Gayathri
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 30 Aug, 2024
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    pid_t pid;

    // Open a file for writing (create if it does not exist, truncate if it does)
    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Fork the process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        close(fd);
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        // Child process
        // Write to the file
        const char *child_msg = "Hello from child process!\n";
        if (write(fd, child_msg, sizeof(child_msg) - 1) < 0) {
            perror("write (child)");
            close(fd);
            return EXIT_FAILURE;
        }
        printf("Child wrote to file.\n");
    } else {
        // Parent process
        // Ensure the parent waits for a while before writing to avoid race condition
        sleep(1); // Optional: wait to ensure the child writes first

        // Write to the file
        const char *parent_msg = "Hello from parent process!\n";
        if (write(fd, parent_msg, sizeof(parent_msg) - 1) < 0) {
            perror("write (parent)");
            close(fd);
            return EXIT_FAILURE;
        }
        printf("Parent wrote to file.\n");

        // Wait for the child process to finish
        wait(NULL);
    }

    // Close the file descriptor
    close(fd);
    return EXIT_SUCCESS;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/22$ ./a.out
Child wrote to file.
Parent wrote to file.
gayathri@alahomora:~/Desktop/SS/22$ l
22.c  a.out*  output.txt
gayathri@alahomora:~/Desktop/SS/22$ cat output.txt 
Hello fHello f
*/
