/*
============================================================================
Name : 5.c
Author : Gutla Gayathri
Description : 5. Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *files[5];
    char *filenames[5] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};

    // Create and open five files
    for (int i = 0; i < 5; i++) {
        files[i] = fopen(filenames[i], "w");
        if (files[i] == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
    }

    // Infinite loop to write to files
    while (1) {
        for (int i = 0; i < 5; i++) {
            fprintf(files[i], "Writing to %s\n", filenames[i]);
            fflush(files[i]); // Ensure data is written to file
        }
        sleep(1); // Slow down the loop a bit
    }

    // Close files (this part is never reached)
    for (int i = 0; i < 5; i++) {
        fclose(files[i]);
    }

    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/5$ ls -l /proc/163841/fd
total 0
lrwx------ 1 gayathri gayathri 64 Aug 30 22:06 0 -> /dev/pts/2
lrwx------ 1 gayathri gayathri 64 Aug 30 22:06 1 -> /dev/pts/2
lrwx------ 1 gayathri gayathri 64 Aug 30 22:06 2 -> /dev/pts/2
l-wx------ 1 gayathri gayathri 64 Aug 30 22:06 3 -> /home/gayathri/Desktop/SS/5/file1.txt
l-wx------ 1 gayathri gayathri 64 Aug 30 22:06 4 -> /home/gayathri/Desktop/SS/5/file2.txt
l-wx------ 1 gayathri gayathri 64 Aug 30 22:06 5 -> /home/gayathri/Desktop/SS/5/file3.txt
l-wx------ 1 gayathri gayathri 64 Aug 30 22:06 6 -> /home/gayathri/Desktop/SS/5/file4.txt
l-wx------ 1 gayathri gayathri 64 Aug 30 22:06 7 -> /home/gayathri/Desktop/SS/5/file5.txt
gayathri@alahomora:~/Desktop/SS/5$ 
*/
