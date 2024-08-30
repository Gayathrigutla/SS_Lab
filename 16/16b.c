/*
============================================================================
Name : 16b.c
Author : Gutla Gayathri
Description : 16. Write a program to perform mandatory locking.
              b. Implement write lock
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



// Function to acquire a read lock
void acquire_read_lock(int fd) {
    struct flock lock;
    lock.l_type = F_RDLCK;  // Set the type to read lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // 0 means to the end of the file

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error acquiring read lock");
        exit(EXIT_FAILURE);
    }
    printf("Read lock acquired.\n");
}

// Function to release a read lock
void release_read_lock(int fd) {
    struct flock lock;
    lock.l_type = F_UNLCK;  // Unlock the file
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error releasing read lock");
        exit(EXIT_FAILURE);
    }
    printf("Read lock released.\n");
}

int main() {
    int fd;

    // Open the file
    fd = open(FILE_PATH, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

   
    // Acquire and release a read lock
    acquire_read_lock(fd);
    sleep(5);  // Simulate work with the read lock
    release_read_lock(fd);

    // Close the file descriptor
    close(fd);

    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/16$ cc 16b.c
gayathri@alahomora:~/Desktop/SS/16$ ./a.out 
Read lock acquired.
Read lock released.

*/
