/*
============================================================================
Name : 3.c
Author : Gutla Gayathri
Description : 3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 30 Aug, 2024
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int fd = creat("example1.txt", S_IRWXU | S_IRGRP | S_IROTH);
	int fd2 = creat("example2.txt", S_IRWXU | S_IRGRP | S_IROTH);
	if(fd == -1){
		printf("Error in creating example1");
		return 1;
	}
	if(fd2 == -1){
		printf("Error in creating example2");
		return 1;
	}
	printf("file descriptor val for example1: %d\n", fd);
	printf("file descriptor val for example2: %d\n", fd2);
	close(fd);
	close(fd2);
	return 0;
}


/*
Output:

gayathri@alahomora:~/Desktop/SS/3$ cc 3.c
gayathri@alahomora:~/Desktop/SS/3$ ./a.out
file descriptor val for example1: 3
file descriptor val for example2: 4
gayathri@alahomora:~/Desktop/SS/3$ 

*/
