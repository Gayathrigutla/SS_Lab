/*
Name : 26b.c
Author : Gutla Gayathri
Description : Write a program to execute an executable program.
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *program = "./a.out"; 
    char *arg1 = "User";      

    printf("Executing %s with argument %s\n", program, arg1);

    // Use execl to execute the program with arguments
    if (execl(program, program, arg1, (char *)NULL) == -1) {
        perror("execl failed");
        exit(EXIT_FAILURE);
    }

    // This line will not be executed if execl is successful
    printf("This won't be printed if execl succeeds.\n");

    return 0;
}
