/*
============================================================================
Name : 15.c
Author : Gutla Gayathri
Description : Write a program to display the environmental variable of the user (use environ).
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ; // Declare the external variable

int main() {
    char **env;

    // Iterate through the environ array and print each environment variable
    for (env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}

/*
Output:


*/
