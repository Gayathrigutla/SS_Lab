/*
Name : 18.c
Author : Gutla Gayathri
Description : Write a program to perform Record locking.                        
a. Implement write lock
Date: 30 Aug, 2024
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FILE_PATH "records.txt"
#define RECORD_SIZE 50

void create_records() {
    int fd;
    char records[3][RECORD_SIZE] = {
        "Record 1: Initial content\n",
        "Record 2: Initial content\n",
        "Record 3: Initial content\n"
    };

    // Open file for writing, create if not exist, truncate if exist
    fd = open(FILE_PATH, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write records to file
    for (int i = 0; i < 3; i++) {
        if (write(fd, records[i], RECORD_SIZE) != RECORD_SIZE) {
            perror("Error writing to file");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    printf("Records created successfully.\n");
    close(fd);
}

int main() {
    create_records();
    return 0;
}
