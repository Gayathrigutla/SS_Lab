/*
Name : 28.c
Author : Gutla Gayathri
Description : Write a program to get maximum and minimum real time priority.
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main() {
    int min_priority, max_priority;

    // Get the minimum real-time priority
    min_priority = sched_get_priority_min(SCHED_FIFO);
    if (min_priority == -1) {
        perror("sched_get_priority_min failed");
        return EXIT_FAILURE;
    }

    // Get the maximum real-time priority
    max_priority = sched_get_priority_max(SCHED_FIFO);
    if (max_priority == -1) {
        perror("sched_get_priority_max failed");
        return EXIT_FAILURE;
    }

    // Print the results
    printf("Minimum real-time priority (SCHED_FIFO): %d\n", min_priority);
    printf("Maximum real-time priority (SCHED_FIFO): %d\n", max_priority);

    // Repeat for SCHED_RR
    min_priority = sched_get_priority_min(SCHED_RR);
    if (min_priority == -1) {
        perror("sched_get_priority_min (SCHED_RR) failed");
        return EXIT_FAILURE;
    }

    max_priority = sched_get_priority_max(SCHED_RR);
    if (max_priority == -1) {
        perror("sched_get_priority_max (SCHED_RR) failed");
        return EXIT_FAILURE;
    }

    // Print the results for SCHED_RR
    printf("Minimum real-time priority (SCHED_RR): %d\n", min_priority);
    printf("Maximum real-time priority (SCHED_RR): %d\n", max_priority);

    return EXIT_SUCCESS;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/28$ ./a.out
Minimum real-time priority (SCHED_FIFO): 1
Maximum real-time priority (SCHED_FIFO): 99
Minimum real-time priority (SCHED_RR): 1
Maximum real-time priority (SCHED_RR): 99

*/
