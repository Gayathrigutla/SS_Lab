/*
============================================================================
Name : 17.c
Author : Gutla Gayathri
Description : Write a program to simulate online ticket reservation. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE_PATH "ticket_file.txt"
#define INITIAL_TICKET_NUMBER 1000

int main() {
    int fd;
    char buffer[10];
    ssize_t bytes_written;

    // Open the file for writing; create if it doesn't exist
    fd = open(FILE_PATH, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write the initial ticket number to the file
    snprintf(buffer, sizeof(buffer), "%d\n", INITIAL_TICKET_NUMBER);
    bytes_written = write(fd, buffer, sizeof(buffer));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Initialized ticket number %d\n", INITIAL_TICKET_NUMBER);

    // Close the file
    close(fd);

    return 0;
}
