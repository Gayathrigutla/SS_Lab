/*
============================================================================
Name : 11b.c
Author : Gutla Gayathri
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
            a. use dup2
Date: 30 Aug, 2024
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd, fd_dup1, fd_dup2;
    const char *message1 = "Data written using original descriptor.\n";
    const char *message2 = "Data written using duplicated descriptor.\n";
    
    // Open the file
    fd = open("example.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Duplicate the file descriptor using dup
    fd_dup1 = dup(fd);
    if (fd_dup1 == -1) {
        perror("Error duplicating file descriptor using dup");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Duplicate the file descriptor using dup2
    fd_dup2 = dup2(fd, fd_dup1 + 1);
    if (fd_dup2 == -1) {
        perror("Error duplicating file descriptor using dup2");
        close(fd);
        close(fd_dup1);
        exit(EXIT_FAILURE);
    }


    // Append data using the original file descriptor
    if (write(fd, message1, strlen(message1)) != strlen(message1)) {
        perror("Error writing data using original descriptor");
        close(fd);
        close(fd_dup1);
        close(fd_dup2);
        exit(EXIT_FAILURE);
    }


    // Append data using the second duplicated file descriptor
    if (write(fd_dup2, message2, strlen(message2)) != strlen(message2)) {
        perror("Error writing data using duplicated descriptor 2");
        close(fd);
        close(fd_dup1);
        close(fd_dup2);
        exit(EXIT_FAILURE);
    }


    // Close all file descriptors
    close(fd);
    close(fd_dup1);
    close(fd_dup2);

    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/11$ cc 11b.c
gayathri@alahomora:~/Desktop/SS/11$ rm example.txt 
gayathri@alahomora:~/Desktop/SS/11$ touch example.txt
gayathri@alahomora:~/Desktop/SS/11$ ./a.out example.txt
gayathri@alahomora:~/Desktop/SS/11$ cat example.txt 
Data written using original descriptor.
Data written using duplicated descriptor.
*/

