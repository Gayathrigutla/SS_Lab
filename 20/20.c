/*
============================================================================
Name : 20.c
Author : Gutla Gayathri
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int priority;
    
    // Get the priority of the current process (PID)
    priority = getpriority(PRIO_PROCESS, getpid());

    if (priority == -1) {
        perror("Error getting priority");
        return EXIT_FAILURE;
    }

    printf("Current priority of the process: %d\n", priority);

    return EXIT_SUCCESS;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/20$ cc 20.c
gayathri@alahomora:~/Desktop/SS/20$ ./a.out
Current priority of the process: 0
gayathri@alahomora:~/Desktop/SS/20$ nice -n -10 ./a.out
nice: cannot set niceness: Permission denied
Current priority of the process: 0
gayathri@alahomora:~/Desktop/SS/20$ sudo nice -n -10 ./a.out
Current priority of the process: -10
*/
