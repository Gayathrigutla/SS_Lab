/*
============================================================================
Name : 8.c
Author : Gutla Gayathri
Description : 8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 30 Aug, 2024
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        return 1;
    }

    char buffer;
    ssize_t bytes_read;
    while ((bytes_read = read(fd, &buffer, 1)) > 0) {
        write(1, &buffer, 1);
        if (buffer == '\n') {} //to move to next line
    }

    close(fd);
    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/8$ cc 8.c
gayathri@alahomora:~/Desktop/SS/8$ ./a.out ex1.txt 
line 1
line 2
line 3

*/
