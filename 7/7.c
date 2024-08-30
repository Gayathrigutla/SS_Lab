/*
============================================================================
Name : 7.c
Author : Gutla Gayathri
Description : 7. Write a program to copy file1 into file2 ($cp file1 file2).
Date: 30 Aug, 2024
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Enter the file names:\n");
        return 1;
    }

    int source = open(argv[1], O_RDONLY);
    if (source < 0) {
        return 1;
    }

    int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        close(source);
        return 1;
    }

    char buffer[4096];
    ssize_t bytes;
    while ((bytes = read(source, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }

    close(source);
    close(dest);
    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/7$ ./a.out file1.txt file2.txt
gayathri@alahomora:~/Desktop/SS/7$ cat file1.txt 
Hi
gayathri@alahomora:~/Desktop/SS/7$ cat file2.txt 
Hi
*/
