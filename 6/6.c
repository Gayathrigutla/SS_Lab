/*
============================================================================
Name : 6.c
Author : Gutla Gayathri
Description : 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 30 Aug, 2024
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	char buffer[32];
	int size_read = read(0, buffer, sizeof(buffer));
	printf("%d\n", size_read);
	fflush(stdout);
	write(1, buffer, sizeof(buffer));
	return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/6$ ./a.out
Hi There
9
Hi There
*/
