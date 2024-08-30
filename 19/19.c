/*
============================================================================
Name : 19.c
Author : Gutla Gayathri
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 30 Aug, 2024
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

// Function to read the time-stamp counter
unsigned long long rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;
    pid_t pid;

    // Get the time before the getpid call
    start = rdtsc();

    // Call getpid
    pid = getpid();

    // Get the time after the getpid call
    end = rdtsc();

    // Print the PID and the time taken
    printf("PID: %d\n", pid);
    printf("Time taken by getpid: %llu cycles\n", end - start);

    return 0;
}

/*
Output:

gayathri@alahomora:~/Desktop/SS/19$ cc 19.c
gayathri@alahomora:~/Desktop/SS/19$ ./a.out
PID: 174388
Time taken by getpid: 13086 cycles
*/

