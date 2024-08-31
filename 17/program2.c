/*
============================================================================
Name : 17.c
Author : Gutla Gayathri
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit.
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define FILE_PATH "ticket_file.txt"

// Function to acquire a write lock
void acquire_write_lock(int fd) {
    struct flock lock;
    lock.l_type = F_WRLCK;  // Set the type to write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // 0 means to the end of the file

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error acquiring write lock");
        exit(EXIT_FAILURE);
    }
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
}

int main() {
    int fd;
    char buffer[10];
    ssize_t bytes_read;
    int ticket_number;

    // Open the file for reading and writing
    fd = open(FILE_PATH, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Acquire write lock
    acquire_write_lock(fd);

    // Read the current ticket number
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("Error reading from file");
        release_write_lock(fd);
        close(fd);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read] = '\0';  // Null-terminate the string
    ticket_number = atoi(buffer);  // Convert to integer

    // Increment the ticket number
    ticket_number++;

    // Move the file offset to the beginning for writing
    lseek(fd, 0, SEEK_SET);

    // Write the new ticket number to the file
    snprintf(buffer, sizeof(buffer), "%d\n", ticket_number);
    if (write(fd, buffer, sizeof(buffer)) == -1) {
        perror("Error writing to file");
        release_write_lock(fd);
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Updated ticket number to %d\n", ticket_number);

    // Release write lock and close the file
    release_write_lock(fd);
    close(fd);

    return 0;
}
