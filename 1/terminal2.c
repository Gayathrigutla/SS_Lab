#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	int fread = open("pipe1", O_RDONLY);
	int fwrite = open("pipe2", O_WRONLY);
	char buffer[100];
	read(fread, buffer, sizeof(buffer));
	printf("Message received from Terminal 1:%s\n", buffer);
	printf("Response message to Terminal 1: ");
	fgets(buffer, 100, stdin);
	write(fwrite, buffer, sizeof(buffer));
	return 0;
}
