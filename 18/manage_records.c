/*
Name : 18.c
Author : Gutla Gayathri
Description : Write a program to perform Record locking.
b. Implement read lock
Date: 30 Aug, 2024
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE_PATH "records.txt"
#define RECORD_SIZE 50

void lock_record(int fd, off_t offset, short lock_type) {
    struct flock lock;
    lock.l_type = lock_type;  // Read or write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = RECORD_SIZE;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error locking file");
        exit(EXIT_FAILURE);
    }

    if (lock_type == F_RDLCK) {
        printf("Read lock acquired on record at offset %ld.\n", (long)offset);
    } else if (lock_type == F_WRLCK) {
        printf("Write lock acquired on record at offset %ld.\n", (long)offset);
    }
}

void unlock_record(int fd, off_t offset) {
    struct flock lock;
    lock.l_type = F_UNLCK;  // Unlock
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = RECORD_SIZE;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Error unlocking file");
        exit(EXIT_FAILURE);
    }

    printf("Lock released on record at offset %ld.\n", (long)offset);
}

void read_record(int record_index) {
    int fd;
    off_t offset;
    char buffer[RECORD_SIZE];

    if (record_index < 1 || record_index > 3) {
        fprintf(stderr, "Invalid record index.\n");
        exit(EXIT_FAILURE);
    }

    fd = open(FILE_PATH, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    offset = (record_index - 1) * RECORD_SIZE;

    // Acquire a read lock on the record
    lock_record(fd, offset, F_RDLCK);

    lseek(fd, offset, SEEK_SET);
    if (read(fd, buffer, RECORD_SIZE) != RECORD_SIZE) {
        perror("Error reading record");
        unlock_record(fd, offset);
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Read record %d: %s", record_index, buffer);

    // Release the read lock
    unlock_record(fd, offset);
    close(fd);
}

void modify_record(int record_index, const char *new_content) {
    int fd;
    off_t offset;
    char buffer[RECORD_SIZE];

    if (record_index < 1 || record_index > 3) {
        fprintf(stderr, "Invalid record index.\n");
        exit(EXIT_FAILURE);
    }

    fd = open(FILE_PATH, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    offset = (record_index - 1) * RECORD_SIZE;

    // Acquire a write lock on the record
    lock_record(fd, offset, F_WRLCK);

    lseek(fd, offset, SEEK_SET);
    if (read(fd, buffer, RECORD_SIZE) != RECORD_SIZE) {
        perror("Error reading record");
        unlock_record(fd, offset);
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Current content of record %d: %s", record_index, buffer);

    // Modify and write the record
    snprintf(buffer, RECORD_SIZE, "%s", new_content);
    lseek(fd, offset, SEEK_SET);
    if (write(fd, buffer, RECORD_SIZE) != RECORD_SIZE) {
        perror("Error writing record");
        unlock_record(fd, offset);
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Modified record %d: %s", record_index, buffer);

    // Release the write lock
    unlock_record(fd, offset);
    close(fd);
}

int main() {
    // Example usage: read record 1 and modify record 2
    read_record(1);
    modify_record(2, "Record 2: Updated content\n");
    return 0;
}
