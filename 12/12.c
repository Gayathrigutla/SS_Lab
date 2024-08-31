============================================================================
/*
Name : 12.c
Author : Gutla Gayathri
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd;
    int flags;
    char *file_path;
    int open_flags = 0;

    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file_path> <open_mode>\n", argv[0]);
        fprintf(stderr, "Open modes: r (read), w (write), rw (read/write), a (append), x (exclusive), nb (non-blocking)\n");
        exit(EXIT_FAILURE);
    }

    file_path = argv[1];
    char *mode = argv[2];

    // Determine open flags based on the mode
    if (strcmp(mode, "r") == 0) {
        open_flags = O_RDONLY;
    } else if (strcmp(mode, "w") == 0) {
        open_flags = O_WRONLY | O_CREAT | O_TRUNC;
    } else if (strcmp(mode, "rw") == 0) {
        open_flags = O_RDWR | O_CREAT;
    } else if (strcmp(mode, "a") == 0) {
        open_flags = O_WRONLY | O_CREAT | O_APPEND;
    } else if (strcmp(mode, "x") == 0) {
        open_flags = O_CREAT | O_EXCL;
    } else if (strcmp(mode, "nb") == 0) {
        open_flags = O_RDONLY | O_NONBLOCK;
    } else {
        fprintf(stderr, "Invalid open mode: %s\n", mode);
        fprintf(stderr, "Open modes: r (read), w (write), rw (read/write), a (append), x (exclusive), nb (non-blocking)\n");
        exit(EXIT_FAILURE);
    }

    // Open the file
    fd = open(file_path, open_flags, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Get file status flags using fcntl
    flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("Error getting file status flags");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Print the file opening mode
    printf("File opening mode:\n");
    if (flags & O_RDONLY) {
        printf("O_RDONLY: Read-only\n");
    }
    if (flags & O_WRONLY) {
        printf("O_WRONLY: Write-only\n");
    }
    if (flags & O_RDWR) {
        printf("O_RDWR: Read and write\n");
    }
    if (flags & O_APPEND) {
        printf("O_APPEND: Append mode\n");
    }
    if (flags & O_CREAT) {
        printf("O_CREAT: Create file if it does not exist\n");
    }
    if (flags & O_TRUNC) {
        printf("O_TRUNC: Truncate file to zero length\n");
    }
    if (flags & O_EXCL) {
        printf("O_EXCL: Exclusive use\n");
    }
    if (flags & O_NONBLOCK) {
        printf("O_NONBLOCK: Non-blocking mode\n");
    }

    // Close the file descriptor
    close(fd);

    return 0;
}

/*
Output: 

gayathri@alahomora:~/Desktop/SS/12$ cc 12.c
gayathri@alahomora:~/Desktop/SS/12$ ./a.out examplefile.txt a
File opening mode:
O_WRONLY: Write-only
O_APPEND: Append mode
gayathri@alahomora:~/Desktop/SS/12$ ./a.out examplefile.txt w
File opening mode:
O_WRONLY: Write-only
*/

