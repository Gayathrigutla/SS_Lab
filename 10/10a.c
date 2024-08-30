/*
============================================================================
Name : 10a.c
Author : Gutla Gayathri
Description : 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
            a. check the return value of lseek
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    ssize_t result;
    off_t final_position;
    const char *data1 = "ABCDEFGHIJ";
    const char *data2 = "1234567890";

    // Open the file with read-write mode
    fd = open("examplefile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write 10 bytes
    if (write(fd, data1, 10) != 10) {
        perror("Error writing first 10 bytes");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Move file pointer by 10 bytes
    result = lseek(fd, 10, SEEK_CUR);
    if (result == -1) {
        perror("Error seeking in file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Write another 10 bytes
    if (write(fd, data2, 10) != 10) {
        perror("Error writing second 10 bytes");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Get the final file pointer position
    final_position = lseek(fd, 0, SEEK_CUR);
    if (final_position == -1) {
        perror("Error getting final file position");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Print the final file pointer position
    printf("Final file pointer position: %ld\n", (long)final_position);

    // Close the file
    close(fd);

    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/10$ ls
10.c
gayathri@alahomora:~/Desktop/SS/10$ cc 10.c
gayathri@alahomora:~/Desktop/SS/10$ ./a.out
Final file pointer position: 30

*/
