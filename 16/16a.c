/*
============================================================================
Name : 16a.c
Author : Gutla Gayathri
Description : 16. Write a program to perform mandatory locking.
              a. Implement write lock
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE_PATH "testfile.txt"

// Function to acquire a write lock
void acquire_write_lock(int fd) {
    struct flock lock;
    lock.l_type = F_WRLCK;  // Set the type to write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // 0 means to the end of the file

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error acquiring write lock");
        exit(EXIT_FAILURE);
    }
    printf("Write lock acquired.\n");
}

// Function to release a write lock
void release_write_lock(int fd) {
    struct flock lock;
    lock.l_type = F_UNLCK;  // Unlock the file
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error releasing write lock");
        exit(EXIT_FAILURE);
    }
    printf("Write lock released.\n");
}



int main() {
    int fd;

    // Open the file
    fd = open(FILE_PATH, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Acquire and release a write lock
    acquire_write_lock(fd);
    sleep(5);  // Simulate work with the write lock
    release_write_lock(fd);

    // Close the file descriptor
    close(fd);

    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/16$ ./a.out 
Write lock acquired.
Write lock released.
*/
