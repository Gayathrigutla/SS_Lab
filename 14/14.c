#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

// Function to print the type of file
void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(mode)) {
        printf("Symbolic link\n");
    } else if (S_ISCHR(mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(mode)) {
        printf("FIFO (named pipe)\n");
    } else if (S_ISSOCK(mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }
}

int main(int argc, char *argv[]) {
    struct stat file_stat;

    // Check if the correct number of arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get file path from command line argument
    char *file_path = argv[1];

    // Get file status
    if (stat(file_path, &file_stat) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    // Print the file type
    print_file_type(file_stat.st_mode);

    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/14$ ls
14.c  a.out  text.txt
gayathri@alahomora:~/Desktop/SS/14$ ./a.out text.txt 
Regular file
gayathri@alahomora:~/Desktop/SS/14$ ./a.out ~/Desktop/SS/14
Directory

*/
