#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	mknod("pipe1", S_IFIFO | 0666, 0);
	mknod("pipe2", S_IFIFO | 0666, 0);
	char buffer[100];
	int fwrite = open("pipe1", O_WRONLY);
	int fread = open("pipe2", O_RDONLY);
	printf("Terminal 1: Write a message to send to Terminal 2: ");
	fgets(buffer, 100, stdin);
	write(fwrite, buffer, sizeof(buffer));

	read(fread, buffer, sizeof(buffer));
	printf("Reply from Terminal 2: %s\n ", buffer);
	close(fread);
	close(fwrite);
	return 0;
}
