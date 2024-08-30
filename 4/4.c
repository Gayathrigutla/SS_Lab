/*
============================================================================
Name : 4.c
Author : Gutla Gayathri
Description : 4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 30 Aug, 2024
============================================================================
*/

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
        int fd = open("example1.txt", O_RDWR);
        if(fd == -1){
                perror("Error opening file");
                return 1;
        }
        printf("File opened successfully with file descriptor: %d\n", fd);
        close(fd);

        // Attempt to open the file with O_CREAT | O_EXCL flags
        fd = open("example1.txt", O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
        if (fd == -1) {
                perror("Error opening file with O_EXCL flag");
        }
         else{
                printf("File created and opened successfully with O_EXCL flag, file descriptor: %d\n", fd);
                close(fd);
        }

        return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/4$ cc 4.c
gayathri@alahomora:~/Desktop/SS/4$ ./a.out
Error opening file: No such file or directory
gayathri@alahomora:~/Desktop/SS/4$ touch example1.txt
gayathri@alahomora:~/Desktop/SS/4$ ./a.out example1.txt 
File opened successfully with file descriptor: 3
Error opening file with O_EXCL flag: File exists
gayathri@alahomora:~/Desktop/SS/4$ 
*/
