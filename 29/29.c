/*
Name : 29.c
Author : Gutla Gayathri
Description : 29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/types.h>
#include <unistd.h>

void print_policy(int policy) {
    switch (policy) {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
            break;
    }
}

int main() {
    int current_policy, new_policy;
    struct sched_param param;

    // Get the current scheduling policy
    current_policy = sched_getscheduler(getpid());
    if (current_policy == -1) {
        perror("sched_getscheduler failed");
        return EXIT_FAILURE;
    }
    print_policy(current_policy);

    // Modify the scheduling policy to SCHED_FIFO
    new_policy = SCHED_FIFO;
    param.sched_priority = 10; // Set priority (must be within valid range)
    if (sched_setscheduler(getpid(), new_policy, &param) == -1) {
        perror("sched_setscheduler (SCHED_FIFO) failed");
        return EXIT_FAILURE;
    }
    printf("Changed scheduling policy to SCHED_FIFO\n");
    print_policy(sched_getscheduler(getpid())); // Verify the change

    // Modify the scheduling policy to SCHED_RR
    new_policy = SCHED_RR;
    param.sched_priority = 10; // Set priority (must be within valid range)
    if (sched_setscheduler(getpid(), new_policy, &param) == -1) {
        perror("sched_setscheduler (SCHED_RR) failed");
        return EXIT_FAILURE;
    }
    printf("Changed scheduling policy to SCHED_RR\n");
    print_policy(sched_getscheduler(getpid())); // Verify the change

    return EXIT_SUCCESS;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/29$ cc 29.c
gayathri@alahomora:~/Desktop/SS/29$ ./a.out
Current scheduling policy: SCHED_OTHER
sched_setscheduler (SCHED_FIFO) failed: Operation not permitted
gayathri@alahomora:~/Desktop/SS/29$ sudo ./a.out
[sudo] password for gayathri: 
Current scheduling policy: SCHED_OTHER
Changed scheduling policy to SCHED_FIFO
Current scheduling policy: SCHED_FIFO
Changed scheduling policy to SCHED_RR
Current scheduling policy: SCHED_RR

*/
